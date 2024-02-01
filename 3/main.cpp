#include <iostream>
#include<vector>

constexpr int N = 15;

void func(std::vector<std::vector<int>>& table)
{
    table[15][0] = 1;
}

void printTable(const std::vector<std::vector<int>>& table)
{
    for (int i = 0; i < table[i].size(); ++i)
    {
        for (int j = 0; j < table[j].size(); ++j)
        {

        }
    }
}

int main()
{
    std::vector<std::vector<int>> table(N * N);

    return 0;
}
