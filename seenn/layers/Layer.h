//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#ifndef SEENN_LAYER_H
#define SEENN_LAYER_H

class Layer {

public:
    int input;
    int output;

    virtual void feedForward(std::vector<double> &input, std::vector<double> &output) = 0;

    virtual void cachedFeedForward(std::vector<double> &input, std::vector<double> &output) = 0;

    virtual void backPropagate(std::vector<double> &outputError, std::vector<double> &prevError) = 0;

    virtual void addStep(std::vector<double> &delta, std::vector<double> &step) = 0;

    virtual void applyStep(std::vector<double> &step) = 0;

    virtual int numParams() = 0;

};

#endif //SEENN_LAYER_H
