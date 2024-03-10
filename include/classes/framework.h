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

        std::array<double, D> get_r_min();
        std::array<double, D> get_r_max();

        // set methods

        void set_r_min(std::array<double, D> R_min);
        void set_r_max(std::array<double, D> R_max);

        // log method

        std::string log();
};

// miscellaneous methods

Framework frame_init(const std::string path);
