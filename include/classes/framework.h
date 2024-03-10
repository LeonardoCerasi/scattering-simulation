#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "constants.h"
#include "arr_op.h"

class Framework
{
    private:

        std::array<double, D> r_min;
        std::array<double, D> r_max;
    
    public:

        // constructors

        Framework();
        Framework(std::array<double, D> R_min, std::array<double, D> R_max);

        // get methods

        std::array<double, D> get_r_min() const;
        std::array<double, D> get_r_max() const;

        double get_x_min(int i) const;
        double get_x_max(int i) const;

        // set methods

        void set_r_min(std::array<double, D> R_min);
        void set_r_max(std::array<double, D> R_max);

        void set_x_min(int i, double x);
        void set_x_max(int i, double x);

        // log method

        std::string log();
};

// miscellaneous methods

Framework frame_init(const std::string path);
