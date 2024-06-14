/**
 * @file
 * mmaker.cpp
 * @author
 * Pojmaevich
 * Mirko
 * (mirkopoj@gmail.com)
 *         Torletti
 * Lara
 * (lara.a.torletti@gmail.com)
 * @brief
 * menu
 * maker
 * @version
 * 0.1
 * @date
 * 2024-06-13
 *
 * @copyright
 * Copyright
 * (c)
 * 2024
 *
 */
#include "../include/mmaker.hpp"

std::string item::getName() {
    return name;
}

void item::setName(std::string name) {
    this->name = name;
}

void item::display() {
    std::cout.width(y + (name.size()));
    std::cout << name << "  \n";
}

void item::disp_selected() {
    std::cout.width(y + 10);
    std::cout << "\033[31;1;4m--> " << name << "\033[0m     \n";
}

std::string itemCombo::desc() {
    return combo->getDescripcion();
}

float itemCombo::price() {
    return combo->getValor();
}

bool itemCombo::itsaproduct() {
    return combo != nullptr;
}

std::unique_ptr<Combo> itemCombo::getCombo() {
    return move(combo);
}

int item::getY() {
    return y;
}

void item::setY(int y) {
    this->y = y;
}

void itemCombo::print_description() {
    if (itsaproduct()) {
        std::cout << "Descripción del combo:\n\t" << desc();
        std::cout << "\nPrecio del combo: $" << price();
    } else {
        std::cout << "Presione [ENTER] para salir del programa\n";
    }
}

void itemDecorator::print_description() {
    std::cout << "Hola soy un decorator \n";
}

std::unique_ptr<Combo> itemDecorator::getCombo() {
    return nullptr;
}

void menu::add(std::unique_ptr<item> it) {
    entries.push_back(std::move(it));
}

void menu::menu_head(std::string s) {
    head.setName(s);
    return;
}

void menu::preparaDisplay() {
    system("clear");
    int max_y = getmax_y();
    int max_x = getmax_x();
    head.setY((max_y - head.getName().size()) / 2);
    for (std::unique_ptr<item> &a : entries) {
        a->setY((max_y - a->getName().size()) / 2);
    }
    int x = (max_x - entries.size()) / 2 - 2;
    gotoxy(0, 0);
    for (size_t i = 2; i < x; i++) {
        std::cout << "\n";
    }
}

void menu::dibujarEspaciador() {
    std::cout.width(head.getY() + 2 * head.getName().size());
    std::cout << std::string(3 * head.getName().size(), '*') << "\n\n";
}

void menu::dibujarMenu() {
    for (size_t i = 0; i < entries.size(); i++) {
        if (i == selected) {
            entries[i]->disp_selected();
        } else {
            entries[i]->display();
        }
    }
    std::cout << "\n\n\n\n\n\n\n";
}

void menu::describirItem() {
    entries[selected]->print_description();
    std::cout << "\n\n";
}

bool menu::navegarMenu() {
    switch (getch()) {
        case 10:
            return true;
        case 66:
            selected++;
            break;
        case 65:
            selected--;
            break;
    }
    if (selected == entries.size()) {
        selected = 0;
    }
    if (selected == -1) {
        selected = entries.size() - 1;
    }
    return false;
}

std::unique_ptr<Combo> menu::makeSelection() {
    return entries[selected]->getCombo();
}

std::unique_ptr<Combo> menu::display() {
    while (true) {
        preparaDisplay();
        head.display();
        dibujarEspaciador();
        dibujarMenu();
        describirItem();
        if (navegarMenu()) {
            return makeSelection();
        }
    }
}