#pragma once

const static int D{3};

const static double ε{5e-4};

const static double h{0.0001};

inline double sign (double x)
{
    return (x == 0 ? 0 : (x > 0 ? 1 : -1));
}
