#include <iostream>

#include "Config.h"

#include "input.h"

int main()
{
    std::cout << "Version " << Scattering_VERSION_MAJOR << "." << Scattering_VERSION_MINOR << std::endl;

    std::cout << "Linee: " << lines("src/simulation.cpp") << std::endl;

    return 0;
}
