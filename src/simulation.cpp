#include <iostream>
#include <stdexcept>

#include "classes/particle.h"
#include "classes/framework.h"
#include "interactions/constraints.h"

int main()
{
    try
    {
        Particle p{1, {0, 0, 0, 2, 2, 2, 0, 0, 0}};
        Framework frame{{0, 0, 0}, {10, 10, 10}};

        for (double t{}; t <= 25; t += h)
        {
            std::cout << "t: " << t << std::endl;
            std::cout << p.log() << "\n\n" << std::endl;
            p.motion(t, h);
            constraints(frame, p);
        }
    }
    catch(const std::exception& e) { std::cerr << e.what() << std::endl; }

    return 0;
}
