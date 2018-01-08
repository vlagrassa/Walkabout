/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TextFiling.hpp
 * Author: CJAdams09
 *
 * Created on December 23, 2017, 10:50 AM
 */


#ifndef TEXTFILING_HPP
#define TEXTFILING_HPP



#include <iostream>
#include <fstream>

class TextFiling {
public:
    TextFiling();
    TextFiling(const TextFiling& orig);
    virtual ~TextFiling();
    
    void killCount();
};

#endif /* TEXTFILING_HPP */