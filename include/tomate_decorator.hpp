/**
 * @file tomate_decorator.hpp
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

class TomateDecorator : public AditionalDecorator {
public:
    TomateDecorator(Combo &decorado);

    virtual std::string getDescripcion() override;
    virtual float getValor() override;
};