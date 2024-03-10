#pragma once

#include <cmath>

#include "classes/particle.h"
#include "classes/framework.h"

void constraints(const Framework &frame, Particle p);
void constraints(const Framework &frame, std::vector<Particle> ensemble);
