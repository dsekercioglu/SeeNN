//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#ifndef SEENN_SGD_H
#define SEENN_SGD_H


#include "Optimizer.h"
#include "../nn/SeqNet.h"

class SGD : public Optimizer {

public:

    double learningRate;
    std::vector<std::vector<double>> delta;
    std::vector<std::vector<double>> step;
    SeqNet &seqNet;

    SGD(SeqNet &seqNet, double learningRate);

    void backPropagate(std::vector<double> &input, std::vector<double> &output) override;

    void applyStep() override;
};


#endif //SEENN_SGD_H
