/**
 * @file tomate_decorator.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/tomate_decorator.hpp"

TomateDecorator::TomateDecorator(Combo &decorado)
    : AditionalDecorator(decorado) {
}

const std::string TomateDecorator::name = "tomate";

std::string TomateDecorator::getName() {
    return TomateDecorator::name;
}

const float TomateDecorator::value = 0.5;

float TomateDecorator::getValorAgregado() {
    return TomateDecorator::value;
}