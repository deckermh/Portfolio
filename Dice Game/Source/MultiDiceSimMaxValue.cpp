#include <iostream>
#include <time.h>
#include <vector>
#include "MultiDiceSimMaxValue.h"

MaxValueSimulator::MaxValueSimulator() {}

int MaxValueSimulator::simOnce(int diceNum, bool testMode)
{
    if (diceNum <= 3)
    {
        std::vector<int> dice = {0, 0, 0};
        replaceDice(dice, diceNum);
        std::vector<int> countDowns = {5, 5, 5, 5, 5, 5};
        return sim(dice, countDowns, testMode);
    }
    return -1;
}

int MaxValueSimulator::sim(int diceNum, int rounds, bool testMode)
{
    if (diceNum <= 3)
    {
        std::vector<int> dice = {0, 0, 0};
        replaceDice(dice, diceNum);
        std::vector<int> countDowns = {5, 5, 5, 5, 5, 5};
        return sim(dice, countDowns, rounds, diceNum, testMode);
    }
    return -1;
}

int MaxValueSimulator::sim(std::vector<int> dice, std::vector<int> countDowns, bool testMode)
{
    int total = 0;

    while (!zero(dice) && !countDowns.empty())
    {
        findBestMove(countDowns, dice, total, testMode);
    }
    replaceCountDowns(countDowns, total);

    printResults(testMode, dice, countDowns);

    return total;
}

int MaxValueSimulator::sim(std::vector<int> dice, std::vector<int> countDowns, int rounds, int diceNum, bool testMode)
{
    int total = 0;
    int superTotal = 0;
    for (int i = 0; i < rounds; i++)
    {
        while (!zero(dice) && !countDowns.empty())
        {
            findBestMove(countDowns, dice, total, testMode);
        }
        superTotal += total;
        replaceCountDowns(countDowns, total);
        total = 0;
        replaceDice(dice, diceNum);
        if (testMode)
            std::cout << "end of round " << i + 1 << "\n\n";
    }
    return superTotal;
}

void MaxValueSimulator::findBestMove(std::vector<int> &countDowns, std::vector<int> &dice, int &total, bool testMode)
{
    std::vector<int> possibleMoves = {dice[0], dice[1], dice[2],
                                      dice[0] + dice[1], dice[1] + dice[2], dice[0] + dice[2],
                                      dice[0] + dice[1] + dice[2]};

    int bestCountDownIdx = -1;
    int possibleMovesIdx = -1;
    int minDiff = INT_MAX;

    bool subOpt = true;

    int secondBestCountDownIdx = -1;
    int secondBestMovesIdx = -1;
    int minWaste = INT_MIN;

    for (int i = 0; i < countDowns.size(); i++)
    {
        for (int j = 0; j < possibleMoves.size(); j++)
        {
            if (possibleMoves[j] > 0)
            {
                int diff = countDowns[i] - possibleMoves[j];
                if (diff >= 0 && diff < minDiff)
                {
                    minDiff = diff;
                    bestCountDownIdx = i;
                    possibleMovesIdx = j;
                    subOpt = false;
                }
                else if (diff < 0 && diff > minWaste)
                {
                    minWaste = diff;
                    secondBestCountDownIdx = i;
                    secondBestMovesIdx = j;
                }
            }
        }
    }
    int finalDiff = minDiff;
    int finalCountDownIdx = bestCountDownIdx;
    int finalPossibleMovesIdx = possibleMovesIdx;

    if (subOpt)
    {
        finalDiff = minWaste;
        finalCountDownIdx = secondBestCountDownIdx;
        finalPossibleMovesIdx = secondBestMovesIdx;
    }

    if (finalDiff <= 0)
    {
        total++;
    }

    printResults(testMode, dice, countDowns, finalDiff);

    updateCountDowns(countDowns, finalDiff, finalCountDownIdx);
    updateDice(dice, finalPossibleMovesIdx, finalCountDownIdx, finalDiff);
}

double MaxValueSimulator::expectedValue(int diceNum, int rounds)
{
    if (diceNum <= 3 && diceNum > 0)
    {
        MaxValueSimulator s;
        int runs = 10000;
        double total = 0;
        srand(time(NULL));
        for (int i = 0; i < runs; i++)
        {
            total += s.sim(3, rounds, false);
        }
        std::cout << total / runs;
        return total / runs;
    }
    return -1;
}
