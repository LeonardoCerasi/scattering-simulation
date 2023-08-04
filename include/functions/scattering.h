#pragma once

#include <cmath>
#include <vector>

#include "classes/particle.h"
#include "classes/framework.h"

/**
 * @brief This function checks if two given Particles scatter in a given time interval along a given coordinate
 *
 * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
 * @param delta_t Time interval [s]
 * @param particle1 Particle object
 * @param particle2Particle object
 * @return True if the two Particles scatter
 * @return False if the two Particles don't scatter
 */
bool scatter(int coordinate, double delta_t, Particle particle1, Particle particle2);

/**
 * @brief This function manages the scattering calculations for a vector of Particles in a given time interval, returns the number of scatterings that happened and prints it on the output Ostream object
 *
 * @param particles Vector of Particle objects
 * @param delta_t Time interval [s]
 * @param output Ostream object
 * @return (int) Number of scatterings
 */
int particles_scattering(std::vector<Particle> &particles, double delta_t, std::ostream &output);
