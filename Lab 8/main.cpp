#include <iostream>

#include <UserInput.h>
#include<Graph.h>
#include <RandomValues.h>

void info(Graph& graph)
{
    std::cout << "������������ �����: " << graph.ford_fulkerson() << "\n";
    std::cout << "и���, �� ������� ������������ ����������� ������: " << "\n";
    auto cut = graph.getMinCut();
    for (auto edge : cut)
        std::cout << edge << "\n";
    std::cout << "�������� �������: " << graph.getCapCut();
}

int main()
{
    setlocale(LC_ALL, "RUS");
    try
    {
        auto adjMatrix = getMatrixFromFile("files/input.txt");
        Graph graph(adjMatrix);
        std::cout << "\t\t" << "��� ��������� �����: " << "\n";
        info(graph);

        std::cout << "\n\n";

        std::cout << "\t\t" << "��� ����� �� ���������� ����������� �������������: " << "\n";
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