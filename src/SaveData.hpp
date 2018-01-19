/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SaveData.hpp
 * Author: CJAdams09
 *
 * Created on January 11, 2018, 10:16 AM
 */

#ifndef SAVEDATA_H
#define SAVEDATA_H

#include <SFML/Graphics.hpp>
#include <stdlib.h>


class SaveData {
public:
    SaveData();
    SaveData(const SaveData&);
    virtual ~SaveData();
    
    void saveData();
};

    



#endif /* SAVEDATA_HPP */

