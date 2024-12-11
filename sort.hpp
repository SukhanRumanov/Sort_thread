#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h> 


void sort1(std::vector<int>& vec);
void sort2(std::vector<int>& vec);


struct ThreadArg
{
    std::vector<int>* vec;
};


