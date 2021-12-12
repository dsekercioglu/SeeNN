//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#ifndef SEENN_ACTIVATION_H
#define SEENN_ACTIVATION_H


#include <vector>
#include "Layer.h"
#include "../functions/Function.h"

class Activation : public Layer {

private:
    std::shared_ptr<Function> function;
    std::vector<std::array<double, 2>> out;

public:

    Activation(int input, std::shared_ptr<Function> function);

    void feedForward(std::vector<double> &input, std::vector<double> &output) override;

    void cachedFeedForward(std::vector<double> &input, std::vector<double> &output) override;

    void backPropagate(std::vector<double> &outputError, std::vector<double> &prevError) override;

    void addStep(std::vector<double> &delta, std::vector<double> &step) override;

    void applyStep(std::vector<double> &step) override;

    int numParams() override;

};


#endif //SEENN_ACTIVATION_H
