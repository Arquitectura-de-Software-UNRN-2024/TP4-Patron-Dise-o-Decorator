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

#include<iostream>
#include <iomanip>
#include "../../include/mmaker.hpp"
#include "../../include/combo_basico.hpp"
#include "../../include/combo_familiar.hpp"
#include "../../include/combo_especial.hpp"
#include "../../include/papasfritas_decorator.hpp"
#include "../../include/queso_decorator.hpp"
#include "../../include/tomate_decorator.hpp"
#include "../../include/carne_decorator.hpp"


std::unique_ptr<Combo> mostrarMenuCombos() {
 	menu obj;
    obj.menu_head("Bienvenido al Sistema de Pedidos");
    obj.add("Combo Básico", new ComboBasico());
    obj.add("Combo Familiar", new ComboFamiliar());
    obj.add("Combo Especial", new ComboEspecial());
   	obj.add("Salir", nullptr);
	return obj.display();
}

std::unique_ptr<Combo> mostrarMenuAdicionales(std::unique_ptr<Combo> combo_elegido){
	menu obj;
    obj.menu_head("¿Deseea agregar adicionales?");
    obj.add("Tomate", nullptr);
    obj.add("Ninguno", nullptr);
	return obj.display();
}

int main() {
	std::unique_ptr<Combo> combo_elegido = mostrarMenuCombos();
	if (combo_elegido){
		mostrarMenuAdicionales(std::move(combo_elegido));
	}
	std::cout << "Gracias por su visita!!\n";
	return 0;
}
