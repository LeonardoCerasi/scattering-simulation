#include "classes/particle.h"

// constructors

Particle::Particle() : m{}, r{} {}

Particle::Particle(double M, std::array<double, 3*D> initial_state) : m{M}, r{initial_state} {}

// get methods

double Particle::get_m() const { return this->m; }
std::array<double, 3*D> Particle::get_r() const { return this->r; }

double Particle::get_x(int i) const { return this->get_r().at(i); }
double Particle::get_v(int i) const { return this->get_r().at(i + D); }
double Particle::get_a(int i) const { return this->get_r().at(i + 2*D); }

// set methods

void Particle::set_m(double M) { this->m = M; }
void Particle::set_r(std::array<double, 3*D> R) { this->r = R; }

void Particle::set_x(int i, double x) { this->r.at(i) = x; }
void Particle::set_v(int i, double v) { this->r.at(i + D) = v; }
void Particle::set_a(int i, double a) { this->r.at(i + 2*D) = a; }

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

    description += "m:    " + std::to_string(this->m) + "\n";
    description += "r: " + print(this->r, 0) + "\n";
    description += "v: " + print(this->r, 1) + "\n";
    description += "a: " + print(this->r, 2);

    return description;
}

// motion method

void Particle::motion(double t, double Δt)
{
    auto f{[&] (double t, const std::array<double, 3*D> &x) -> std::array<double, 3*D>
    {
        std::array<double, 3*D> supp{x};
        std::rotate(supp.begin(), supp.begin() + D, supp.end());
        std::fill(supp.begin() + 2*D, supp.end(), 0);
        return supp;
    }};

    this->r = runge_kutta<3*D>(t, Δt, this->r, f);
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
