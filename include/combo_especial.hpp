/**
 * @file combo_especial.hpp
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

#include "combo.hpp"

class ComboEspecial :public Combo{
public:
    virtual std::string getDescripcion() override;
    virtual float getValor() override;

};
