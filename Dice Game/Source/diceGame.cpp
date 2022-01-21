#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include "diceGame.h"

Game::Game()
{
}

int Game::roll()
{
    return rand() % 6 + 1;
}

void Game::replaceDice(std::vector<int> &dice, int diceNum)
{
    for (int i = 0; i < diceNum; i++)
    {
        dice[i] = roll();
    }
}

void Game::replaceCountdowns(std::vector<int> &countdowns)
{
    while (countdowns.size() < 6)
    {
        countdowns.push_back(5);
    }
}

void Game::printVector(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << "---  ";
    }
    std::cout << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << "|" << v[i] << "|  ";
    }
    std::cout << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << "---  ";
    }
    std::cout << "\n";
}

void Game::printVector(std::vector<int> v, std::string name)
{
    std::cout << "Your " << name << " are: \n";

    for (int i = 0; i < v.size(); i++)
    {
        std::cout << "---  ";
    }
    std::cout << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << "|" << v[i] << "|  ";
    }
    std::cout << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << "---  ";
    }
    std::cout << "\n";
}

bool Game::contains(std::vector<int> v, int e)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == e)
        {
            return true;
        }
    }
    return false;
}

int Game::makeChoice(std::vector<int> acceptedChoices, std::string name)
{
    int playerChoice;
    do
    {
        std::cout << "Select " << name << ".\n";
        std::cin >> playerChoice;
        if (contains(acceptedChoices, playerChoice))
        {
            std::cout << "You selected " << playerChoice << ".\n\n\n";
        }
        else
        {
            std::cout << "Invalid selection.\n";
        }
    } while (!contains(acceptedChoices, playerChoice));
    return playerChoice;
}

void Game::updateAcceptedChoices(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = i;
    }
}

void Game::runGame(int rounds)
{
    std::vector<int> countdowns = {5, 5, 5, 5, 5, 5};
    for (int i = 0; i < rounds; i++)
    {
        std::vector<int> dice(3);
        replaceDice(dice, 3);
        replaceCountdowns(countdowns);

        std::vector<int> acceptedDiceChoices(dice.size());
        std::vector<int> acceptedCtdwnChoices(countdowns.size());
        updateAcceptedChoices(acceptedDiceChoices);
        updateAcceptedChoices(acceptedCtdwnChoices);

        while (!dice.empty() && !countdowns.empty())
        {
            acceptedDiceChoices.resize(dice.size());
            updateAcceptedChoices(acceptedDiceChoices);
            acceptedCtdwnChoices.resize(countdowns.size());
            updateAcceptedChoices(acceptedCtdwnChoices);

            printVector(dice, "dice");
            printVector(countdowns, "countdowns");

            int diceIdx = makeChoice(acceptedDiceChoices, "die");
            int ctdwnIdx = makeChoice(acceptedCtdwnChoices, "countdown");

            countdowns[ctdwnIdx] -= dice[diceIdx];
            dice.erase(dice.begin() + diceIdx);

            if (countdowns[ctdwnIdx] <= 0)
            {
                countdowns.erase(countdowns.begin() + ctdwnIdx);
                dice.push_back(roll());
            }
        }
    }
}

void Game::play()
{
    srand(time(NULL));
    std::cout << "How many rounds would you like to play?\n";
    int rounds;
    std::cin >> rounds;
    runGame(rounds);
}