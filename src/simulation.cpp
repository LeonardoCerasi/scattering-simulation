#include <iostream>

#include "Config.h"

#include "tools/input.h"
#include "classes/particle.h"

int main()
{
    std::cout << "Version " << Scattering_VERSION_MAJOR << "." << Scattering_VERSION_MINOR << std::endl;

    std::cout << "Linee: " << lines("src/classes/particle.cpp") << std::endl;

    Particle part = Particle();

    std::cout << "Mass: " << part.get_mass() << std::endl;

    return 0;
}
