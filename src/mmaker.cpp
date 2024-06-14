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
#include "../include/mmaker.hpp"

string item::getName(){
    return name;
}

void item::setName(string name){
    this->name = name;
}

void item::display(){
   cout.width(y + (name.size()));
   cout<<name<<"  \n";
}
 
void item::disp_selected()
{
    cout.width(y+10);
    cout<<"\033[31;1;4m--> " << name <<"\033[0m     \n";

}

string item::desc(){
    return combo->getDescripcion();
}

float item::price(){
    return combo->getValor();
}

bool item::itsaproduct(){
    return combo != nullptr;
}

unique_ptr<Combo> item::getCombo(){
    return move(combo);
}

int item::getY(){
    return y;
}

void item::setY(int y){
    this->y = y;
}

void menu::add(string s, Combo * combo)
{
    entries.push_back(item(s, combo));
}

void menu::menu_head(string s)
{
    head.setName(s);
    return;
}

void menu::preparaDisplay(){
    system("clear");
    int max_y = getmax_y();
    int max_x = getmax_x();
	head.setY((max_y - head.getName().size())/2);
    for(item &a : entries){
        a.setY((max_y - a.getName().size())/2);
    }
    int x = (max_x - entries.size())/2 - 2;
    gotoxy(0, 0);
    for(size_t i =2; i<x; i++){
        cout<<endl;
    }
}

void menu::dibujarEspaciador(){
    cout.width(head.getY()+2*head.getName().size());
    cout << string(3*head.getName().size(), '*') << "\n\n"; 
}

void menu::dibujarMenu(){
    for(size_t i=0;i<entries.size();i++){
        if ( i == selected){
            entries[i].disp_selected();
        }else{
                entries[i].display();}
    }
    cout << "\n\n\n\n\n\n\n";
}

bool menu::navegarMenu(){
    switch(getch()){
        case 10:
            return true;
        case 66:
            selected++;
            break;
        case 65:
            selected--;
            break;
    }
    if(selected == entries.size()){
        selected = 0;}
    if(selected == -1){
        selected = entries.size() -1;}
    return false;
}

std::unique_ptr<Combo> menu::display(){
    
    while(true){
        preparaDisplay();
        head.display();
        dibujarEspaciador();
        dibujarMenu();

        if (entries[selected].itsaproduct()){
            cout << "Descripción del combo:\n\t" << entries[selected].desc() << "\n";
            cout << "Precio del combo: $" << entries[selected].price() << "\n"; 
        } else {
            cout << "Presione [ENTER] para salir del programa\n\n";
        }
        cout<<'\n';
        if(navegarMenu){return entries[selected].getCombo();}
    }
}