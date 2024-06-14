/**
 * @file papasfritas_decorator.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-12
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "aditional_decorator.hpp"

class PapasFritasDecorator : public AditionalDecorator {
public:
    PapasFritasDecorator(Combo &decorado);

    virtual std::string getName() override;
    virtual float getValorAgregado() override;

    const static std::string name;
    const static float value;
};