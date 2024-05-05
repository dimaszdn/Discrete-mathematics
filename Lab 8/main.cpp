#include <iostream>

#include <UserInput.h>
#include<Graph.h>
#include <RandomValues.h>

void info(Graph& graph)
{
    std::cout << "Максимальный поток: " << graph.ford_fulkerson() << "\n";
    std::cout << "Рёбра, по которым производится минимальный разрез: " << "\n";
    auto cut = graph.getMinCut();
    for (auto edge : cut)
        std::cout << edge << "\n";
    std::cout << "Величина разреза: " << graph.getCapCut();
}

int main()
{
    setlocale(LC_ALL, "RUS");
    try
    {
        auto adjMatrix = getMatrixFromFile("files/input.txt");
        Graph graph(adjMatrix);
        std::cout << "\t\t" << "Для исходного графа: " << "\n";
        info(graph);

        std::cout << "\n\n";

        std::cout << "\t\t" << "Для графа со случайными пропускными способностями: " << "\n";
        auto newAdjMatrix = randomThroughput(adjMatrix, 100, 1000);
        Graph newGraph(newAdjMatrix);
        info(newGraph);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}