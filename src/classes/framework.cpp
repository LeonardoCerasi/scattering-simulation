#include "classes/framework.h"

// constructors

Framework::Framework() : r_min{}, r_max{} {}

Framework::Framework(std::array<double, D> R_min, std::array<double, D> R_max) : r_min{R_min}, r_max{R_max} {}

// get methods

std::array<double, D> Framework::get_r_min() { return this->r_min; }

std::array<double, D> Framework::get_r_max() { return this->r_max; }

// set methods

void Framework::set_r_min(std::array<double, D> R_min) { this->r_min = R_min; }

void Framework::set_r_max(std::array<double, D> R_max) { this->r_max = R_max; }

// log method

std::string Framework::log()
{
    // support function
    auto print{[&] (std::array<double, D> arr) -> std::string
    {
        std::string str{};
        str += "(  ";
        for (int i{}; i < (int)arr.size() - 1; i++) { str += std::to_string(arr.at(i)) + "  ,  "; }
        str += std::to_string(arr.at(arr.size() - 1)) + "  )";
        return str;
    }};

    std::string description{};

    description += "min: " + print(this->r_min) + "\n";
    description += "max: " + print(this->r_max);

    return description;
}

// miscellaneous methods

Framework frame_init(const std::string path)
{
    // support function
    auto load{[&] (std::ifstream &input) -> std::array<double, D>
    {
        std::array<double, D> supp{};
        for (int i{}; i < (int)supp.size(); i++) { input >> supp.at(i); }
        return supp;
    }};

    std::ifstream input{path};
    if (!input) { throw std::invalid_argument("Error while opening file " + path); }

    return Framework(load(input), load(input));
}
