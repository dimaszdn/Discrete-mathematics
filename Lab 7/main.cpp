#include<Graph.h>

int main()
{
    try
    {
        Graph graph(1500);
        graph.fillRandom();
//        graph.dijkstra(0);
        graph.bellmanFord(0);
//        graph.outputAdjMatrixToConsole();
//        std::cout << "\n" << "Count iterations: " << graph.getItDijkstra() << "\n";
//        std::cout << graph.getMinDegree() << "\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }

    return 0;
}
