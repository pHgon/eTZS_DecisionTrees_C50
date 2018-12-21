library(C50)
library(gmodels)

pret <- read.csv("/home/paulohenrik/GIT-repository/eTZS_DecisionTrees_C50/datasets_1/pred.csv")
pret$BestPred <- factor (pret$BestPred, levels = c("0", "1"), labels = c("no", "yes"))

set.seed(123)


sink("/home/paulohenrik/GIT-repository/eTZS_DecisionTrees_C50/pret.txt")
matrix_dimensions <- list(c("no", "yes"), c("no", "yes"))
names(matrix_dimensions) <- c("predicted", "actual")
error_cost <- matrix(c(0, 0, 5, 0), nrow = 2, dimnames = matrix_dimensions)
pret_error <- C5.0(pret[c(-6, seq(-9, -12), -14, -15, -17, -18, seq(-20, -23))], pret$BestPred, costs = error_cost, control = C5.0Control(winnow = TRUE, minCases = 4500))
summary(pret_error)
sink()

#pret_error <- C5.0(pret[-6], pret$bestMode_pred, costs = error_cost, control = C5.0Control(winnow = TRUE, minCases = 4000))

#pret_sample <- sample(1:600000, 540000)
#pret_train <- pret[pret_sample, ]
#pret_test <- pret[-pret_sample, ]

#prop.table(table(pret_train$bestMode_pred))
#prop.table(table(pret_test$bestMode_pred))

#pret_model <- C5.0(pret_train[-6], pret_train$bestMode_pred)

#pret_pred <- predict(pret_model, pret_test)
#CrossTable(pret_test$bestMode_pred, pret_pred, prop.chisq = FALSE, prop.c = FALSE, prop.r = FALSE,dnn = c('actual default', 'predicted default'))


