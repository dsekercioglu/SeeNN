#include <iostream>
#include <memory>
#include "seenn/layers/Dense.h"
#include "seenn/nn/SeqNet.h"
#include "seenn/layers/Bias.h"
#include "seenn/optim/SGD.h"
#include "seenn/Utils.h"
#include "seenn/layers/Activation.h"
#include "seenn/functions/ReLU.h"
#include "seenn/functions/Sigmoid.h"
#include <vector>
#include <chrono>

int main() {
    /*
     * 42139016932
     * 43072674356ns
     * 14861448542ns
     *
     */



    srand(1);
    auto layers = std::make_unique<std::vector<std::unique_ptr<Layer>>>();
    std::shared_ptr<Function> relu = std::make_shared<ReLU>();
    std::shared_ptr<Function> sigmoid = std::make_shared<Sigmoid>();
    auto dense0 = std::make_unique<Dense>(2, 16, 1);
    auto relu0 = std::make_unique<Activation>(16, relu);
    auto dense1 = std::make_unique<Dense>(16, 1, 1);
    layers->emplace_back(std::move(dense0));
    layers->emplace_back(std::move(relu0));
    layers->emplace_back(std::move(dense1));
    auto nn = SeqNet(std::move(layers));
    auto optim = SGD(nn, 1e-2);

    std::vector<std::vector<double>> in = {{0, 0},
                                           {0, 1},
                                           {1, 0},
                                           {1, 1}};
    std::vector<std::vector<double>> out = {{0},
                                            {1},
                                            {1},
                                            {0}};

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 4000000; i++) {
        int index = i % 4;
        optim.backPropagate(in[index], out[index]);
        optim.applyStep();
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count() << "ns\n";

    for (auto &i : in) {
        std::vector<double> output = nn.feedForward(i);
        for (int j = 0; j < output.size() - 1; j++) {
            std::cout << output[j] << ", ";
        }
        std::cout << output[output.size() - 1] << std::endl;
    }
    return 0;
}

