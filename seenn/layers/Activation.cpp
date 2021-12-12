//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#include "Activation.h"
#include <array>
#include <utility>

Activation::Activation(int input, std::shared_ptr<Function> function) {
    this->input = input;
    this->output = input;
    this->function = std::move(function);
    this->out = std::vector<std::array<double, 2>>(input);
}

void Activation::feedForward(std::vector<double> &input, std::vector<double> &output) {
    for (int i = 0; i < input.size(); i++) {
        function->activate(input[i], out[i]);
        output[i] = out[i][0];
    }
}

void Activation::cachedFeedForward(std::vector<double> &input, std::vector<double> &output) {
    for (int i = 0; i < input.size(); i++) {
        function->activateDifferentiate(input[i], out[i]);
        output[i] = out[i][0];
    }
}

void Activation::backPropagate(std::vector<double> &outputError, std::vector<double> &prevError) {
    for (int i = 0; i < prevError.size(); i++) {
        prevError[i] = outputError[i] * out[i][1];
    }
}

void Activation::addStep(std::vector<double> &delta, std::vector<double> &step) {

}

void Activation::applyStep(std::vector<double> &step) {

}

int Activation::numParams() {
    return 0;
}
