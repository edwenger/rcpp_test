class Cohort {

public:
    Cohort(int count);
    int getCount() const;
    void setCount(int count_);
    int drawFraction(const float fraction_);
    void print();

private:
    int count;
};