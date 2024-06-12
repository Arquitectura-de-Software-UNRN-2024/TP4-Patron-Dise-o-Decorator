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

std::string PapasFritasDecorator::getDescripcion() {
    return AditionalDecorator::getDescripcion() + " + papas fritas";
}

float PapasFritasDecorator::getValor() {
    return AditionalDecorator::getValor() + 1.20;
}
