//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#ifndef SEENN_BIAS_H
#define SEENN_BIAS_H


#include "Layer.h"

class Bias : public Layer {

private:
    std::vector<double> connections;

public:

    Bias(int input, double range);

    void feedForward(std::vector<double> &input, std::vector<double> &output) override;

    void cachedFeedForward(std::vector<double> &input, std::vector<double> &output) override;

    void backPropagate(std::vector<double> &outputError, std::vector<double> &prevError) override;


    void addStep(std::vector<double> &delta, std::vector<double> &step) override;

    void applyStep(std::vector<double> &step) override;

    int numParams() override;
};


#endif //SEENN_BIAS_H
