//
// Created by Doruk Sekercioglu on 19.10.2020.
//

#ifndef SEENN_FUNCTION_H
#define SEENN_FUNCTION_H


class Function {

public:
    virtual void activate(double in, std::array<double, 2> &out) = 0;

    virtual void activateDifferentiate(double in, std::array<double, 2> &out) = 0;
};


#endif //SEENN_FUNCTION_H
