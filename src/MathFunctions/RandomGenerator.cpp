#include "RandomGenerator.h"

RandomGenerator *RandomGenerator::s_instance = 0;

RandomGenerator::RandomGenerator() { }

void RandomGenerator::set_seed(int seed_)
{
    generator.seed(seed_);
}
