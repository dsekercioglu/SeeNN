//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#include <vector>
#include "Bias.h"
#include "../Utils.h"


Bias::Bias(int input, double range) {
    this->input = input;
    this->output = input;
    for (int i = 0; i < input * input; i++) {
        connections.push_back(Utils::fRand(-range, range));
    }
}

void Bias::feedForward(std::vector<double> &input, std::vector<double> &output) {
    for (int i = 0; i < input.size(); i++) {
        output[i] = input[i] + connections[i];
    }
}

void Bias::cachedFeedForward(std::vector<double> &input, std::vector<double> &output) {
    return feedForward(input, output);
}

void Bias::backPropagate(std::vector<double> &outputError, std::vector<double> &prevError) {
    for (int i = 0; i < outputError.size(); i++) {
        prevError[i] = outputError[i];
    }
}

int Bias::numParams() {
    return input;
}

void Bias::addStep(std::vector<double> &delta, std::vector<double> &step) {
    for (int i = 0; i < delta.size(); i++) {
        step[i] += delta[i];
    }
}

void Bias::applyStep(std::vector<double> &step) {
    for (int i = 0; i < step.size(); i++) {
        connections[i] -= step[i];
    }
}
