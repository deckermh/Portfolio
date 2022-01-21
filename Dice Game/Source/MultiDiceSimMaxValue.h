#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include "simulator.h"

class MaxValueSimulator : public Simulator
{
private:
    int sim(std::vector<int>, std::vector<int>, bool);
    int sim(std::vector<int>, std::vector<int>, int, int, bool);
    void findBestMove(std::vector<int> &, std::vector<int> &, int &, bool);

public:
    MaxValueSimulator();
    int simOnce(int, bool);
    int sim(int, int, bool);
    double expectedValue(int, int);
};