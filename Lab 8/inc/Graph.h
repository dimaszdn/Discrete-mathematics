#pragma once

#include<vector>
#include<queue>
#include<UserInput.h>

struct Edge
{
    int u, v;

    Edge(int u, int v)
    {
        this->u = u;
        this->v = v;
    }

    friend std::ostream& operator<<(std::ostream& out, Edge& edge)
    {
        out << edge.u << " " << edge.v << " ";
        return out;
    }
};

class Graph
{
private:
    std::vector<std::vector<int>> adjMatrix{};
    std::vector<Edge> minCut{};
    int capCut{0};
    size_t n{};

public:
    explicit Graph(std::vector<std::vector<int>> matrix) : adjMatrix(std::move(matrix)),
                                                            n(adjMatrix.size())
    {}

    bool bfs(const std::vector<std::vector<int>>& residualGraph,
             int s, int t, std::vector<int>& parents,
             std::vector<bool>& visited)
    {
//        std::vector<bool> visited(n, false);
        visited.resize(n);
        std::fill(visited.begin(), visited.end(), false);
        std::queue<int> searchQueue;

        searchQueue.push(s);
        visited[s] = true;
        parents[s] = -1;
        while (!searchQueue.empty())
        {
            int curNode = searchQueue.front();
            searchQueue.pop();
            for (int to = 0; to < n; ++to)
            {
                if (residualGraph[curNode][to] > 0 && !visited[to])
                {
                    visited[to] = true;
                    searchQueue.push(to);
                    parents[to] = curNode;
                    if (to == t)
                        return true;
                }
            }
        }
        return false;
    }

    int ford_fulkerson()
    {
        int maxFlow = 0;
        std::vector<int> parents(n);
        std::vector<bool> visited;
        //определили сток и исток
        int s = 0;
        int t = n - 1;
        //инициализируем остаточный граф
        std::vector<std::vector<int>> residualGraph(adjMatrix);

        while(bfs(residualGraph, s, t, parents, visited))
        {
            int flow = INT_MAX;
            //проходим по найденному пути от истока до стока
            //только в обратном направлении
            for (int v = t; v != s; v = parents[v])
            {
                int u = parents[v];
                flow = std::min(flow, residualGraph[u][v]);
            }
            maxFlow += flow;
            //обновляем остаточную пропускную способность рёбер
            for (int v = t; v != s; v = parents[v])
            {
                int u = parents[v];
                residualGraph[u][v] -= flow;
                residualGraph[v][u] += flow;
            }
        }
        //находим минимальный разрез
        //посещенные вершины образуют множество S
        //не посещенные вершины образуют множество T
        bfs(residualGraph, s, t, parents, visited);
        for (int u = 0; u < n; ++u)
        {
            for (int v = 0; v < n; ++v)
            {
                if (adjMatrix[u][v] && visited[u] && !visited[v])
                {
                    minCut.emplace_back(u, v);
                    capCut += adjMatrix[u][v];
                }
            }
        }
        return maxFlow;
    }

    [[nodiscard]] int getCapCut() const
    {
        return capCut;
    }

    std::vector<Edge> getMinCut()
    {
        return minCut;
    }
};