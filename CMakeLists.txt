cmake_minimum_required(VERSION 3.17)
project(SeeNN)

set(CMAKE_CXX_STANDARD 17)

add_executable(SeeNN main.cpp seenn/layers/Layer.h seenn/layers/Dense.cpp seenn/layers/Dense.h seenn/Utils.cpp seenn/Utils.h seenn/nn/SeqNet.cpp seenn/nn/SeqNet.h seenn/layers/Bias.cpp seenn/layers/Bias.h seenn/optim/Optimizer.h seenn/optim/SGD.cpp seenn/optim/SGD.h seenn/layers/Activation.cpp seenn/layers/Activation.h seenn/functions/Function.h seenn/functions/ReLU.cpp seenn/functions/ReLU.h seenn/functions/Sigmoid.cpp seenn/functions/Sigmoid.h)