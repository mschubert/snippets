#!/usr/bin/Rscript

# =============================================================================
# >> R script for analysing the Transitional Cell Carcinoma (TCC) GC-MS data <<
# >> Proteomics Module Assignment, Cranfield University
# >> Michael Schubert, 12/19/2010


# =============================================================================
# >> 0.) Clear workspace and any open figures, load required libraries <<
# 
rm(list=ls())
graphics.off()

require(R.matlab)
require(matlab)
require(plsgenomics)
require(scatterplot3d)

source("biplot3d2.r")
source("DoLOOCV2.r")

# =============================================================================
# >> 1.1) Clear workspace and any open figures <<
#
DATA = readMat("GCMS_P4D.mat")
XTIC = DATA$Xtic		# data
RT = DATA$SCANS			# retention time
SAM = as.character(DATA$SAM)	# labels
CLASSES = as.numeric(factor(substr(SAM, 0,2)))
TYPES = c("Healthy Control", "Unhealthy Control", "TCC Patients")
POSITIVE_CLASS = 3

# =============================================================================
# >> 1.2) Prompt the user for comparative visualisation plots, 3 chromatograms each <<
#
visualise = function() {
    while (TRUE) {
        cmp = NULL
        # read in 3 chromatogram indices to plot and compare
        for (i in c(1:3)) {
            n = readline(paste("Chromatogram", i, "to compare (0 to exit): "))
            if (!(n>0 && n<length(SAM))) {
                return("Visualisation aborted")
            }
            cmp = c(cmp, as.numeric(n))
        }
        # read to filename to save plot to
        fname = readline("Filename to save image to: ")

        # save the plot
        tiff(filename=fname)
        par(mfcol=c(3,1))
        for (i in cmp) {
            title = paste("TIC for Sample:", SAM[i])
            plot(RT, XTIC[i,], type="l", main=title, ylab="Intesity", xlab="Retention time [s]")
        }
        dev.off()
    }
}
print("TIC comparison, possible indices:")
print(SAM)
visualise()

# =============================================================================
# >> 2a.) Do PCA analysis and do plot with PC weights <<
#
PCA = prcomp(XTIC)

# get the PC weights and construct labels from them
eigen = PCA$sdev^2
pc1lab = paste("PC1 (", round(eigen[1] / sum(eigen) * 100, 2), "%)", sep="")
pc2lab = paste("PC2 (", round(eigen[2] / sum(eigen) * 100, 2), "%)", sep="")

# save figure
tiff(filename="PCA.tif")
plot(PCA$x, col=CLASSES, pch=CLASSES, xlab=pc1lab, ylab=pc2lab, main="PCA plot")
legend(x="topright", legend=TYPES, col=c(1:length(TYPES)), pch=c(1:length(TYPES)))
text(PCA$x, SAM, cex=0.5)
dev.off()

# =============================================================================
# >> 2b.) Draw a 3D score plot to identify any outliers <<
#
biplot3d2(XTIC, SAM, RT, 1, 2, 3, -1, 0)

# =============================================================================
# >> 3.) Construction of Classification Vectors <<
#
#  The following vectors should be constructed: C1 vs TCC, C2 vs TCC and C(1+2)
#  vs TCC. The way this was proposed in the assignment sheet is highly inefficient
#  and leads to code that is hard to maintain. Instead, two filters are created,
#  where each row serves as a view (i.e., lists the TIC indices that should be
#  used for analysis) for a certain test case. This in combination with the first
#  3 lines of the nested for loops is fully equivalent and more efficient to what
#  was asked

# the first filter has TRUE on all positive samples and FALSE otherwise
PositiveClassFilter = (CLASSES==POSITIVE_CLASS)
# the training filter has 3 rows, each representing a test case; TRUE if the sample
# belongs to the test case, FALSE otherwise
XtrainFilter = rbind(CLASSES!=2, CLASSES!=1, TRUE)

# =============================================================================
# >> 4+5.) Leave one out Cross Validation + Specificity/Sensitivity <<
#

# define different runs and scaling methods, and initialise an empty result table
RUN = c("C1 vs TCC", "C2 vs TCC", "C1+2 vs TCC")
SCALING = c("None", "Mean-Centre", "Auto-Scale", "Range[0,1]", "Range[-1,1]", "Normalise")
RESULT = NULL

# do cross-validation for each run and each scaling method
for (run in 1:length(RUN)) {
    for (sc in 1:length(SCALING)) {
        # use the filters created in point 3 to extract the right samples for each
        # run, as well as their labels
        Xtrain = XTIC[XtrainFilter[run,],]
        Ctrain = PositiveClassFilter[XtrainFilter[run,]] + 1
        SAMtrain = SAM[XtrainFilter[run,]]

        # do leave-one-out cross validation using the script provided by Michael
        # Cauchy, and take the mean of the overall classification score of the run
        cur = DoLOOCV2(Xtrain, Ctrain, sc-1, 1, 20)
        overall = round(mean(cur$Overall), 2)
        lv = cur$OptLVs[1]

        # for the optimal LV, perform PLS-DA again using the same scaling method
        # and try to predict class labels for the whole set with built-in cross
        # valiation (this is not leave-one-out and might produce slight differences)
        Xscaled = pretreat1(Xtrain, sc-1)
        plsda = pls.lda(Xscaled$SCALED, Ctrain, Xtest=NULL, lv, nruncv=20)
        pred = plsda$predclass

        # calculate true/false positives/negatives from Ctrain (=correct labels) and
        # pred (=assigned labels)
        TP = sum(pred[which(Ctrain==2)]==2) / sum(pred==2)
        TN = sum(pred[which(Ctrain==1)]==1) / sum(pred==1)
        FP = sum(pred[which(Ctrain==1)]==2) / sum(pred==2)
        FN = sum(pred[which(Ctrain==2)]==1) / sum(pred==1)

        # calculate specificity and sensitivity from TFPN
        spec = round(100 * TN/(TN+FP), 2)
        sens = round(100 * TP/(TP+FN), 2)

        # add the result of the current run to our result matrix
        RESULT = rbind(RESULT, c(RUN[run], lv, SCALING[sc], overall, spec, sens))
    }
}

# use descriptive column names for the result table and print a summary of each
# run to the user; the top runs are easy to find in this table
colnames(RESULT) = c("Protocol", "LV", "Scaling", "% Overall", "% Specificity", "% Sensitivity")
print(as.table(RESULT))
