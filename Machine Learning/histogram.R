library(ggplot2)

titanic_df <- read.csv("C:\\Users\\abhay\\Desktop\\Main\\RAJAGIRI\\S5\\ML\\titanic.csv")

ggplot(titanic_df, aes(x = Age)) +
  geom_histogram(binwidth = 5, fill = "black", color = "white") +
  labs(
    title = "Passenger Age Distribution on the Titanic",
    x = "Age",
    y = "Count"
  ) 
