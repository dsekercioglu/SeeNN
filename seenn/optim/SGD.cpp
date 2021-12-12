//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#include <iostream>
#include "SGD.h"


SGD::SGD(SeqNet &seqNet, double learningRate) : seqNet(seqNet) {
    this->learningRate = learningRate;
    int size = seqNet.layers->size();
    delta = std::vector<std::vector<double>>(size);
    step = std::vector<std::vector<double>>(size);
    for (int i = 0; i < size; i++) {
        delta[i] = std::vector<double>((*seqNet.layers)[i]->output);
        step[i] = std::vector<double>((*seqNet.layers)[i]->numParams());
        for (int j = 0; j < step[i].size(); j++) {
            step[i][j] = 0;
        }
    }
}

void SGD::backPropagate(std::vector<double> &input, std::vector<double> &output) {
    int lastIndex = (int)seqNet.layers->size() - 1;
    std::vector<double> predicted = seqNet.cachedFeedForward(input);
    for (int i = 0; i < predicted.size(); i++) {
        delta[lastIndex][i] = predicted[i] - output[i];
    }

    (*seqNet.layers)[lastIndex]->addStep(delta[lastIndex], step[lastIndex]);
    for (int i = lastIndex; i > 0; i--) {
        (*seqNet.layers)[i]->backPropagate(delta[i], delta[i - 1]);
        (*seqNet.layers)[i - 1]->addStep(delta[i - 1], step[i - 1]);
    }
}

void SGD::applyStep() {
    for (int i = 0; i < seqNet.layers->size(); i++) {
        for (int j = 0; j < step[i].size(); j++) {
            step[i][j] *= learningRate;
        }
        (*seqNet.layers)[i]->applyStep(step[i]);
        for (int j = 0; j < step[i].size(); j++) {
            step[i][j] = 0;
        }
    }
}
