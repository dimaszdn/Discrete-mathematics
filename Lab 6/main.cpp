#include <iostream>

#include<Graph.h>
#include<UserInput.h>
#include<Dijkstra.h>

int main()
{
    try
    {
        setlocale(LC_ALL, "Rus");

        //�������� ������ ����
//        auto edges = getUserInputFromFile("files/input.txt");
        auto edges = getUserInputFromConsole();

        //��������� ����
        Graph graph(8, true);
        for (auto edge : edges)
            graph.addEdge(edge);

        //�������� ������� ��������� �����
        auto adjMatrix = graph.getAdjMatrix();
        std::cout << "������� ���������: " << "\n";
        showMatrix(adjMatrix);

        std::cout << "\n\n";

        //��������� ������� ��������� � ������� �������������
        auto incMatrix = graph.getIncMatrix();
        std::cout << "������� �������������: " << "\n";
        showMatrix(incMatrix);

        std::cout << "\n\n";

        //��������� �������� �� ���� ���������
        bool euler = graph.isEuler();
        if (euler)
            std::cout << "���� �������� ���������" << "\n";
        else
            std::cout << "���� �� �������� ���������" << "\n";

        std::cout << "\n\n";


        //��������� ����������������� ����
        Graph undirGraph = getUndirectedGraph(8, edges);
        auto unAdjMatrix = undirGraph.getAdjMatrix();
        std::cout << "������� ��������� ������������������ �����: " << "\n";
        showMatrix(unAdjMatrix);

        std::cout << "\n\n";

        std::cout << "������������ ���������� ����" << "\n";
        std::vector<int> path;
        std::vector<int> from;
        std::vector<int> dist;
        for (int i = 0; i < 8; ++i)
        {
            from = dijkstra(unAdjMatrix, dist, i);
            std::cout << "��� ������� " << i << ":" << "\n";
            for (int j = 0; j < 8; ++j)
            {
                showPath(getPath(from,i, j));
                std::cout << "[" << dist[j] << "]" << "\n";
            }
            std::cout << "\n";
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}
