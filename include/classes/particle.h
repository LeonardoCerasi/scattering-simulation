#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "tools/input.h"

static const int DIMENSION = 3;

class Particle
{
private:
    // Mass
    double m = 0;

    // Position
    std::vector<double> r{0, 0, 0};

    // Velocity
    std::vector<double> v{0, 0, 0};

    // Acceleration
    std::vector<double> a{0, 0, 0};

public:
    /**
     * @brief Default constructor: construct an empty Particle object
     *
     */
    Particle() {}

    /**
     * @brief Construct a new Particle object in a given initial state
     *
     * @param initial_state Vector of initial parameteres
     */
    Particle(std::vector<double> initial_state)
    {
        // Mass
        m = initial_state[0];

        // Initial coordinates
        r[0] = initial_state[1];
        r[1] = initial_state[2];
        r[2] = initial_state[3];

        // Initial velocities
        v[0] = initial_state[4];
        v[1] = initial_state[5];
        v[2] = initial_state[6];

        // Initial accelerations
        a[0] = initial_state[7];
        a[1] = initial_state[8];
        a[2] = initial_state[9];
    }

    // Set Functions

    /**
     * @brief Sets the mass of the Particle to the given value
     *
     * @param value Mass of the Particle [kg]
     */
    void set_mass(double value);

    /**
     * @brief Sets the position of the Particle along the selected coordinate to the given value
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @param value Position of the Particle [m]
     */
    void set_position(int coordinate, double value);

    /**
     * @brief Sets the velocity of the Particle along the selected coordinate to the given value
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @param value Velocity of the Particle [m/s]
     */
    void set_velocity(int coordinate, double value);

    /**
     * @brief Sets the acceleration of the Particle along the selcted coordinate to the given value
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @param value Acceleration of the particle [m/s²]
     */
    void set_acceleration(int coordinate, double value);

    // Get Functions

    /**
     * @brief Returns the mass of the Particle
     *
     * @return (double) Mass [kg]
     */
    double get_mass();

    /**
     * @brief Returns the position of the Particle along the selected coordinate
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @return (double) Position [m]
     */
    double get_position(int coordinate);

    /**
     * @brief Returns the velocity of the Particle along the selected coordinate
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @return (double) Velocity [m/s]
     */
    double get_velocity(int coordinate);

    /**
     * @brief Returns the acceleration of the Particle along the selected coordinate
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @return (double) Acceleration [m/s²]
     */
    double get_acceleration(int coordinate);

    /**
     * @brief Moves the Particle forward in time of a given time interval
     *
     * @param delta_t Time interval [s]
     */
    void motion(double delta_t);

    /**
     * @brief Prints on an output Ostream object the full description of the Particle
     *
     * @param output Ostream object
     */
    void particle_log(std::ostream &output);
};

/**
 * @brief Initializes a vector of Particle objects from an input file of space-separated values
 *
 * @param path Path of the input file
 * @return (std::vector<Particle>) Ensemble of particles
 */
std::vector<Particle> init_particles(const char *path);

/**
 * @brief Prints on an output Ostream objects the full description of the Particle system
 *
 * @param output Ostream object
 * @param particles Vector of Particle objects
 */
void system_log(std::ostream &output, std::vector<Particle> particles);
