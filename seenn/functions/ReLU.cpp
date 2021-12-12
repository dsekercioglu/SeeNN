//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#include <array>
#include "ReLU.h"

void ReLU::activate(double in, std::array<double, 2> &out) {
    out[0] = in > 0 ? in : 0;
}

void ReLU::activateDifferentiate(double in, std::array<double, 2> &out) {
    if (in > 0) {
        out[0] = in;
        out[1] = 1;
    } else {
        out[0] = 0;
        out[1] = 0;
    }
}
