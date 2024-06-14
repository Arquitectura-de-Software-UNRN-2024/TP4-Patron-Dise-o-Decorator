/**
 * @file carne_decorator.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/carne_decorator.hpp"

CarneDecorator::CarneDecorator(Combo &decorado) : AditionalDecorator(decorado) {
}

const std::string CarneDecorator::name = "hamburguesa";

std::string CarneDecorator::getName() {
    return CarneDecorator::name;
}

const float CarneDecorator::value = 1.0;

float CarneDecorator::getValorAgregado() {
    return CarneDecorator::value;
}