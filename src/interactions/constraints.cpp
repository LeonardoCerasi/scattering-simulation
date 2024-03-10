#include "interactions/constraints.h"

void constr(const std::array<double, D> arr, Particle p, const int signum)
{
    for (int i{}; i < D; i++)
    {
        if (std::fabs(arr.at(i) - p.get_x(i)) < ε && (signum * sign(p.get_v(i))) > 0)
        {
            p.set_x(i, arr.at(i));
            p.set_v(i, -p.get_v(i));
        }
    }
}

void constraints(const Framework &frame, Particle p)
{
    constr(frame.get_r_max(), p, 1);
    constr(frame.get_r_min(), p, -1);
}

void constraints(const Framework &frame, std::vector<Particle> ensemble)
{
    for (Particle p : ensemble)
    {
        constr(frame.get_r_max(), p, 1);
        constr(frame.get_r_min(), p, -1);
    }
}
