#include <iostream>

#include "Config.h"

#include "tools/input.h"
#include "classes/particle.h"
#include "classes/framework.h"
#include "functions/scattering.h"

/**
 * @brief This function initiates an ensemble of Particles and a Framework, simulates their motion and interactions and outputs the data generated on an output file
 *
 * @param path_output Path of the output file
 * @param path_framework Path of the framework input file
 * @param path_particles Path of the Particles input file
 */
void simulation(const char *path_output, const char *path_framework, const char *path_particles)
{
    // create output file
    std::ofstream output;
    output.open(path_output);

    // framework
    Framework framework = init_framework(path_framework);

    // particles
    std::vector<Particle> particles = init_particles(path_particles);

    // time accuracy
    double delta_t = time_accuracy(output);

    // duration
    double t_final = duration(output);

    // initialize scattering counter
    int scattering = 0;

    // flow of time
    for (double t = delta_t; t <= t_final; t += delta_t)
    {
        // output current time on log file
        output << "t = " << t << std::endl
               << std::endl;

        // motion of the framework
        framework.framework_motion(t);

        // cycle over partciles
        for (int i = 0; i < particles.size(); i++)
        {
            // motion of the particle
            particles[i].motion(delta_t);

            // verify constraints
            framework.constraints(particles[i], t);
        }

        // scattering of particles
        scattering += particles_scattering(particles, delta_t, output);

        // output current state of the system
        framework.framework_log(output);
        system_log(output, particles);
    }

    // log of scattering
    std::cout << "\nDuring the simulation " << scattering << " scattering(s) occurred" << std::endl;

    // output scattering count on log file
    output << "\nDuring the simulation " << scattering << " scattering(s) occurred" << std::endl;

    // close output file
    output.close();
}

int main()
{
    std::cout << "Version " << Simulation_VERSION_MAJOR << "." << Simulation_VERSION_MINOR << std::endl;

    simulation("log.log", "test/framework.in", "test/particles.in");

    return 0;
}
