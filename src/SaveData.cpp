/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextFiling.cpp
 * Author: CJAdams09
 * 
 * Created on December 23, 2017, 10:50 AM
 */

#include "SaveData.hpp"
#include "player/Player.hpp"
#include <iostream>
#include <fstream>
#include <string>


SaveData::SaveData() {
    
}
SaveData::SaveData(const SaveData& orig) {
    
}
SaveData::~SaveData() {
    
}

void Player::writeData(std::ostream &saveData,Item items[]){
    saveData << std::distance(items, std::find(items, items + 26, *equipment.head))
            << "," << std::distance(items, std::find(items, items + 26, *equipment.hand))
            << "," <<std::distance(items, std::find(items, items + 26, *equipment.chest)) 
            << "," <<std::distance(items, std::find(items, items + 26, *equipment.pocket1))
            << "," << std::endl;
            saveData.flush();
}

Player::Player(std::istream& saveData,Item items[]){ 
    char s[3];
    saveData.getline(s,3,',');
    if(s[0] =='\0'){
        std::cerr << "***no file to read** AHHHHHHHHHHHHH UUUUGGGGGGHHHHHH*";
    }
    equipment.head = &items[std::stoi(s)];
    std::cout << s;
    saveData.getline(s,3,',');
    equipment.hand = &items[std::stoi(s)];
    std::cout << s;
    saveData.getline(s,3,',');
    equipment.chest = &items[std::stoi(s)];
    std::cout << s;
    saveData.getline(s,3,',');
    equipment.pocket1 = &items[std::stoi(s)];
    std::cout << s;
}