#include "Graph.h"

using namespace std;

int main() {
    Graph g;
    g.addEdge('B', 'A', 10);
    g.addEdge('A', 'C', 12);
    g.addEdge('C', 'B', 20);
    g.addEdge('C', 'D', 32);
    g.addEdge('A', 'D', 60);
    g.addEdge('E', 'A', 7);


    std::cout << "DFS from E: ";
    g.DFS('E');
    std::cout << std::endl;

    std::cout << "BFS from E: ";
    g.BFS('E');
    std::cout << std::endl;

    std::cout << "Path from A to E: ";
    if (g.hasPath('A', 'E')) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    std::cout << "Path from E to A: ";
    if (g.hasPath('E', 'A')) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

