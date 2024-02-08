library(caret)

soybean_df <- read.csv("C:\\Users\\abhay\\Desktop\\Main\\RAJAGIRI\\S5\\ML\\Soybean.csv")

soybean <- na.omit(soybean_df)

preproc <- preProcess(soybean[, -1], method = c("center", "scale"))
soybean[, -1] <- predict(preproc, soybean[, -1])
set.seed(123) 

splitIndex <- createDataPartition(soybean$Class, p = 0.8, list = FALSE)
training_data <- soybean[splitIndex, ]
training_data
testing_data <- soybean[-splitIndex, ]
testing_data
