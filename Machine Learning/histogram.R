setwd(file.path("C:\\Users\\student\\Desktop\\abhay\\Exp3"))
# Load the necessary packages
library(ggplot2)



# Convert the dataset to a data frame
titanic_df <- read.csv("titanic.csv")

# Create a histogram of passenger ages
ggplot(titanic_df, aes(x = Age)) +
  geom_histogram(binwidth = 5, fill = "black", color = "white") +
  labs(
    title = "Passenger Age Distribution on the Titanic",
    x = "Age",
    y = "Count"
  ) +
  
