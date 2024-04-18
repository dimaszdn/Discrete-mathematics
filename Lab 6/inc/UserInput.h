#pragma once

#include<vector>
#include<sstream>

#include<Edge.h>

std::vector<Edge> getUserInputFromConsole()
{
    std::cout << "¬ведите список рЄбер (начало, конец, вес): " << "\n";
    std::vector<Edge> edges;
    int a, b, weight;
    while (true)
    {
        std::cin >> a >> b >> weight;
        if (a == 0 && b == 0 && weight == 0)
            break;
        edges.emplace_back(a, b, weight);
    }
    return edges;
}

std::vector<Edge> getUserInputFromFile(const std::string& path)
{
    std::vector<Edge> edges;
    std::ifstream fin(path);
    if (!fin.is_open())
        throw std::exception("File opening error");
    else
    {
        std::string triple;
        int a, b, weight;
        std::istringstream iss;
        while (std::getline(fin, triple))
        {
            iss.str(triple);
            if (iss >> a >> b >> weight)
                edges.emplace_back(a, b, weight);
            iss.clear();
        }
    }
    return edges;
}