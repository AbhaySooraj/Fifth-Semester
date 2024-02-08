library(ipred)
library(caret)

set.seed(123)

bagged_model<- bagging(Species ~ ., data = iris, nbagg=50)

predictions<-predict(bagged_model,iris)

iris$Species<-as.factor(iris$Species)
predictions<-as.factor(predictions)

confusionMatrix(predictions,iris$Species)
