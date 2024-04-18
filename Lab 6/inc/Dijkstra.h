#pragma once

#include<vector>

std::vector<int> dijkstra(const std::vector<std::vector<int>>& adjMatrix, std::vector<int>& dist, int start)
{
    const int INF = 1e9;
    const int countNodes = adjMatrix.size();
    dist.resize(countNodes);
    std::fill(dist.begin(), dist.end(), INF);
    std::vector<bool> visited(countNodes);
    std::vector<int> from(countNodes, -1);

    dist[start] = 0;
    for (int i = 0; i < countNodes; ++i)
    {
        int nearest = -1;
        for (int v = 0; v < countNodes; ++v)
        {
            if (!visited[v] && (nearest == -1 || dist[nearest] > dist[v]))
                nearest = v;
        }
        visited[nearest] = true;

        for (int to = 0; to < countNodes; ++to)
        {
            if (adjMatrix[nearest][to] > 0)
            {
                if (dist[to] > dist[nearest] + adjMatrix[nearest][to])
                {
                    dist[to] = dist[nearest] + adjMatrix[nearest][to];
                    from[to] = nearest;
                }
            }
        }
    }
    return from;
}

std::vector<int> getPath(const std::vector<int>& from, int start, int finish)
{
    std::vector<int> path;
    for (int v = finish; v != -1; v = from[v])
        path.push_back(v);
    std::reverse(path.begin(), path.end());
    if (start == finish)
        path.push_back(finish);
    return path;
}

void showPath(const std::vector<int>& path)
{
    for (auto n : path)
        std::cout << n << " ";
}