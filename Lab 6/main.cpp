#include <iostream>

//#include<UserInput.h>
#include<Graph.h>

int main()
{
    try
    {
        Graph graph("files/input.txt");
        std::vector<std::vector<int>> v(10);
        std::cout << v[0].size();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}