/**
 * @file test_decorator.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief Test para decorator
 * @version 0.1
 * @date 2024-06-11
 *
 * @copyright Copyright (c) 2024
 *
 */
#include <criterion/criterion.h>
#include "../../include/combo_basico.hpp"
#include "../../include/tomate_decorator.hpp"


Test(descripcion_simple, test) {
    std::unique_ptr<Combo> combo(new ComboBasico());
    std::unique_ptr<Combo> combo_decorado(new TomateDecorator(*combo));
    std::string esperado = "Hamburguesa, mayonesa, queso, papas fritas, gaseosa + tomate";
    std::string obtenido = combo_decorado->getDescripcion();
    cr_assert_eq(esperado, obtenido);
}

Test(valor_simple, test) {
    std::unique_ptr<Combo> combo(new ComboBasico());
    std::unique_ptr<Combo> combo_decorado(new TomateDecorator(*combo));
    float esperado = 10.5;
    float obtenido = combo_decorado->getValor();
    cr_assert_eq(esperado, obtenido);
}
