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

CarneDecorator::CarneDecorator(Combo &decorado)
:AditionalDecorator(decorado)
{}

std::string CarneDecorator::getDescripcion(){
    return AditionalDecorator::getDescripcion()+" + hamburguesa";
}

float CarneDecorator::getValor(){
    return AditionalDecorator::getValor()+1.0;
}
