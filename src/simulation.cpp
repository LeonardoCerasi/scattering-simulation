#include <iostream>
#include <stdexcept>

#include "classes/particle.h"
#include "classes/framework.h"

int main()
{
    try
    {
        std::vector<Particle> ensemble{sys_init("test/particles.in")};
        std::cout << sys_log(ensemble) << std::endl;

        Framework frame{frame_init("test/framework.in")};
        std::cout << frame.log() << std::endl;
    }
    catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

    return 0;
}
