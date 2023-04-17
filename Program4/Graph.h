#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

class Graph {
private:
    std::map<char, std::vector<std::pair<char, int>>> adjList;
    void DFSUtil(char node, std::map<char, bool>& visited);
public:
    void addEdge(char src, char dest, int weight);
    void DFS(char start);
    void BFS(char start);
    bool hasPath(char src, char dest);
};

#endif

