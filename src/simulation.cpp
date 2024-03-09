#include <iostream>

#include "classes/particle.h"

int main()
{
    Particle p{};
    std::cout << p.log() << std::endl;

    return 0;
}
