// [[Rcpp::plugins(cpp11)]]
#include <string>
#include <random>
#include <Rcpp.h>

#include "MathFunctions/RandomGenerator.h"

#include "Cohort.h"


Cohort::Cohort(int count)
    : count(count) { }

int Cohort::getCount() const
{
    return count;
}

void Cohort::setCount(int count_)
{
    count = count_;
}

int Cohort::drawFraction(const float fraction_)
{
    std::binomial_distribution<int> distribution(getCount(), fraction_);
    return distribution(RandomGenerator::instance()->generator);
}

void Cohort::print() {
    Rcpp::Rcout << "<emod.Cohort with count of " << count << ">" << std::endl;
}

RCPP_MODULE(cohort) {
    Rcpp::class_<Cohort>("Cohort")
        .constructor<int>("")
        .property("count", &Cohort::getCount, &Cohort::setCount, "Count property of the Cohort")
        .method("drawFraction", &Cohort::drawFraction, "Draw a random binomial fraction of the Cohort's count")
        .method("print", &Cohort::print, "Print the state of the Cohort")
        ;
}