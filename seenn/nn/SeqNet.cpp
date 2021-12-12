//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#include "SeqNet.h"
#include <vector>

SeqNet::SeqNet(std::unique_ptr<std::vector<std::unique_ptr<Layer>>> layers) {
    this->layers = std::move(layers);
    this->outputBuffers = std::vector<std::vector<double>>(this->layers->size());
    for (int i = 0; i < this->layers->size(); i++) {
        outputBuffers[i] = std::vector<double>((*this->layers)[i]->output);
    }
}

std::vector<double> &SeqNet::feedForward(std::vector<double> &input) {
    (*layers)[0]->feedForward(input, outputBuffers[0]);
    for (int i = 1; i < layers->size(); i++) {
        (*layers)[i]->feedForward(outputBuffers[i - 1], outputBuffers[i]);
    }
    return outputBuffers[layers->size() - 1];
}

std::vector<double> &SeqNet::cachedFeedForward(std::vector<double> &input) {
    (*layers)[0]->cachedFeedForward(input, outputBuffers[0]);
    for (int i = 1; i < layers->size(); i++) {
        (*layers)[i]->cachedFeedForward(outputBuffers[i - 1], outputBuffers[i]);
    }
    return outputBuffers[layers->size() - 1];
}
