#include "classes/framework.h"

// Set Functions

void Framework::set_minimum(int coordinate, double value)
{
    this->min[coordinate] = value;
}

void Framework::set_maximum(int coordinate, double value)
{
    this->max[coordinate] = value;
}

void Framework::set_velocity(int coordinate, double value)
{
    this->v[coordinate] = value;
}

void Framework::set_period(int coordinate, double value)
{
    this->t[coordinate] = value;
}

// Get Functions

double Framework::get_initial_minimum(int coordinate)
{
    return this->min_0[coordinate];
}

double Framework::get_initial_maximum(int coordinate)
{
    return this->max_0[coordinate];
}

double Framework::get_initial_velocity(int coordinate)
{
    return this->v_0[coordinate];
}

double Framework::get_minimum(int coordinate)
{
    return this->min[coordinate];
}

double Framework::get_maximum(int coordinate)
{
    return this->max[coordinate];
}

double Framework::get_velocity(int coordinate)
{
    return this->v[coordinate];
}

double Framework::get_period(int coordinate)
{
    return this->t[coordinate];
}

void Framework::framework_motion(double t)
{
    // cycle over dimensions
    for (int i = 0; (get_period(i) != 0) && i < DIMENSION; i++)
    {
        // harmonic motion  of minimum edges
        this->set_minimum(i, this->get_initial_minimum(i) + (this->get_initial_velocity(i) * this->get_period(i) / (2 * M_PI)) * sin(2 * M_PI * t / this->get_period(i)));

        // harmonic motion of the maximum edges
        this->set_maximum(i, this->get_initial_maximum(i) + (this->get_initial_velocity(i) * this->get_period(i) / (2 * M_PI)) * sin(2 * M_PI * t / this->get_period(i)));

        // harmonic motion of the velocities
        this->set_velocity(i, this->get_initial_velocity(i) * cos(2 * M_PI * t / this->get_period(i)));
    }
}

void Framework::framework_log(std::ostream &output)
{
    output << "\nBox:" << std::endl;

    output << "x_min: " << this->get_minimum(0) << std::endl;
    output << "y_min: " << this->get_minimum(1) << std::endl;
    output << "z_min: " << this->get_minimum(2) << std::endl;

    output << "x_max: " << this->get_maximum(0) << std::endl;
    output << "y_max: " << this->get_maximum(1) << std::endl;
    output << "z_max: " << this->get_maximum(2) << std::endl;

    output << "v_x: " << this->get_velocity(0) << std::endl;
    output << "v_y: " << this->get_velocity(1) << std::endl;
    output << "v_z: " << this->get_velocity(2) << std::endl;

    output << "t_x: " << this->get_period(0) << std::endl;
    output << "t_y: " << this->get_period(1) << std::endl;
    output << "t_z: " << this->get_period(2) << std::endl
           << std::endl;
}

void Framework::constraints(Particle &particle, double delta_t)
{
    // cycle over dimensions
    for (int i = 0; i < DIMENSION; i++)
    {
        // particle collides with minimum edge
        if (particle.get_position(i) < this->get_minimum(i) && particle.get_velocity(i) < this->get_velocity(i))
        {
            // collision particle-wall
            particle.set_position(i, this->get_minimum(i));
            particle.set_velocity(i, (2 * this->get_velocity(i) - particle.get_velocity(i)));

            // if needed, change verse of acceleration
            if (particle.get_acceleration(i) < 0)
            {
                particle.set_acceleration(i, -particle.get_acceleration(i));
            }
        }
        // particle collides with maximum edge
        else if (particle.get_position(i) > this->get_maximum(i) && particle.get_velocity(i) > this->get_velocity(i))
        {
            // collision particle-wall
            particle.set_position(i, this->get_maximum(i));
            particle.set_velocity(i, (2 * this->get_velocity(i) - particle.get_velocity(i)));

            // if needed, change verse of acceleration
            if (particle.get_acceleration(i) > 0)
            {
                particle.set_acceleration(i, -particle.get_acceleration(i));
            }
        }
    }
}

Framework init_framework(const char *path)
{
    return Framework(read_data(path, 'f')[0]);
}
