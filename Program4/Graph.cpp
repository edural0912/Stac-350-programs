#include "Graph.h"

using namespace std;

void Graph::addEdge(char src, char dest, int weight) {
    adjList[src].push_back(std::make_pair(dest, weight));
}

void Graph::DFSUtil(char node, std::map<char, bool>& visited) {
    visited[node] = true;
    std::cout << node << " ";
    for (auto i = adjList[node].begin(); i != adjList[node].end(); ++i) {
        if (!visited[i->first]) {
            DFSUtil(i->first, visited);
        }
    }
}

void Graph::DFS(char start) {
    std::map<char, bool> visited;
    DFSUtil(start, visited);
}

void Graph::BFS(char start) {
    std::map<char, bool> visited;
    std::queue<char> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        char node = q.front();
        std::cout << node << " ";
        q.pop();

        for (auto i = adjList[node].begin(); i != adjList[node].end(); ++i) {
            if (!visited[i->first]) {
                visited[i->first] = true;
                q.push(i->first);
            }
        }
    }
}

bool Graph::hasPath(char src, char dest) {
    std::map<char, bool> visited;
    std::queue<char> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        char node = q.front();
        q.pop();

        for (auto i = adjList[node].begin(); i != adjList[node].end(); ++i) {
            if (i->first == dest) {
                return true;
            }
            if (!visited[i->first]) {
                visited[i->first] = true;
                q.push(i->first);
            }
        }
    }
    return false;
}
