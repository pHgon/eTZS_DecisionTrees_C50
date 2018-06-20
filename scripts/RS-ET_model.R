library(C50)
library(gmodels)

raster <- read.csv("/home/paulohenrik/Documentos/DecisionTrees/datasets/raster.csv")
raster$BestRaster <- factor (raster$BestRaster, levels = c("0", "1"), labels = c("no", "yes"))

set.seed(123)


sink("/home/paulohenrik/Documentos/DecisionTrees/log.txt")
matrix_dimensions <- list(c("no", "yes"), c("no", "yes"))
names(matrix_dimensions) <- c("predicted", "actual")
error_cost <- matrix(c(0, 0, 0, 0), nrow = 2, dimnames = matrix_dimensions)
raster_error <- C5.0(raster[-23], raster$BestRaster, costs = error_cost, control = C5.0Control(winnow = FALSE, minCases = 1000))
summary(raster_error)
sink()
