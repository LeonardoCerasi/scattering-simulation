#include "classes/particle.h"

// constructors

Particle::Particle() : m{}, r{}, v{}, a{} {}

Particle::Particle(double M, std::vector<std::array<double, D>> initial_state) : m{M}, r{initial_state.at(0)}, v{initial_state.at(1)}, a{initial_state.at(2)} {}

// get methods

double Particle::get_m() { return m; }
std::array<double, D> Particle::get_r() { return r; }
std::array<double, D> Particle::get_v() { return v; }
std::array<double, D> Particle::get_a() { return a; }

// set methods

void Particle::set_m(double M) { m = M; }
void Particle::set_r(std::array<double, D> R) { r = R; }
void Particle::set_v(std::array<double, D> V) { v = V; }
void Particle::set_a(std::array<double, D> A) { a = A; }

// log method

std::string Particle::log()
{
    // support function
    auto print{[&] (std::array<double, D> arr) -> std::string
    {
        std::string str{};
        str += "(  ";
        for (int i{}; i < D - 1; i++) { str += std::to_string(arr.at(i)) + "  ,  "; }
        str += std::to_string(arr.at(D - 1)) + "  )";
        return str;
    }};

    std::string description{};

    description += "m:    " + std::to_string(m) + "\n";
    description += "r: " + print(r) + "\n";
    description += "v: " + print(v) + "\n";
    description += "a: " + print(a);

    return description;
}

// miscellaneous methods

std::vector<Particle> sys_init(const char *path)
{

}

std::string sys_log(std::vector<Particle> ensemble)
{
    std::string description{};

    for (Particle p : ensemble) { description += p.log() + "\n\n"; }

    return description;
}
