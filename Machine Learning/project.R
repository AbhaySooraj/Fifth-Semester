install.packages("dplyr")
install.packages("ggplot2")

library(dplyr)
library(ggplot2)
library(outliers)

online <-read.csv("C:\\Users\\student\\Desktop\\abhay\\online.csv")

online <- na.omit(online)
online

#create new column Amount
online$Amount <- online$Quantity * online$UnitPrice
# Group by CustomerID and sum the Amount
rfm_m <- aggregate(Amount ~ CustomerID, data = online, sum)

# Group by CustomerID and count the number of unique InvoiceNo
rfm_f <- online %>%
  group_by(CustomerID) %>%
  summarize(Frequency = n_distinct(InvoiceNo))

# Rename the columns
names(rfm_f) <- c('CustomerID', 'Frequency')

# Assuming 'rfm_m' and 'rfm_f' are your data frames
rfm <- merge(rfm_m, rfm_f, by = 'CustomerID', all = FALSE)

online$InvoiceDate <- as.POSIXct(online$InvoiceDate, format='%d-%m-%Y %H:%M')
max_date <- max(online$InvoiceDate)
print(max_date)
# Compute the difference between max date and transaction date
online$Diff <- as.numeric(difftime(max_date, online$InvoiceDate, units = "days"))

# Compute last transaction date to get the recency of customers
rfm_p <- aggregate(Diff ~ CustomerID, data = online, FUN = min)
rfm_p$Diff <- as.integer(rfm_p$Diff)

# Merge Assuming 'rfm', 'rfm_p' are your data frames
rfm <- merge(rfm, rfm_p, by = 'CustomerID', all = FALSE)

# Rename the columns
names(rfm) <- c('CustomerID', 'Amount', 'Frequency', 'Recency')



# Assuming 'rfm' is your data frame
rfm_df <- rfm[, c('Amount', 'Frequency', 'Recency')]

# Standardize the attributes
rfm_df_scaled <- scale(rfm_df)

# Assuming 'rfm_df_scaled' is your scaled data frame
rfm_df_scaled <- as.data.frame(rfm_df_scaled)


# Rename the columns
names(rfm_df_scaled) <- c('Amount', 'Frequency', 'Recency')

# Set seed for reproducibility
set.seed(123)

# Perform k-means clustering
kmeans_model <- kmeans(rfm_df_scaled, centers = 3, nstart = 50)

# Display the k-means model
print(kmeans_model)

# Assuming 'rfm' is your data frame and 'kmeans_model' is your k-means model

# Assign cluster labels
rfm$Cluster_Id <- kmeans_model$cluster

# Box plot to visualize Cluster Id vs Amount
ggplot(rfm, aes(x = as.factor(Cluster_Id), y = Amount)) +
  geom_boxplot() +
  labs(x = "Cluster Id", y = "Amount") +
  ggtitle("Box plot of Cluster Id vs Amount")

# Box plot to visualize Cluster Id vs Frequency
ggplot(rfm, aes(x = as.factor(Cluster_Id), y = Frequency)) +
  geom_boxplot() +
  labs(x = "Cluster Id", y = "Frequency") +
  ggtitle("Box plot of Cluster Id vs Frequency")

# Box plot to visualize Cluster Id vs Recency
ggplot(rfm, aes(x = as.factor(Cluster_Id), y = Recency)) +
  geom_boxplot() +
  labs(x = "Cluster Id", y = "Recency") +
  ggtitle("Box plot of Cluster Id vs Recency")

