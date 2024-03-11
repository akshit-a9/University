#include <cstring>
#include <iostream>
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

int main() {
    int edgeCount;
    bool isSelected[NUM_VERTICES];
    memset(isSelected, false, sizeof(isSelected));
    edgeCount = 0;
    isSelected[0] = true;
    int fromVertex;
    int toVertex;
    cout << "Edge" << " : " << "Weight" << endl;
    while (edgeCount < NUM_VERTICES - 1) {
        int minWeight = INFINITY;
        fromVertex = 0;
        toVertex = 0;

        for (int i = 0; i < NUM_VERTICES; i++) {
            if (isSelected[i]) {
                for (int j = 0; j < NUM_VERTICES; j++) {
                    if (!isSelected[j] && graph[i][j]) {
                        if (minWeight > graph[i][j]) {
                            minWeight = graph[i][j];
                            fromVertex = i;
                            toVertex = j;
                        }
                    }
                }
            }
        }
        cout << fromVertex + 1 << " - " << toVertex + 1 << " :  " << graph[fromVertex][toVertex] << endl;
        isSelected[toVertex] = true;
        edgeCount++;
    }

    return 0;
}
