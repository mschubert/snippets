# =============================================================================
# >> R script for analysing the AML microarray dataset of Ross et. al (2002) <<
# >> Genomics Module Assignment, Cranfield University
# >> Michael Schubert, 11/28/2010

# =============================================================================
# >> Read the training set and filter raw signal to expression values <<
#

# load libraries
library(affy)
library(affyPLM)
library(genefilter)

# load Affymetrix CEL files that are in train_set.txt
Affy.Expt = read.AnnotatedDataFrame("train_set.txt", header=TRUE, row.names=1, sep="\t")
Affy.Data = ReadAffy(filenames=rownames(pData(Affy.Expt)), phenoData=Affy.Expt, verbose=TRUE)

# perform threestep filtering (background correction, normalisation and summarisation)
my.tstep = threestep(Affy.Data, background.method="RMA.2", normalize.method="quantile", summary.method="median.polish")

# save the labels, types, and numerical expression of labels in variables to use later
my.labels = as.vector(my.tstep$Sample.type)
my.types = unique(my.labels)
my.classes = array(0, length(my.labels))
for(i in c(1:length(my.types))) my.classes[my.labels==my.types[i]] = i

# =============================================================================
# >> Filter expression values from tstep <<
#

## prefilter data; this step was no used in the analysis
#variationFilter = function(ratio=1, distance=0, thresh=0, na.rm=TRUE) {
#	function(x) {
#		minval = min(x, na.rm=na.rm)
#		maxval = max(x, na.rm=na.rm)
#		(maxval/minval > ratio) && (maxval-minval > distance) && (maxval > thresh)
#	}
#}
#my.filter = genefilter(my.tstep, filterfun(variationFilter(thresh=log2(100))))

# this filtering step was done so the laptop could handle the data (not enough RAM)
my.filter = genefilter(my.tstep, filterfun(kOverA(6, log2(150))))
my.exprs = t(exprs(my.tstep[my.filter]))

# =============================================================================
# >> Exploratory analysis: principle component analysis <<
#

# use a singular value decomposition of the covariance matrix; this takes a lot of memory
my.svd = svd(cov(my.exprs))
my.iloads = solve(t(my.svd$v))

# calculate the weights
my.weights = my.svd$d

# calculate the scores matrix using the inverse loads
my.scores = my.exprs %*% my.iloads

# set up plot parameters like title and axis labels
my.title = paste("PCA of different leukemia types, capturing\n", round(100*sum(my.weights[1:2])/sum(my.weights), digits=1), "% of variance")
my.pc1 = paste("PC1 (", round(100*my.weights[1]/sum(my.weights), 1), "%)")
my.pc2 = paste("PC2 (", round(100*my.weights[2]/sum(my.weights), 1), "%)")

# plot the image and save to file
tiff(filename="PCA_allExprs.tif")
plot(my.scores[,1], my.scores[,2], main=my.title, xlab=my.pc1, ylab=my.pc2, pch=my.classes, col=my.classes)
legend(x="bottomright", legend=my.types, col=c(1:length(my.types)), pch=c(1:length(my.types)))
dev.off()

# =============================================================================
# >> Exploratory analysis: linear discriminant analysis <<
#

# the MASS library is needed for this
library(MASS)

# lda needs a dataframe and a factor matrix for the sample labels
my.frame = data.frame(my.exprs, Sp=my.labels)
my.lda = lda(Sp ~ ., my.frame)

# predict data on the same set it was created on; my.vec is similar to PC vectors
my.vec = predict(my.lda, my.frame)$x

# plot the image and save to file
tiff(filename="LDA_allExprs.tif")
plot(my.vec[,1], my.vec[,2], pch=my.classes, col=my.classes, main="Linear Discriminant Analysis", xlab="LD1", ylab="LD2")
legend(x="topright", legend=my.types, col=c(1:length(my.types)), pch=c(1:length(my.types)))
dev.off()

# =============================================================================
# >> Do statistical testing using eBayes <<
#

# load statistical libraries
library(limma)
library(multtest)
library(e1071)

# create a zero-matrix with 1s at sample type positions
my.design = model.matrix(~ 0+factor(my.classes))

# name the samples A-E so contrasts can be built
colnames(my.design) = c("A","B","C","D","E")

# initialize the discriminant genes and top-discr. genes as empty variables so we can add later
my.discriminants = NULL
my.topgenes = NULL

