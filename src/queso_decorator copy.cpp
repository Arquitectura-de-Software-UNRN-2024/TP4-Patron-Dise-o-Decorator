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

QuesoDecorator::QuesoDecorator(Combo &decorado)
:AditionalDecorator(decorado)
{}

std::string QuesoDecorator::getDescripcion(){
    return AditionalDecorator::getDescripcion()+" + queso";
}

float QuesoDecorator::getValor(){
    return AditionalDecorator::getValor()+0.80;
}
