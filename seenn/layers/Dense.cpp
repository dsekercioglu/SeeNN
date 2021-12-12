//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#include <vector>
#include "../Utils.h"
#include "Dense.h"

Dense::Dense(int in, int out, double range) {
    lastInput = std::vector<double>(in);
    this->input = in;
    this->output = out;
    for (int i = 0; i < in * out; i++) {
        connections.push_back(Utils::fRand(-range, range));
    }
}

void Dense::feedForward(std::vector<double> &input, std::vector<double> &output) {
    for (int i = 0; i < this->output; i++) {
        int offset = i * this->input;
        output[i] = connections[offset] * input[0];
        for (int j = 1; j < this->input; j++) {
            output[i] += connections[offset + j] * input[j];
        }
    }
}

void Dense::cachedFeedForward(std::vector<double> &input, std::vector<double> &output) {
    for (int i = 0; i < lastInput.size(); i++) {
        lastInput[i] = input[i];
    }
    return this->feedForward(input, output);
}

void Dense::backPropagate(std::vector<double> &outputError, std::vector<double> &prevError) {
    int index;
    for (int i = 0; i < input; i++) {
        index = i;
        prevError[i] = connections[index] * outputError[0];
        for (int j = 1; j < output; j++) {
            prevError[i] += connections[index + j * output] * outputError[j];
        }
    }
}

int Dense::numParams() {
    return connections.size();
}

void Dense::addStep(std::vector<double> &delta, std::vector<double> &step) {
    for (int i = 0; i < output; i++) {
        for (int j = 0; j < input; j++) {
            step[i * input + j] += delta[i] * lastInput[j];
        }
    }
}

void Dense::applyStep(std::vector<double> &step) {
    for(int i = 0; i < step.size(); i++) {
        connections[i] -= step[i];
    }
}
