/**
 * @file aditional_decorator.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "../include/aditional_decorator.hpp"

AditionalDecorator::AditionalDecorator(Combo &decorado)
:combo(decorado)
{}


std::string AditionalDecorator::getDescripcion(){
    return combo.getDescripcion() + " + " + getName();
}

float AditionalDecorator::getValor(){
    return combo.getValor() + getValorAgregado();
}