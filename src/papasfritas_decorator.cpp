/**
 * @file papasfritas_decorator.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/papasfritas_decorator.hpp"

PapasFritasDecorator::PapasFritasDecorator(Combo &decorado)
    : AditionalDecorator(decorado) {
}

const std::string PapasFritasDecorator::name = "papas fritas";

std::string PapasFritasDecorator::getName() {
    return PapasFritasDecorator::name;
}

const float PapasFritasDecorator::value = 1.2;

float PapasFritasDecorator::getValorAgregado() {
    return PapasFritasDecorator::value;
}