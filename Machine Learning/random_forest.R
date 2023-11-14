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


# Train a Random Forest classifier
model <- train(Class ~ ., data = training_data, method = "rf")
model
# Make predictions on the testing data
predictions <- predict(model, newdata = testing_data)
predictions
predictions <- as.factor(predictions)
testing_data$Class<-as.factor(testing_data$Class)

# Evaluate the model's performance
confusionMatrix(predictions, testing_data$Class)
