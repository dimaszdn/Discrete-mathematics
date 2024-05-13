#pragma once

#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
#include <iostream>
#include <queue>

#include<RandomValues.h>
#include<Parameters.h>

void printVec(const std::vector<int>& vec)
{
    for (auto el : vec)
        std::cout << el << "\n";
    std::cout << "\n";
}

class Graph
{
private:
    size_t n{};
    std::vector<std::vector<int>> adjMatrix{};
    std::vector<int> degrees{};
    long long itDijkstra{};
    long long itFordBellman{};

public:
    explicit Graph(size_t countNodes) : n(countNodes),
                                adjMatrix(countNodes, std::vector<int>(countNodes)),
                                degrees(countNodes, 0),
                                itDijkstra(0),
                                itFordBellman(0)
    {}

    void fillRandom()
    {
        PRNG generator;
        initGenerator(generator);

        addSubgraphK5(generator);
        linkVertices(generator);
        makeSparse(generator);

        std::cout << "[Graph created!]" << "\n";
    }

    void addSubgraphK5(PRNG& generator)
    {
        std::vector<int> k5;
        //генерируем 5 случайных вершин, которые будем связывать
        while (k5.size() < 5)
        {
            int node = random(generator, 0, n - 1);
            if (std::find(k5.begin(), k5.end(), node) == k5.end())
                k5.push_back(node);
        }

        //увеличиваем степень
        for (auto node : k5)
            degrees[node] += 4;

        //добавляем рёбра
        for (int i = 0; i < k5.size(); ++i)
        {
            for (int j = i + 1; j < k5.size(); ++j)
            {
                adjMatrix[k5[i]][k5[j]] = 1;
                adjMatrix[k5[j]][k5[i]] = 1;
            }
        }
    }

    void linkVertices(PRNG& generator)
    {
        //вектор с индексами всех вершин
        std::vector<int> nodes;
        for (int i = 0; i < n; ++i)
            nodes.push_back(i);

        //перемешиваем индексы
        std::shuffle(nodes.begin(), nodes.end(), generator.engine);

        //затем в случайном порядке связываем все вершины
        int curNode, nextNode;
        for (int i = 0; i < n - 1; ++i)
        {
            curNode = nodes[i];
            nextNode = nodes[i + 1];
            if (!adjMatrix[curNode][nextNode])
            {
                adjMatrix[curNode][nextNode] = 1;
                adjMatrix[nextNode][curNode] = 1;
                degrees[curNode]++;
                degrees[nextNode]++;
            }
        }
    }

    void makeSparse(PRNG& generator)
    {
        int value;
        for (int i = 0; i < n; ++i)
        {
            int degree = random(generator, minDegree, maxDegree);
            for (int j = i; j < n; ++j)
            {
                value = random(generator, 0, 1);
                if (canAddEdge(i, j, degree) && value)
                {
                    adjMatrix[i][j] = value;
                    adjMatrix[j][i] = value;
                    degrees[i]++;
                    degrees[j]++;
                }
            }
        }
    }

    void dijkstra(int start)
    {
        std::ofstream fout("files/dist[" + std::to_string(n) + "d].txt");

        std::vector<int> dist(n, INT_MAX);
        std::vector<bool> visited(n, false);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

        dist[start] = 0;
        pq.push(std::make_pair(0, start));

        while (!pq.empty()) {
            int current = pq.top().second;
            pq.pop();

            if (visited[current])
                continue;

            visited[current] = true;

            for (int neighbor = 0; neighbor < n; neighbor++) {
                if (adjMatrix[current][neighbor] == 1) {
                    int alt = dist[current] + 1;
                    if (alt < dist[neighbor]) {
                        dist[neighbor] = alt;
                        pq.push(std::make_pair(alt, neighbor));
                    }
                }
                itDijkstra++;
            }
        }
        std::cout << "[The distances are calculated!]" << "\n";
        fout << "For node: " << start << "\n";
        for (int i = 0; i < dist.size(); ++i)
            fout << i << ": " << dist[i] << "\n";
        std::cout << "[The output to the file is completed!]" << "\n";
        fout.close();
    }

    void bellmanFord(int start)
    {
        std::ofstream fout("files/dist[" + std::to_string(n) + "fb].txt");

        std::vector<int> dist(n, INT_MAX);
        dist[start] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int u = 0; u < n; u++)
            {
                for (int v = 0; v < n; v++)
                {
                    if (adjMatrix[u][v])
                    {
                        if (dist[u] != INT_MAX && dist[v] > dist[u] + 1)
                            dist[v] = dist[u] + 1;
                    }
                }
            }
        }
        std::cout << "[The distances are calculated!]" << "\n";
        fout << "For node: " << start << "\n";
        for (int i = 0; i < dist.size(); ++i)
            fout << i << ": " << dist[i] << "\n";
        std::cout << "[The output to the file is completed!]" << "\n";
        fout.close();
    }

    long long getItDijkstra()
    {
        return itDijkstra;
    }

public:
    void outputAdjMatrixToConsole()
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                std::cout << std::right << std::setw(5) << adjMatrix[i][j];
            std::cout << "\n";
        }
    }

    void outputToFileAdjMatrix()
    {
        std::string path = "files/graph" + std::to_string(n) + ".txt";
        std::ofstream fout(path);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                fout << adjMatrix[i][j] << " ";
            }
            fout << "\n";
        }
    }

    int getMinDegree()
    {
        return *std::min_element(degrees.begin(), degrees.end());
    }

    bool isSymmetric()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (adjMatrix[i][j] != adjMatrix[j][i])
                    return false;
        return true;
    }

private:
    bool canAddEdge(int u, int v, int randDegree)
    {
        int degreeU = degrees[u];
        int degreeV = degrees[v];

        if (u == v)
            return false;

        if (degreeU >= randDegree || degreeV >= maxDegree)
            return false;

        if (adjMatrix[u][v])
            return false;

        return true;
    }
};
