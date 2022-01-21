#pragma once
#include <iostream>
#include <time.h>
#include <vector>

class Simulator
{
public:
    void printResults(bool, std::vector<int>, std::vector<int>, int);
    void printResults(bool, std::vector<int>, std::vector<int>);
    bool zero(std::vector<int>);
    void updateCountDowns(std::vector<int>&, int, int);
    void updateDice(std::vector<int>&, int, int, bool);
    int roll();
    void replaceCountDowns(std::vector<int>&, int);
    void replaceDice(std::vector<int>&, int);
};