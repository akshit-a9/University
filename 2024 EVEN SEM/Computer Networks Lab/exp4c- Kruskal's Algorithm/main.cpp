#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define INFINITY 9999999
#define NUM_VERTICES 6

int graph[NUM_VERTICES][NUM_VERTICES] = {
    {0, 7, 9, INFINITY, INFINITY, 14},
    {7, 0, 10, 15, INFINITY, INFINITY},
    {9, 10, 0, 11, INFINITY, 2},
    {INFINITY, 15, 11, 0, 6, INFINITY},
    {INFINITY, INFINITY, INFINITY, 6, 0, 9},
    {14, INFINITY, 2, INFINITY, 9, 0}
};

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    Edge* edge;
};

int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    if(xset != yset) {
        parent[xset] = yset;
    }
}

void KruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[V];
    int e = 0;
    int i = 0;

    sort(graph->edge, graph->edge + graph->E, [](Edge a, Edge b) -> bool {
        return a.weight < b.weight;
    });

    int *parent = new int[V];
    memset(parent, -1, sizeof(int) * V);

    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edge[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }

    cout << "Following are the edges in the constructed MST\n";
    for (i = 0; i < e; ++i)
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;

    delete[] parent;
}

int main() {
    int V = NUM_VERTICES, E = 0;
    vector<Edge> edges;
    for(int i = 0; i < V; ++i) {
        for(int j = i + 1; j < V; ++j) {
            if(graph[i][j] != INFINITY) {
                edges.push_back({i, j, graph[i][j]});
                E++;
            }
        }
    }

    Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = &edges[0];

    KruskalMST(graph);

    return 0;
}
