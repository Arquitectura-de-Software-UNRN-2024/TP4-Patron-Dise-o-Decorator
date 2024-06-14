/**
 * @file queso_decorator.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/queso_decorator.hpp"

QuesoDecorator::QuesoDecorator(Combo &decorado) : AditionalDecorator(decorado) {
}

const std::string QuesoDecorator::name = "queso";

std::string QuesoDecorator::getName() {
    return QuesoDecorator::name;
}

const float QuesoDecorator::value = 0.8;

float QuesoDecorator::getValorAgregado() {
    return QuesoDecorator::value;
}
