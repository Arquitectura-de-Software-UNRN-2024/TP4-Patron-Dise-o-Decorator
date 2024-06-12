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

std::string TomateDecorator::getDescripcion() {
    return AditionalDecorator::getDescripcion() + " + tomate";
}

float TomateDecorator::getValor() {
    return AditionalDecorator::getValor() + 0.50;
}
