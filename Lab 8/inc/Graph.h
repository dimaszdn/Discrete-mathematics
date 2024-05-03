#pragma once

#include<vector>

class Graph
{
private:
    std::vector<std::vector<int>> adjMatrix;

public:
    explicit Graph(std::vector<std::vector<int>> matrix) : adjMatrix(std::move(matrix))
    {}


};