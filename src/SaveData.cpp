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

#include "TextFiling.hpp"
#include <iostream>
#include <fstream>


TextFiling::TextFiling() {
    
}
TextFiling::TextFiling(const TextFiling& orig) {
    
}
TextFiling::~TextFiling() {
    
}

void TextFiling::killCount(){
    std::ofstream data;
    data.open("saveData");
    data << "Writing this to a file.\n";
    data.close();
}
