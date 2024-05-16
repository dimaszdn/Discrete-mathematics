#pragma once

long long dijkstraComplexity(int v, int e)
{
    auto complexity = pow(v, 2) + e * log2(v);
    return static_cast<long long>(complexity);
}

long long bellmanFordComplexity(int v)
{
    auto complexity = pow(v, 3);
    return static_cast<long long>(complexity);
}