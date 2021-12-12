//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#include <cstdlib>
#include "Utils.h"

double Utils::fRand(double fMin, double fMax) {
    double f = (double) random() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
