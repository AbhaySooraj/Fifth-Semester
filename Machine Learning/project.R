install.packages("dplyr")
install.packages("ggplot2")

library(dplyr)
library(ggplot2)



online <-read.csv("C:\\Users\\student\\Desktop\\abhay\\online.csv")

missing_values <- colSums(is.na(online))
missing_values

online <- na.omit(online)
online


# Select relevant columns for clustering
data_for_clustering <- online[, c("Recency", "Frequency", "Monetary")]

# Standardize the data (optional but often recommended for k-means)
scaled_data <- scale(data_for_clustering)

# Determine the optimal number of clusters (K) using the elbow method
wss <- numeric(10)
for (i in 1:10) {
  kmeans_model <- kmeans(scaled_data, centers = i, nstart = 10)
  wss[i] <- sum(kmeans_model$withinss)
}

# Plot the elbow method to identify the optimal K
plot(1:10, wss, type = "b", pch = 19, frame = FALSE, xlab = "Number of Clusters (K)", ylab = "Within Sum of Squares (WSS)")
