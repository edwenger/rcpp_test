#include <random>

class RandomGenerator
{
protected:
    static RandomGenerator *s_instance;

    RandomGenerator();

public:

    void set_seed(int seed_);
    static RandomGenerator *instance()
    {
        if (!s_instance)
            s_instance = new RandomGenerator;
        return s_instance;
    }

    std::default_random_engine generator;
};
