#include <iostream>
#include <time.h>
#include <vector>
#include "simulator.h"

void Simulator::printResults(bool testMode, std::vector<int> dice, std::vector<int> countDowns, int finalDiff)
{
    if (testMode)
    {
        std::cout << "dice are: ";
        for (int i = 0; i < dice.size(); i++)
        {
            std::cout << dice[i] << ", ";
        }
        std::cout << "\n";

        std::cout << "countdowns are: ";
        for (int i = 0; i < countDowns.size(); i++)
        {
            std::cout << countDowns[i] << ", ";
        }
        std::cout << "\n";
        std::cout << "finalDiff is: " << finalDiff << "\n";
    }
}

void Simulator::printResults(bool testMode, std::vector<int> dice, std::vector<int> countDowns)
{
    if (testMode)
    {
        std::cout << "dice are: ";
        for (int i = 0; i < dice.size(); i++)
        {
            std::cout << dice[i] << ", ";
        }
        std::cout << "\n";

        std::cout << "countdowns are: ";
        for (int i = 0; i < countDowns.size(); i++)
        {
            std::cout << countDowns[i] << ", ";
        }
    }
}

bool Simulator::zero(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            return false;
        }
    }
    return true;
}

void Simulator::updateCountDowns(std::vector<int> &countDowns, int finalDiff, int finalCountDownIdx)
{
    countDowns[finalCountDownIdx] = finalDiff;
    if (countDowns[finalCountDownIdx] <= 0)
    {
        countDowns.erase(countDowns.begin() + finalCountDownIdx);
    }
}

void Simulator::updateDice(std::vector<int> &dice, int possibleMovesIdx, int bestCountDownIdx, bool noPops)
{
    if (possibleMovesIdx == 0 || possibleMovesIdx == 1 || possibleMovesIdx == 2)
    {
        dice[possibleMovesIdx] = 0;
        if (!noPops)
            dice[possibleMovesIdx] = roll();
    }
    else if (possibleMovesIdx == 3)
    {
        dice[0] = 0;
        dice[1] = 0;
        if (!noPops)
            dice[0] = roll();
    }
    else if (possibleMovesIdx == 4)
    {
        dice[1] = 0;
        dice[2] = 0;
        if (!noPops)
            dice[1] = roll();
    }
    else if (possibleMovesIdx == 5)
    {
        dice[0] = 0;
        dice[2] = 0;
        if (!noPops)
            dice[0] = roll();
    }
    else
    {
        dice = {0, 0, 0};
        if (!noPops)
            dice[0] = roll();
    }
}

int Simulator::roll()
{
    return rand() % 6 + 1;
}

void Simulator::replaceCountDowns(std::vector<int> &countDowns, int total)
{
    for (int i = 0; i < total; i++)
    {
        countDowns.push_back(5);
    }
}

void Simulator::replaceDice(std::vector<int> &dice, int diceNum)
{
    for (int i = 0; i < diceNum; i++)
    {
        dice[i] = roll();
    }
}