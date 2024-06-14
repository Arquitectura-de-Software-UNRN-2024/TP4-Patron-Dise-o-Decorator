/**
 * @file mmaker.cpp
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

class item
{
        string name;
        unique_ptr<Combo> combo;
        int y;

    public:
        item(string s1, Combo * combo):name(s1), combo(combo)
        {        }
        string getName(){
            return name;
        }
        void setName(string name){
            this->name = name;
        }
        void display();
        void disp_selected();
        string desc(){
            return combo->getDescripcion();
        }
        float price(){
            return combo->getValor();
        }
        bool itsaproduct(){
            return combo != nullptr;
        }
        unique_ptr<Combo> getCombo(){
            return move(combo);
        }
        int getY(){
            return y;
        }
        void setY(int y){
            this->y = y;
        }
};
void item::display()
{
   cout.width(y + (name.size()));
   cout<<name<<"  \n";
}

void item::disp_selected()
{
    cout.width(y+10);
    cout<<"\033[31;1;4m--> " << name <<"\033[0m     \n";

}

class menu
{
    item head = {"",nullptr};
    vector<item> entries = {};
    int num = 0;
    public:
    void add(string s, Combo * combo);
    void menu_head(string);
    std::unique_ptr<Combo> display();
};


void menu::add(string s, Combo * combo)
{
    num++;
    entries.push_back(item(s, combo));
}

void menu::menu_head(string s)
{
    head.setName(s);
    return;
}

std::unique_ptr<Combo> menu::display()
{
    
    int selected = 0, opt=66, last_x = getmax_x(), last_y = getmax_y();
    while(true)
    {
        system("clear");
        int max_y = getmax_y(), i;
		head.setY((max_y - head.getName().size())/2);
        for(item &a : entries)
        {
            a.setY((max_y - a.getName().size())/2);
        }
        int max_x = getmax_x();
        if (!(max_x == last_x && max_y == last_y))
        {
            system("clear");
            last_x = max_x;
            last_y = max_y;
        }
        int x = (max_x - num)/2 - 2;
        gotoxy(0, 0);
        //printf("\033[%d;%dH", 0, 0);
        for(i =2; i<x; i++)
            cout<<endl;
        //cout.width(head.y);
        head.display();
        cout.width(head.getY()+2*head.getName().size());
        cout << string(3*head.getName().size(), '*');
        //cout << "**********";
		cout<<"\n\n";
        for(i=0;i<(int)entries.size();i++)
        {
            if ( i == selected)
                entries[i].disp_selected();
            else
                entries[i].display();
        }
        cout << "\n\n\n\n\n\n\n";
       
        if (entries[selected].itsaproduct()){
            cout << "Descripción del combo:\n\t" << entries[selected].desc() << "\n";
            cout << "Precio del combo: $" << entries[selected].price() << "\n"; 
        } else {
            cout << "Presione [ENTER] para salir del programa\n\n";
        }
        int previous = (opt==66)?(selected-1):(selected+1);
        if (previous < 0)
            previous = num-1;
        if(previous == num)
            previous = 0;
        //int temp = entries[previous].itsaproduct()? (entries[previous].desc().length() - entries[selected].desc().length()): ;
        //for(int i=0;i<temp;i++)
        //    cout << " ";
        cout<<'\n';
        opt = getch();
        if (opt == 10)
            return entries[selected].getCombo();
        switch(opt)
        {
            case 66:
                selected++;
                break;
            case 65:
                selected--;
                break;
        }
        if(selected == num)
            selected = 0;
        if(selected == -1)
            selected = num -1;
    }
}