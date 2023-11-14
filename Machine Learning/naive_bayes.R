library(mlbench)
library(caret)
library(e1071)


soybean_df <- read.csv("C:\\Users\\abhay\\Desktop\\Main\\RAJAGIRI\\S5\\ML\\Soybean.csv")

soybean <- na.omit(soybean_df)

#normalization or scaling
preproc <- preProcess(soybean[, -1], method = c("center", "scale"))
soybean[, -1] <- predict(preproc, soybean[, -1])
set.seed(123)  # For reproducibility

#split 80% to training and 20% to test data
splitIndex <- createDataPartition(soybean$Class, p = 0.8, list = FALSE)
training_data <- soybean[splitIndex, ]
training_data
testing_data <- soybean[-splitIndex, ]
testing_data


# Train the Naive Bayes classifier
nb_model <- naiveBayes(Class ~ ., data = training_data)
nb_model
# Make predictions on the testing data
predictions <- predict(nb_model, newdata = testing_data)
predictions
# Create a confusion matrix
predictions <- as.factor(predictions)
testing_data$Class<-as.factor(testing_data$Class)

confusion_matrix <- confusionMatrix(predictions, testing_data$Class)
# View the confusion matrix and associated metrics
print(confusion_matrix)
