#pragma once

#include<fstream>

struct Edge
{
    int a, b, weight;

    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->weight = c;
    }

    friend std::ostream& operator<<(std::ostream& out, Edge& edge)
    {
        out << edge.a << " " << edge.b << " " << edge.weight;
        return out;
    }
};