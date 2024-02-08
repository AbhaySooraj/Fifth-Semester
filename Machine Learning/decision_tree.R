library(rpart)
library(rpart.plot)

titanic <- read.csv("C:\\Users\\abhay\\Desktop\\Main\\RAJAGIRI\\S5\\ML\\titanic.csv")

titanic<-titanic[,c("Pclass","Sex","Age","SibSp","Parch","Fare","Survived")]
titanic<-na.omit(titanic)

titanic$Sex <- as.factor(titanic$Sex)

tree_model <- rpart(Survived ~ ., data = titanic, method = "class")
print(tree_model)
prp(tree_model)

prediction<-predict(tree_model,newdata = titanic, type="class")
titanic$Survived<-as.factor(titanic$Survived)

confusionMatrix(prediction, titanic$Survived)
