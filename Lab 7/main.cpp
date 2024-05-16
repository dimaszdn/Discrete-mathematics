#include<Graph.h>
#include<Complexity.h>

int main()
{
    try
    {
        const int N = 13500;
        Graph graph(N);
        graph.fillRandom();
        graph.dijkstra(52);
        graph.bellmanFord(52);
        std::cout << "\n\n";
        std::cout << "Dijkstra iterations: " << std::fixed << graph.getItDijkstra() << "\n";
        std::cout << "Dijkstra complexity: " << dijkstraComplexity(N, graph.countEdges()) << "\n\n";
        std::cout << "Bellman-Ford iterations: " << graph.getItBellmanFord() << "\n";
        std::cout << "Bellman-Ford complexity: " << bellmanFordComplexity(N) << "\n\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }

    return 0;
}
