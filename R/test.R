library(here)
library(Rcpp)

sourceCpp(here("src", "Cohort.cpp"))

c1 = new(Cohort, 10)

c1$count = c1$count + 10

c1$print()

x = c()
for (i in 1:1000)
{
  x[i] = c1$drawFraction(0.2)
}

hist(x)

