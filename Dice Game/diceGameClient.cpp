#include <iostream>
#include <vector>
#include "./Source/diceGame.h"
#include "./Source/diceGame.cpp"
#include "./Source/simulator.h"
#include "./Source/simulator.cpp"
#include "./Source/MultiDiceSimGreedy.h"
#include "./Source/MultiDiceSimGreedy.cpp"
#include "./Source/MultiDiceSimMaxValue.h"
#include "./Source/MultiDiceSimMaxValue.cpp"

int main()
{
    Game g;
    std::vector<int> acceptedChoices = {0, 1};
    std::cout << "Select a mode: \n";
    std::cout << " --------- \n";
    std::cout << "| 0: Play | \n";
    std::cout << " --------- \n\n";
    std::cout << " ------------- \n";
    std::cout << "| 1: Simulate | \n";
    std::cout << " ------------- \n\n";
    int choice = g.makeChoice(acceptedChoices, "mode");

    if (choice == 0)
    {
        g.play();
    }
    else if (choice == 1)
    {
        std::cout << "Which approach would you like to test? \n";
        std::cout << "The greedy algorithm maximizes the number of countdowns destroyed in the current round, \n";
        std::cout << "with no regard for future rounds. \n";
        std::cout << "The max value algorithm attempts to minimize waste when using dice, getting the most\n";
        std::cout << "value out of each one. \n\n";

        std::vector<int> sampleDice = {2, 4};
        std::vector<int> sampleCtdwn = {5,5,5};
        std::cout << "For instance, consider the following situation: we have two dice left, \n";
        g.printVector(sampleDice);
        std::cout << "with countdowns\n";
        g.printVector(sampleCtdwn);        
        std::cout << "The greedy algorithm would combine the 2 and the 4 to form 6 and knock out a countdown. \n";
        std::cout << "However, using a 6 when we only need 5 is a bit wasteful. So, the max value algorithm would \n";
        std::cout << "instead use the 4 on the first countdown, and the 2 on the second to minimize waste. \n";
        std::cout << "Which algorithm would you like to simulate?\n\n";

        std::cout << " ----------- \n";
        std::cout << "| 0: Greedy | \n";
        std::cout << " ----------- \n\n";
        std::cout << " -------------- \n";
        std::cout << "| 1: Max Value | \n";
        std::cout << " -------------- \n\n";

        int choice = g.makeChoice(acceptedChoices, "algorithm");

        if (choice == 0) {
            GreedySimulator s;//MAKE THIS ITS OWN METHOD SO YOU DONT COPY CODE
            int rounds = -1;
            std::cout << "How many rounds would you like to simulate?\n";
            std::cin >> rounds;

            std::cout << "The expected number of countdowns destroyed for " << rounds << " rounds was approximately: ";
            s.expectedValue(3, rounds);
        }
        else if (choice == 1) {
            MaxValueSimulator s;
            int rounds = -1;
            std::cout << "How many rounds would you like to simulate?\n";
            std::cin >> rounds;

            std::cout << "The expected number of countdowns destroyed for " << rounds << " rounds was approximately: ";
            s.expectedValue(3, rounds);
        }
    }
}