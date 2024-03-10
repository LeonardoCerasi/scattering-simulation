#include <iostream>
#include <stdexcept>

#include "classes/particle.h"

int main()
{
    try
    {
        std::vector<Particle> ensemble{sys_init("test/particles.in")};
        std::cout << sys_log(ensemble) << std::endl;
    }
    catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

    return 0;
}
