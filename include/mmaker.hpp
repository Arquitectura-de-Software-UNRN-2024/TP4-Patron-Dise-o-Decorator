/**
 * @file mmaker.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief menu maker
 * @version 0.1
 * @date 2024-06-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <memory>
#include "func.hpp"
#include "combo.hpp"

using namespace std;

class item{
    string name;
    unique_ptr<Combo> combo;
    int y;

    public:
        item(string s1, Combo * combo):name(s1), combo(combo){}
        string getName();
        void setName(string name);
        void display();
        void disp_selected();
        string desc();
        float price();
        bool itsaproduct();
        unique_ptr<Combo> getCombo();
        int getY();
        void setY(int y);
};

class menu{
    item head = {"",nullptr};
    vector<item> entries = {};
    int selected = 0;
    public:
    void add(string s, Combo * combo);
    void menu_head(string);
    std::unique_ptr<Combo> display();
    void preparaDisplay();
    void dibujarEspaciador();
    void dibujarMenu();
    bool navegarMenu();
};

