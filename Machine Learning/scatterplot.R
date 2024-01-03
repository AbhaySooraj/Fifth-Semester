library(ggplot2)
iris_df<-iris
ggplot(iris_df,aes(x=Petal.Length,y=Petal.Width))+
  geom_point(aes(color=Species,shape=Species,size=1))+
  labs(title="Scatter Plot of Petal Length")
