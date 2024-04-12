#pragma once


#include<UserInput.h>
#include<Edge.h>

class Graph
{
private:
    std::vector<Edge> edges{};

public:
    Graph()
    {
        edges = getUserInputFromConsole();
    }

    explicit Graph(const std::string& path)
    {
        edges = getUserInputFromFile(path);
    }

    std::vector<std::vector<bool>> getAdjMatrix()
    {
        std::vector<std::vector<bool>> adjMatrix(edges.size());

    }

    void adjMatrixToIncMatrix()
    {

    }
};