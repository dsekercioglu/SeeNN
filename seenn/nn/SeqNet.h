//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#ifndef SEENN_SEQNET_H
#define SEENN_SEQNET_H


#include <vector>
#include "../layers/Layer.h"

class SeqNet {

public:
    std::unique_ptr<std::vector<std::unique_ptr<Layer>>> layers;
    std::vector<std::vector<double>> outputBuffers;

    explicit SeqNet(std::unique_ptr<std::vector<std::unique_ptr<Layer>>> layers);

    std::vector<double> &feedForward(std::vector<double> &input);

    std::vector<double> &cachedFeedForward(std::vector<double> &input);
};


#endif //SEENN_SEQNET_H
