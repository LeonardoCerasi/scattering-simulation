#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

#include "classes/particle.h"
#include "tools/input.h"

class Framework
{
private:
    // Initial minimum edges
    std::vector<double> min_0{0, 0, 0};

    // Initial maximum edges
    std::vector<double> max_0{0, 0, 0};

    // Initial velocities
    std::vector<double> v_0{0, 0, 0};

    // Minimum edges
    std::vector<double> min{0, 0, 0};

    // Maximum edges
    std::vector<double> max{0, 0, 0};

    // Velocities
    std::vector<double> v{0, 0, 0};

    // Periods of oscillations
    std::vector<double> t{0, 0, 0};

public:
    /**
     * @brief Default constructor: construct an empty Framework object
     *
     */
    Framework() {}

    /**
     * @brief Construct a new Framework object in a given initial state
     *
     * @param initial_state vector of initial parameters
     */
    Framework(std::vector<double> initial_state)
    {
        // cycle over dimensions
        for (int i = 0; i < DIMENSION; i++)
        {
            // initial minimum edges
            min_0[i] = initial_state[i];
            min[i] = initial_state[i];

            // initial maximum edges
            max_0[i] = initial_state[i + DIMENSION];
            max[i] = initial_state[i + DIMENSION];

            // initial velocities
            v_0[i] = initial_state[i + 2 * DIMENSION];
            v[i] = initial_state[i + 2 * DIMENSION];

            // periods of oscillations
            t[i] = initial_state[i + 3 * DIMENSION];
        }
    }

    // Set Functions

    /**
     * @brief Sets the minimum edge of the Framework along the selected coordinate to the given value
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @param value Minimum edge of the Framework [m]
     */
    void set_minimum(int coordinate, double value);

    /**
     * @brief Sets the maximum edge of the Framework along the selected coordinate to the given value
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @param value Maximum edge of the Framework [m]
     */
    void set_maximum(int coordinate, double value);

    /**
     * @brief Sets the velocity of the Framework along the selected coordinate to the given value
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @param value Velocity of the Framework [m/s]
     */
    void set_velocity(int coordinate, double value);

    /**
     * @brief Sets the period of the oscillation of the Framework along the selected coordinate to the given value
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @param value Period of the Framework [s]
     */
    void set_period(int coordinate, double value);

    // Set Functions

    /**
     * @brief Returns the initial minimum edge of the Framework along the selected coordinate
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @return (double) Initial minimum edge [m]
     */
    double get_initial_minimum(int coordinate);

    /**
     * @brief Returns the initial maximum edge of the Framework along the selected coordinate
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @return (double) Initial maximum edge [m]
     */
    double get_initial_maximum(int coordinate);

    /**
     * @brief Returns the initial velocity of the Framework along the selected coordinate
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @return (double) Initial velocity [m/s]
     */
    double get_initial_velocity(int coordinate);

    /**
     * @brief Returns the current minimum edge of the Framework along the selected coordinate
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @return (double) Current minimum edge [m]
     */
    double get_minimum(int coordinate);

    /**
     * @brief Returns the current maximum edge of the Framework along the selected coordinate
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @return (double) Current maximum edge [m]
     */
    double get_maximum(int coordinate);

    /**
     * @brief Returns the current velocity of the Framework along the selected coordinate
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @return (double) Current velocity [m/s]
     */
    double get_velocity(int coordinate);

    /**
     * @brief Returns the period of the oscillation of the Framework along the selected coordinate
     *
     * @param coordinate Selected coordinate (0: x / 1: y / 2: z)
     * @return (double) Period [s]
     */
    double get_period(int coordinate);

    /**
     * @brief Moves the Framework to a given instant in time, starting from t=0[s]
     *
     * @param t Time instant [s]
     */
    void framework_motion(double t);

    /**
     * @brief Prints on an output Ostream object the full description of the Framework
     *
     * @param output Ostream object
     */
    void framework_log(std::ostream &output);

    /**
     * @brief Constrains the given Particle inside the Framework at the given time instant, starting from t=0[s]
     *
     * @param particle Particle object
     * @param t Time instant [s]
     */
    void constraints(Particle particle, double t);
};

/**
 * @brief Initializes a Framework object from an input file of space-separated values
 *
 * @param path Path of the input file
 * @return (Framework) Framework object
 */
Framework init_framework(const char *path);
