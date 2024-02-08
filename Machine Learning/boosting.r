library(gbm)
library(caret)

iris$Species<-as.numeric(factor(iris$Species))

set.seed(123)

bm<-gbm(Species ~.,data=iris,distribution="multinomial",n.trees=100,interaction.depth=3,shrinkage=0.1)

predictions<-predict(bm,newdata=iris,n.trees=100,type="response")

cm<-table(iris$Species,pl)
cm
