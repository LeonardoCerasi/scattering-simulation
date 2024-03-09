#pragma once

#include <vector>
#include <string>

#include "constants.h"
#include "arr_op.h"

class Particle
{
    private:

        double m;
        std::array<double, D> r, v, a;
    
    public:

        // constructors

        Particle();
        Particle(double M, std::vector<std::array<double, D>> initial_state);

        // get methods

        double get_m();
        std::array<double, D> get_r();
        std::array<double, D> get_v();
        std::array<double, D> get_a();

        // set methods

        void set_m(double M);
        void set_r(std::array<double, D> R);
        void set_v(std::array<double, D> V);
        void set_a(std::array<double, D> A);
        
        // log method

        std::string log();
};

// miscellaneous methods

std::vector<Particle> sys_init(const char *path);

std::string sys_log(std::vector<Particle> ensemble);
