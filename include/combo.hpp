/**
 * @file combo.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief combo interface
 * @version 0.1
 * @date 2024-06-11
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <string>

class Combo{
public:
    virtual std::string getDescripcion() = 0;
    virtual float getValor() = 0;
};