#include "classes/particle.h"

// constructors

Particle::Particle() : m{}, r{} {}

Particle::Particle(double M, std::array<double, 3*D> initial_state) : m{M}, r{initial_state} {}

// get methods

double Particle::get_m() { return m; }
std::array<double, 3*D> Particle::get_r() { return r; }

// set methods

void Particle::set_m(double M) { m = M; }
void Particle::set_r(std::array<double, 3*D> R) { r = R; }


// log method

std::string Particle::log()
{
    // support function
    auto print{[&] (std::array<double, 3*D> arr, int k) -> std::string
    {
        std::string str{};
        str += "(  ";
        for (int i{}; i < D - 1; i++) { str += std::to_string(arr.at(k*D + i)) + "  ,  "; }
        str += std::to_string(arr.at(k*D + D - 1)) + "  )";
        return str;
    }};

    std::string description{};

    description += "m:    " + std::to_string(m) + "\n";
    description += "r: " + print(r, 0) + "\n";
    description += "v: " + print(r, 1) + "\n";
    description += "a: " + print(r, 2);

    return description;
}

// miscellaneous methods

std::vector<Particle> sys_init(const std::string path)
{
    std::ifstream input{path};
    if (!input) { throw std::invalid_argument("Error while opening file " + path); }

    std::vector<Particle> ensemble{};

    std::string s_supp{};
    std::array<double, 3*D> d_supp{};

    std::getline(input, s_supp);
    while (!input.eof())
    {
        std::stringstream ss_str{s_supp};

        double m{};
        ss_str >> m;
        for (int i{}; i < 3*D; i++) { ss_str >> d_supp.at(i); }

        ensemble.push_back(Particle(m, d_supp));

        d_supp = {};
        std::getline(input, s_supp);
    }

    return ensemble;
}

std::string sys_log(std::vector<Particle> ensemble)
{
    std::string description{};

    for (Particle p : ensemble) { description += p.log() + "\n\n"; }

    return description;
}
