//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#ifndef SEENN_OPTIMIZER_H
#define SEENN_OPTIMIZER_H


#include <vector>

class Optimizer {

public:
    virtual void backPropagate(std::vector<double> &input, std::vector<double> &output) = 0;

    virtual void applyStep() = 0;
};


#endif //SEENN_OPTIMIZER_H
