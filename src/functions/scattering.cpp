#include "functions/scattering.h"

bool scatter(int coordinate, double delta_t, Particle particle1, Particle particle2)
{
    // check if the particles would go past each other
    return (((particle1.get_position(coordinate) < particle2.get_position(coordinate)) &&
             ((particle1.get_position(coordinate) + particle1.get_velocity(coordinate) * delta_t + particle1.get_acceleration(coordinate) * pow(delta_t, 2) / 2.0) >
              (particle2.get_position(coordinate) + particle2.get_velocity(coordinate) * delta_t + particle2.get_acceleration(coordinate) * pow(delta_t, 2) / 2.0))) ||
            ((particle1.get_position(coordinate) > particle2.get_position(coordinate)) &&
             ((particle1.get_position(coordinate) + particle1.get_velocity(coordinate) * delta_t + particle1.get_acceleration(coordinate) * pow(delta_t, 2) / 2.0) <
              (particle2.get_position(coordinate) + particle2.get_velocity(coordinate) * delta_t + particle2.get_acceleration(coordinate) * pow(delta_t, 2) / 2.0))));
}

int particles_scattering(std::vector<Particle> particles, double delta_t, std::ostream &output)
{
    // initialize scattering count
    int scattering = 0;

    // cycle over particles
    for (int i = 0; i < particles.size() - 1; i++)
    {
        // mass of the first particle
        double m1 = particles[i].get_mass();

        // cycle over remaining particles
        for (int j = i + 1; j < particles.size(); j++)
        {
            // mass of the second particle
            double m2 = particles[i].get_mass();

            // if the two particles collide
            if (scatter(0, delta_t, particles[i], particles[j]) && scatter(1, delta_t, particles[i], particles[j]) && scatter(2, delta_t, particles[i], particles[j]))
            {
                // cycle over dimensions
                for (int k = 0; k < DIMENSION; k++)
                {
                    // elastic scattering of velocities
                    double v1 = ((m1 - m2) / (m2 - m1)) * particles[i].get_velocity(k) + (2 * m2 / (m1 + m2)) * particles[j].get_velocity(k);
                    double v2 = ((m2 - m1) / (m2 - m1)) * particles[j].get_velocity(k) + (2 * m1 / (m1 + m2)) * particles[i].get_velocity(k);

                    // elastic scattering of accelerations
                    double a1 = particles[i].get_acceleration(k) - (m2 / m1) * particles[j].get_acceleration(k);
                    double a2 = particles[j].get_acceleration(k) - (m1 / m2) * particles[i].get_acceleration(k);

                    // the settings are postponed because otherwise the calculations of accelerations would be wrong

                    particles[i].set_velocity(k, v1);
                    particles[j].set_velocity(k, v2);
                    particles[i].set_acceleration(k, a1);
                    particles[j].set_acceleration(k, a2);
                }

                // output that a scattering happened on log file
                output << "Scattering\n"
                       << std::endl;
                       
                // update scattering counter
                scattering++;
            }
        }
    }

    return scattering;
}