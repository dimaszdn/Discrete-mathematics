#include <iostream>

#include<Graph.h>
#include<UserInput.h>
#include<Dijkstra.h>

int main()
{
    try
    {
        setlocale(LC_ALL, "Rus");

        //получаем список рёбер
//        auto edges = getUserInputFromFile("files/input.txt");
        auto edges = getUserInputFromConsole();

        //заполняем граф
        Graph graph(8, true);
        for (auto edge : edges)
            graph.addEdge(edge);

        //получаем матрицу смежности графа
        auto adjMatrix = graph.getAdjMatrix();
        std::cout << "Матрица смежности: " << "\n";
        showMatrix(adjMatrix);

        std::cout << "\n\n";

        //переводим матрицу смежности в матрицу инцидентности
        auto incMatrix = graph.getIncMatrix();
        std::cout << "Матрица инцидентности: " << "\n";
        showMatrix(incMatrix);

        std::cout << "\n\n";

        //проверяем является ли граф Эйлеровым
        bool euler = graph.isEuler();
        if (euler)
            std::cout << "Граф является Эйлеровым" << "\n";
        else
            std::cout << "Граф не является Эйлеровым" << "\n";

        std::cout << "\n\n";


        //формируем неориентированный граф
        Graph undirGraph = getUndirectedGraph(8, edges);
        auto unAdjMatrix = undirGraph.getAdjMatrix();
        std::cout << "Матрица смежности неориентированного графа: " << "\n";
        showMatrix(unAdjMatrix);

        std::cout << "\n\n";

        std::cout << "Всевозможные кратчайшие пути" << "\n";
        std::vector<int> path;
        std::vector<int> from;
        std::vector<int> dist;
        for (int i = 0; i < 8; ++i)
        {
            from = dijkstra(unAdjMatrix, dist, i);
            std::cout << "Для вершины " << i << ":" << "\n";
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
