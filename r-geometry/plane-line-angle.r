#!/usr/bin/env Rscript

# assume data is in form (e1, e2, e3, l1, l2) where all are points in R^3
data = as.matrix(read.csv(file="points.csv", header=FALSE, sep=","))

for (i in length(data[,1])) {
    line = data[i,];

    # get 2 plane vectors and calculate their normal (cross product)    
    e1 = line[1:3] - line[7:9];
    e2 = line[4:6] - line[7:9];
    n = e1 %*% e2

    # get the line vector
    l = line[10:12] - line[13:15];

    # calculate the angle between the normal vector and the line vector
    # sum(a*b) = dot product, sqrt(sum(a*a)) = norm
    angle = asin(abs(sum(n*l)) / (sqrt(sum(n*n)) * sqrt(sum(l*l))));
    print(angle/pi*90);
}
