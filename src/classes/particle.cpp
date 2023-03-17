#include "classes/particle.h"

// Set Functions

void Particle::set_mass(double value)
{
    this->m = value;
}

void Particle::set_position(int coordinate, double value)
{
    this->r[coordinate] = value;
}

void Particle::set_velocity(int coordinate, double value)
{
    this->v[coordinate] = value;
}

void Particle::set_acceleration(int coordinate, double value)
{
    this->a[coordinate] = value;
}

// Get Functions

double Particle::get_mass()
{
    return this->m;
}

double Particle::get_position(int coordinate)
{
    return this->r[coordinate];
}

double Particle::get_velocity(int coordinate)
{
    return this->v[coordinate];
}

double Particle::get_acceleration(int coordinate)
{
    return this->a[coordinate];
}

void Particle::motion(double delta_t)
{
    // cycle over dimensions
    for (int i = 0; i < DIMENSION; i++)
    {
        // variation of velocity
        this->set_velocity(i, this->get_velocity(i) + this->get_acceleration(i) * delta_t);

        // variation of positions
        this->set_position(i, this->get_position(i) + this->get_velocity(i) * delta_t - this->get_acceleration(i) * pow(delta_t, 2) / 2.0);
    }
}

void Particle::particle_log(std::ostream &output)
{
    output << "m: " << this->get_mass() << std::endl;

    output << "x: " << this->get_position(0) << std::endl;
    output << "y: " << this->get_position(1) << std::endl;
    output << "z: " << this->get_position(2) << std::endl;

    output << "v_x: " << this->get_velocity(0) << std::endl;
    output << "v_y: " << this->get_velocity(1) << std::endl;
    output << "v_z: " << this->get_velocity(2) << std::endl;

    output << "a_x: " << this->get_acceleration(0) << std::endl;
    output << "a_y: " << this->get_acceleration(1) << std::endl;
    output << "a_z: " << this->get_acceleration(2) << std::endl
           << std::endl;
}

std::vector<Particle> init_particles(const char *path)
{
    // initialize vector of particles
    std::vector<Particle> ensemble;

    // vector of particles' data
    std::vector<std::vector<double>> data = read_data(path, 'p');

    // push particles into the ensemble
    for (int i = 0; i < data.size(); i++)
    {
        ensemble.push_back(Particle(data[i]));
    }

    return ensemble;
}

void system_log(std::ostream &output, std::vector<Particle> particles)
{
    // cycle over particles
    for (int i = 0; i < particles.size(); i++)
    {
        output << "Particle " << (i + 1) << std::endl;

        particles[i].particle_log(output);
    }
}
