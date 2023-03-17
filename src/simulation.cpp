#include <iostream>

#include "Config.h"

#include "tools/input.h"
#include "classes/particle.h"
#include "classes/framework.h"

int main()
{
    std::cout << "Version " << Scattering_VERSION_MAJOR << "." << Scattering_VERSION_MINOR << std::endl;

    std::cout << "Linee: " << lines("src/classes/particle.cpp") << std::endl;

    Particle part = Particle();

    std::cout << "Mass: " << part.get_mass() << std::endl;

    Framework fram = Framework();

    std::cout << "Min x: " << fram.get_minimum(0) << std::endl;

    return 0;
}
