/**
 * @file aditional_decorator.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2024-06-11
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include "combo.hpp"

class AditionalDecorator :public Combo{
public:
    virtual std::string getDescripcion() override;
    virtual float getValor() override;
    virtual std::string getName() = 0;
    virtual float getValorAgregado() = 0;

protected:
    AditionalDecorator(Combo &);

private:
    Combo &combo;
};