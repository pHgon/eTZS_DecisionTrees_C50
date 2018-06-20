library(C50)
library(gmodels)

first <- read.csv("/home/paulohenrik/Documentos/DecisionTrees/datasets/first.csv")
first$BestFirst <- factor (first$BestFirst, levels = c("0", "1"), labels = c("no", "yes"))

set.seed(123)


sink("/home/paulohenrik/Documentos/DecisionTrees/log.txt")
matrix_dimensions <- list(c("no", "yes"), c("no", "yes"))
names(matrix_dimensions) <- c("predicted", "actual")
error_cost <- matrix(c(0, 5, 0, 0), nrow = 2, dimnames = matrix_dimensions)
first_error <- C5.0(first[c(-11, -12, -15, -18, -21, -23)], first$BestFirst, costs = error_cost, control = C5.0Control(winnow = FALSE, minCases = 4000))
summary(first_error)
sink()