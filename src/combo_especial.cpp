/**
 * @file combo_especial.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief
 * @version 0.1
 * @date 2024-06-12
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../include/combo_especial.hpp"

std::string ComboEspecial::getDescripcion() {
    return "Triple hamburguesa, mayonesa, ketchup, alioli, queso cheddar, "
           "queso azul, "
           "hongos, panceta, cebolla caramelizada, aros de cebolla rebozados, "
           "rucula, huevo frito, jamon, calabresa, jabali ahumado, batatas "
           "fritas, papas al horno, sandia caramelizada con chori-flan de "
           "postre gaseosa y vino tinto";
}

float ComboEspecial::getValor() {
    return 197.32;
}
