#include <iostream>
#include<vector>

constexpr int N = 15;

void showVec(const std::vector<std::vector<int>>& v)
{
    for (int i = 0; i < N + 1; ++i)
    {
        for (int j = 0; j < N + 1; ++j)
        {
            std::cout << v[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main()
{
    std::vector<std::vector<int>> table((N + 1), std::vector<int>(N + 1, 1));

    for (int i = N - 1; i >= 0; --i)
        for (int j = 1; j < N + 1; ++j)
            table[i][j] = table[i][j - 1] + table[i + 1][j];
    std::cout << table[0][N];
    return 0;
}
