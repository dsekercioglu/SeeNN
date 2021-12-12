//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#ifndef SEENN_SIGMOID_H
#define SEENN_SIGMOID_H


#include <array>
#include "Function.h"

class Sigmoid : public Function {

public:
    void activate(double in, std::array<double, 2> &out) override;

    void activateDifferentiate(double in, std::array<double, 2> &out) override;
};

#endif //SEENN_SIGMOID_H
