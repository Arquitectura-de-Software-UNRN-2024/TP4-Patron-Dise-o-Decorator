/**
 * @file main.cpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief main de sistema de pedidos
 * @version 0.1
 * @date 2024-06-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#include "../../include/carne_decorator.hpp"
#include "../../include/combo_basico.hpp"
#include "../../include/combo_especial.hpp"
#include "../../include/combo_familiar.hpp"
#include "../../include/mmaker.hpp"
#include "../../include/papasfritas_decorator.hpp"
#include "../../include/queso_decorator.hpp"
#include "../../include/tomate_decorator.hpp"
#include <iomanip>
#include <iostream>

std::unique_ptr<Combo> mostrarMenuCombos() {
    menu obj;
    obj.menu_head("Bienvenido al Sistema de Pedidos");
    obj.add(std::unique_ptr<item>(
        new itemCombo("Combo Básico", new ComboBasico())));
    obj.add(std::unique_ptr<item>(
        new itemCombo("Combo Familiar", new ComboFamiliar())));
    obj.add(std::unique_ptr<item>(
        new itemCombo("Combo Especial", new ComboEspecial())));
    obj.add(std::unique_ptr<item>(
        new itemSalir("Salir", "Presione [ENTER] para salir del programa")));
    return obj.display();
}

std::vector<std::unique_ptr<Combo>>
mostrarMenuAdicionales(std::unique_ptr<Combo> combo_elegido) {
    std::vector<std::unique_ptr<Combo>> propietario_de_la_memoria;
    propietario_de_la_memoria.push_back(std::move(combo_elegido));
    std::unique_ptr<Combo> combo_decorado = nullptr;
    bool salir;
    do {
        menu obj;
        obj.menu_head("¿Deseea agregar adicionales?");
        obj.add(std::unique_ptr<item>(new itemDecorator(
            "Tomate", std::unique_ptr<AditionalDecorator>(new TomateDecorator(
                          *propietario_de_la_memoria.back())))));
        obj.add(std::unique_ptr<item>(new itemDecorator(
            "Papas",
            std::unique_ptr<AditionalDecorator>(
                new PapasFritasDecorator(*propietario_de_la_memoria.back())))));
        obj.add(std::unique_ptr<item>(new itemDecorator(
            "Carne", std::unique_ptr<AditionalDecorator>(new CarneDecorator(
                         *propietario_de_la_memoria.back())))));
        obj.add(std::unique_ptr<item>(new itemDecorator(
            "Queso", std::unique_ptr<AditionalDecorator>(new QuesoDecorator(
                         *propietario_de_la_memoria.back())))));
        obj.add(std::unique_ptr<item>(
            new itemSalir("No deseo agregar más adicionales",
                          "Presione [ENTER] para imprimir ticket")));

        combo_decorado = obj.display();
        salir = true;
        if (combo_decorado) {
            propietario_de_la_memoria.push_back(std::move(combo_decorado));
            salir = false;
        }

    } while (!salir);
    return propietario_de_la_memoria;
}

int main() {
    std::unique_ptr<Combo> combo_elegido = mostrarMenuCombos();
    if (combo_elegido) {
        std::vector<std::unique_ptr<Combo>> propietario_de_la_memoria =
            mostrarMenuAdicionales(std::move(combo_elegido));
        combo_elegido = std::move(propietario_de_la_memoria.back());
        std::cout << "Descripión del combo total:\n\t"
                  << combo_elegido->getDescripcion();
        std::cout << "\nPrecio total:\n\t$" << combo_elegido->getValor();
    }
    std::cout << "\n\nGracias por su visita!!\n";
    return 0;
}
