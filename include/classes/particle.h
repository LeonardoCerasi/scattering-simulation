#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "constants.h"
#include "arr_op.h"
#include "integration/runge_kutta.h"

class Particle
{
    private:

        double m;
        std::array<double, 3*D> r;
    
    public:

        // constructors

        Particle();
        Particle(double M, std::array<double, 3*D> initial_state);

        // get methods

        double get_m() const;
        std::array<double, 3*D> get_r() const;

        double get_x(int i) const;
        double get_v(int i) const;
        double get_a(int i) const;

        // set methods

        void set_m(double M);
        void set_r(std::array<double, 3*D> R);

        void set_x(int i, double x);
        void set_v(int i, double v);
        void set_a(int i, double a);
        
        // log method

        std::string log();

        // motion method

        void motion(double t, double Δt);
};

// miscellaneous methods

std::vector<Particle> sys_init(const std::string path);

std::string sys_log(std::vector<Particle> ensemble);
