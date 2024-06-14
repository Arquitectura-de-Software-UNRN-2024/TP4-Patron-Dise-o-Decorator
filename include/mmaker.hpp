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
#include "aditional_decorator.hpp"
#include "combo.hpp"
#include "func.hpp"
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class item {
  public:
    item(std::string s1) : name(s1) {
    }
    std::string getName();
    void setName(std::string name);
    void display();
    void disp_selected();
    int getY();
    void setY(int y);
    virtual void print_description() = 0;
    virtual std::unique_ptr<Combo> getCombo() = 0;

  private:
    std::string name;
    int y;
};

class itemHead : public item {
  public:
    itemHead(std::string s) : item(s) {
    }
    virtual void print_description() override {};
    virtual std::unique_ptr<Combo> getCombo() override {
        return nullptr;
    };
};

class itemSalir : public item {
  public:
    itemSalir(std::string s, std::string d) : item(s), desc(d) {
    }
    virtual void print_description() override;
    virtual std::unique_ptr<Combo> getCombo() override {
        return nullptr;
    };

  private:
    std::string desc;
};

class itemCombo : public item {
  public:
    itemCombo(std::string s1, Combo *combo) : item(s1), combo(combo) {
    }
    virtual void print_description() override;
    virtual std::unique_ptr<Combo> getCombo() override;

  private:
    std::unique_ptr<Combo> combo;
};

class itemDecorator : public item {
  public:
    itemDecorator(std::string s1, std::unique_ptr<AditionalDecorator> ad)
        : item(s1), aditional(std::move(ad)) {
    }
    virtual void print_description() override;
    virtual std::unique_ptr<Combo> getCombo() override;

  private:
    std::unique_ptr<AditionalDecorator> aditional;
};

class menu {
  public:
    void add(std::unique_ptr<item> it);
    void menu_head(std::string);
    std::unique_ptr<Combo> display();
    void preparaDisplay();
    void dibujarEspaciador();
    void dibujarMenu();
    void describirItem();
    bool navegarMenu();
    std::unique_ptr<Combo> makeSelection();

  private:
    itemHead head = {""};
    std::vector<std::unique_ptr<item>> entries = {};
    int selected = 0;
};
