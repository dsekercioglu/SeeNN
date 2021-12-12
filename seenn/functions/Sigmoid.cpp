//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#include <cmath>
#include "Sigmoid.h"

void Sigmoid::activate(double in, std::array<double, 2> &out) {
    out[0] = 1 / (1 + std::exp(-in));
}

void Sigmoid::activateDifferentiate(double in, std::array<double, 2> &out) {
    out[0] = 1 / (1 + std::exp(-in));
    out[1] = out[0] * (1 - out[0]);
}
