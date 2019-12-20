A test project using Rcpp on EMOD-relevant objects

```
> setwd("path/to/repository")
> library(Rcpp)
> sourceCpp("src/Cohort.cpp")
> c1 = new(Cohort, 10)
> c1$count = c1$count + 10
> c1$print()
> c1$drawFraction(0.2)
```