#pragma once
#include <vector>

class Game {
    private:
        void updateAcceptedChoices(std::vector<int>&);
    public:
        Game();
        int roll();
        void replaceDice(std::vector<int>&, int);
        void replaceCountdowns(std::vector<int>&);
        void printVector(std::vector<int>);
        void printVector(std::vector<int>, std::string);
        bool contains(std::vector<int>, int);
        int makeChoice(std::vector<int>, std::string);
        void runGame(int);
        void play();
};