//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#ifndef SEENN_RELU_H
#define SEENN_RELU_H


#include "Function.h"

class ReLU : public Function {

public:
    void activate(double in, std::array<double, 2> &out) override;

    void activateDifferentiate(double in, std::array<double, 2> &out) override;
};


#endif //SEENN_RELU_H
