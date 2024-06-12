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
#include "../../include/carne_decorator.hpp"
#include "../../include/combo_basico.hpp"
#include "../../include/combo_especial.hpp"
#include "../../include/combo_familiar.hpp"
#include "../../include/papasfritas_decorator.hpp"
#include "../../include/queso_decorator.hpp"
#include "../../include/tomate_decorator.hpp"
#include <criterion/criterion.h>

Test(descripcion_simple, test) {
    std::unique_ptr<Combo> combo(new ComboBasico());
    std::unique_ptr<Combo> combo_decorado(new TomateDecorator(*combo));
    std::string esperado =
        "Hamburguesa, mayonesa, queso, papas fritas, gaseosa + tomate";
    std::string obtenido = combo_decorado->getDescripcion();
    cr_assert_eq(esperado, obtenido);
}

Test(valor_simple, test) {
    std::unique_ptr<Combo> combo(new ComboBasico());
    std::unique_ptr<Combo> combo_decorado(new TomateDecorator(*combo));
    float esperado = 10.5;
    float obtenido = combo_decorado->getValor();
    cr_assert_float_eq(esperado, obtenido, 0.001);
}

Test(descripcion_doble, test) {
    std::unique_ptr<Combo> combo(new ComboFamiliar());
    std::unique_ptr<Combo> combo2(new QuesoDecorator(*combo));
    std::unique_ptr<Combo> combo_decorado(new CarneDecorator(*combo2));
    std::string esperado =
        "Dos hamburguesa con mayonesa y queso, dos papas fritas y dos "
        "gaseosas + queso + hamburguesa";
    std::string obtenido = combo_decorado->getDescripcion();
    cr_assert_eq(esperado, obtenido);
}

Test(valor_doble, test) {
    std::unique_ptr<Combo> combo(new ComboFamiliar());
    std::unique_ptr<Combo> combo2(new QuesoDecorator(*combo));
    std::unique_ptr<Combo> combo_decorado(new CarneDecorator(*combo2));
    float esperado = 19.8;
    float obtenido = combo_decorado->getValor();
    cr_assert_float_eq(esperado, obtenido, 0.001);
}

Test(descripcion_completo, test) {
    std::unique_ptr<Combo> combo(new ComboEspecial());
    std::unique_ptr<Combo> combo2(new QuesoDecorator(*combo));
    std::unique_ptr<Combo> combo3(new TomateDecorator(*combo2));
    std::unique_ptr<Combo> combo4(new PapasFritasDecorator(*combo3));
    std::unique_ptr<Combo> combo5(new QuesoDecorator(*combo4));
    std::unique_ptr<Combo> combo_decorado(new CarneDecorator(*combo5));
    std::string esperado =
        "Triple hamburguesa, mayonesa, ketchup, alioli, queso cheddar, "
        "queso azul, "
        "hongos, panceta, cebolla caramelizada, aros de cebolla rebozados, "
        "rucula, huevo frito, jamon, calabresa, jabali ahumado, batatas "
        "fritas, papas al horno, sandia caramelizada con chori-flan de "
        "postre gaseosa y vino tinto + queso + tomate + papas fritas + queso + "
        "hamburguesa";
    std::string obtenido = combo_decorado->getDescripcion();
    cr_assert_eq(esperado, obtenido);
}

Test(valor_completo, test) {
    std::unique_ptr<Combo> combo(new ComboEspecial());
    std::unique_ptr<Combo> combo2(new QuesoDecorator(*combo));
    std::unique_ptr<Combo> combo3(new TomateDecorator(*combo2));
    std::unique_ptr<Combo> combo4(new PapasFritasDecorator(*combo3));
    std::unique_ptr<Combo> combo5(new QuesoDecorator(*combo4));
    std::unique_ptr<Combo> combo_decorado(new CarneDecorator(*combo5));
    float esperado = 201.62;
    float obtenido = combo_decorado->getValor();
    cr_assert_float_eq(esperado, obtenido, 0.001);
}
