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
#include <iostream>
#include <fstream>


SaveData::SaveData() {
    
}
SaveData::SaveData(const SaveData& orig) {
    
}
SaveData::~SaveData() {
    
}
/*
void saveData(){
    std::ifstream inFile;
    inFile.open("statFile.txt");
    
    if (!inFile) {
    std::cerr << "Unable to open file datafile.txt";
    std::exit(-1);   // call system to stop
    
    inFile.close("statFile.txt");
}
*/
