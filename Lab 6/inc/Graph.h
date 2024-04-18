#pragma once

#include<Edge.h>

#include<iomanip>
#include<vector>
#include<algorithm>

typedef std::vector<std::vector<bool>> Matrixnnb;
typedef std::vector<bool> Matrix1b;
typedef std::vector<std::vector<int>> Matrixnni;
typedef std::vector<int> Matrix1i;

class Graph
{
private:
    std::vector<Edge> edges{};
    int countNodes{};
    bool directed{};

public:
    Graph() = default;

    Graph(int countNodes, bool directed)
    {
         this->countNodes = countNodes;
         this->directed = directed;
    }

    ~Graph() = default;

    void addEdge(Edge edge)
    {
        edges.push_back(edge);
    }

    Matrixnni getAdjMatrix()
    {
        Matrixnni adjMatrix(countNodes, Matrix1i(countNodes, 0));
        for (auto edge : edges)
        {
            if (!directed)
            {
                adjMatrix[edge.a][edge.b] = edge.weight; //1
                adjMatrix[edge.b][edge.a] = edge.weight; //1
            }
            else
                adjMatrix[edge.a][edge.b] = edge.weight; //1
        }

        return adjMatrix;
    }

    Matrixnni getIncMatrix()
    {
        Matrixnni incMatrix(countNodes, Matrix1i(edges.size(), 0));
        auto adjMatrix = this->getAdjMatrix();
        int edge = 0;
        for (int i = 0; i < countNodes; ++i)
        {
            for (int j = 0; j < countNodes; ++j)
            {
                if (adjMatrix[i][j] > 0)
                {
                    incMatrix[i][edge] = 1;
                    incMatrix[j][edge] = -1;
                    ++edge;
                }
            }
        }
        return incMatrix;
    }

    //только для ориентированного предусмотрено
    bool isEuler()
    {
        auto adjMatrix = this->getAdjMatrix();
        std::vector<int> in_degree(adjMatrix.size(), 0);
        std::vector<int> out_degree(adjMatrix.size(), 0);

        // Подсчет входящей и исходящей степени для каждой вершины
        for (int i = 0; i < adjMatrix.size(); i++)
        {
            for(int j = 0; j < adjMatrix.size(); j++)
            {
                if(adjMatrix[i][j] > 0)
                {
                    out_degree[i]++;
                    in_degree[j]++;
                }
            }
        }

        for (int i = 0; i < adjMatrix.size(); i++)
            if (in_degree[i] != out_degree[i])
                return false;

        return true;
    }
};

Graph getUndirectedGraph(int countNodes, const std::vector<Edge>& edges)
{
    std::vector<Edge> undirectedEdges;

    for (const Edge& edge : edges)
    {
        Edge reverseEdge(edge.b, edge.a, edge.weight);

        auto it = find_if(undirectedEdges.begin(), undirectedEdges.end(), [&](const Edge& edge) {
            return (edge.a == reverseEdge.a && edge.b == reverseEdge.b);
        });

        if (it != undirectedEdges.end())
            it->weight = (it->weight + reverseEdge.weight) / 2;
        else
            undirectedEdges.push_back(edge);
    }

    sort(undirectedEdges.begin(), undirectedEdges.end(),
         [](const Edge& e1, const Edge& e2)
         {
             if (e1.a != e2.a) {
                 return e1.a < e2.a;
             }
             return e1.b < e2.b;
         });

    Graph graph(countNodes, false);

    for (auto edge : undirectedEdges)
        graph.addEdge(edge);

    return graph;
}

template<typename T>
void showMatrix(const std::vector<std::vector<T>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
            std::cout << std::right << std::setw(4) << matrix[i][j];
        std::cout << "\n";
    }
}