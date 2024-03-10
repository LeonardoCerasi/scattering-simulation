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
        std::cout << frame.log() << "\n\n" << std::endl;

        Particle p{1, {0, 0, 0, 0, 0, 0, 2, 2, 2}};
        for (int t{}; t <= 10; t++)
        {
            std::cout << "t: " << t << std::endl;
            std::cout << p.log() << "\n\n" << std::endl;
            p.motion(t, 1);
        }
    }
    catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

    return 0;
}