# fit a linear model to data
fit.1 = lmFit(my.tstep, my.design)

# get significant differences of each combination of 2 sample types
for (con in c("A-B", "A-C", "A-D", "A-E", "B-C", "B-D", "B-E", "C-D", "C-E", "D-E")) {
        # make a contrast matrix for each combination of sample types
        contrast.matrix = makeContrasts(con, levels=my.design)
        fit.2 = contrasts.fit(fit.1, contrast.matrix)
        fit.3 = eBayes(fit.2)
        # adjust p-values for multiple testing (Benjamini-Hochberg)
        multadjust = mt.rawp2adjp(fit.3$p.value, proc=c("BH"))
        # get all genes with adjusted p<0.01
        my.index = multadjust$index[multadjust$adjp[,2]<1e-2]
        # print number of significant results for each combination
        print(paste(con, ":", length(my.index), "genes w/ significant difference"))
        # add current result to discriminants (all significant) and topgenes (top 10)
        my.discriminants = c(my.discriminants, my.index)
        my.topgenes = c(my.topgenes, multadjust$index[1:10])
}

# get a set of all significant genes, ignore duplicates
my.subset = my.tstep[unique(my.discriminants)]
my.exprs = t(exprs(my.subset))

# do the same thing for the top genes
my.topgenes = unique(my.topgenes)
my.topset = my.tstep[my.topgenes]
my.topexprs = t(exprs(my.topset))

# =============================================================================
# >> Save annotations <<
#

# load annotation libraries
library(annaffy)
library(hgu133a.db)

# define which annotations we want
annot.columns = aaf.handler()[c(1:5,7,10,12)]

# create a table and save to HTML; use my.topexprs for top 43
anntable = aafTableAnn(colnames(my.topexprs), "hgu133a.db", annot.columns)
saveHTML(anntable,"top-discriminants.html", title="Class-discriminant genes")

# also save a table for all significant genes
anntable = aafTableAnn(colnames(my.exprs), "hgu133a.db", annot.columns)
saveHTML(anntable,"discriminants.html", title="Class-discriminant genes")

# =============================================================================
# >> Plot a hierachically clustered heatmap of the top-discriminating genes found <<
#

# define the distance and clustering functions
my.dist = function(x) dist(x, method="euclidean")
my.hclust = function(d) hclust(d, method="ward")

# plot the heatmap and save to file
tiff(filename="heatmap.tif")
heatmap(my.topexprs, distfun=my.dist, hclustfun=my.hclust, labRow=my.labels, main="Heatmap of 62 samples vs 43 class-discriminant genes")
dev.off()

# =============================================================================
# >> Do SVM training and classification <<
#

# read the test set, do threestep filtering, save expression data of my.topgenes under my.textexprs
Test.Expt = read.AnnotatedDataFrame("test_set.txt", header=TRUE, row.names=1, sep="\t")
Test.Data = ReadAffy(filenames=rownames(pData(Test.Expt)), phenoData=Test.Expt, verbose=TRUE)
my.tstep2 = threestep(Test.Data, background.method="RMA.2", normalize.method="quantile", summary.method="median.polish")
my.testexprs = t(exprs(my.tstep2[my.topgenes]))

# read the other set, do threestep filtering, save expression data of my.topgenes under my.otherexprs
Other.Expt = read.AnnotatedDataFrame("other_set.txt", header=TRUE, row.names=1, sep="\t")
Other.Data = ReadAffy(filenames=rownames(pData(Other.Expt)), phenoData=Other.Expt, verbose=TRUE)
my.tstep3 = threestep(Other.Data, background.method="RMA.2", normalize.method="quantile", summary.method="median.polish")
my.otherexprs = t(exprs(my.tstep3[my.topgenes]))

# train SVM on training set
my.svm = svm(my.topexprs, my.labels, type="C-classification", kernel="linear")

# predict the training set, the test set, and the other set (only adult samples) with the model
my.trainpred = predict(my.svm, my.topexprs)
my.testpred = predict(my.svm, my.testexprs)
my.testpred = predict(my.svm, my.otherexprs)

# print summary of classification results
print("SVM classification on training set:")
print(paste(my.trainpred, my.trainpred == my.labels))
print("SVM classification on test set:")
print(paste(my.testpred, my.testpred == my.tstep2$Sample.type))
