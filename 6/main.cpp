#include <iostream>
#include<vector>

constexpr int N = 15;

int totalCountOfPaths(std::vector<std::vector<int>> table)
{
    for (int i = 1; i < N + 1; ++i)
        for (int j = 1; j < N + 1; ++j)
            table[i][j] = table[i][j - 1] + table[i - 1][j];
    return table[N][N];
}

int main()
{
    std::vector<std::vector<int>> table((N + 1), std::vector<int>(N + 1, 1));

    std::cout << totalCountOfPaths(table) << "\n";

    return 0;
}
