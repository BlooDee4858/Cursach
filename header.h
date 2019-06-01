//
// Created by Sasha on 01.06.2019.
//

#ifndef CURSACH_HEADER_H
#define CURSACH_HEADER_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;



int IsChecker(int ip,int jp,int map[8][8]);
void Step(int step[],int map[8][8],int * s);
int kill(int map[8][8], int step[4], int* s);
int KillCheck(int map[8][8], int s);

#endif //CURSACH_HEADER_H
