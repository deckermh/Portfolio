#include <iostream>
#include <time.h>
#include <vector>

template <typename T>
bool contains(std::vector<T> vec, T val)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == val)
        {
            return true;
        }
    }
    return false;
}

class Simulator
{
    std::vector<int> success = {4, 5};

private:
    int sim(int total)
    {
        int roll = rand() % 6;
        if (!contains(success, roll) || total == 6)
        {
            return total;
        }
        else
        {
            return (sim(total + 1));
        }
    }

public:
    int sim()
    {
        return sim(0);
    }
};

int main()
{
    Simulator s;
    int runs = 10000;
    double total = 0;
    srand(time(NULL));
    for (int i = 0; i < runs; i++) {
        total += s.sim();
    }
    std::cout << total/runs;
}
