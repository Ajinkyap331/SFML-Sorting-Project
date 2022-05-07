#ifndef MY_GLOBALS_H
#define MY_GLOBALS_H

#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include <chrono>
#include <thread>
using namespace std;


extern vector <int> arr;
extern sf::RenderWindow window;
extern sf::RectangleShape getData(int, int);
extern void bubbleSort();
extern void quickSort(int, int);


#endif