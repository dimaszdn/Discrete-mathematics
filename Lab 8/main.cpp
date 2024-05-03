#include <iostream>

#include<UserInput.h>
#include<Graph.h>

int main()
{
    try
    {
        auto adjMatrix = getMatrixFromFile("files/input.txt");
        Graph graph(adjMatrix);

    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}