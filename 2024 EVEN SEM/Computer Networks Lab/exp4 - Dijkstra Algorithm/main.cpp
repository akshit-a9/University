#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <set>
using namespace std;

void printPath(vector<int>& previous, int j) {
    if (previous[j] == -1) {
        return;
    }
    printPath(previous, previous[j]);
    cout << " --->" << j + 1;
}

int main() {
    int num;
    cout << "Enter the number of nodes: ";
    cin >> num;
   
    vector<vector<int>> a(num, vector<int>(num, 10000));
   
    for (int i = 0; i < num; i++) {
        a[i][i] = 0;
    }
   
    cout << "Enter the edges of the network in terms of node pairs and -1 to end" << endl;
    int x, y, w;
    int edgeCount = 1;
   
    while (true) {
        cout << "Edge number " << edgeCount++ << ": ";
        cin >> x >> y;
        if (x == -1 || y == -1) break;
        cout << "Enter the weight of the edge: ";
        cin >> w;
        a[x - 1][y - 1] = w;
        a[y - 1][x - 1] = w;
    }
   
    // Print the network in matrix representation
    cout << "\n*The network in matrix representation is as below*" << endl;
    for (const auto& row : a) {
        for (const auto& val : row) {
            cout << setw(6) << val << "\t";
        }
        cout << endl;
    }
   
    // Dijkstra's Algorithm
    int source;
    cout << "Enter the source node: ";
    cin >> source;
    source--; // Adjusting for 0-indexed array
   
    vector<int> dist(num, 10000);
    vector<int> previous(num, -1);
    dist[source] = 0;
   
    set<pair<int, int>> q; // Set is used as a min-priority queue
    q.insert({0, source});
   
    while (!q.empty()) {
        int u = q.begin()->second;
        q.erase(q.begin());
       
        for (int v = 0; v < num; ++v) {
            if (a[u][v] && dist[u] + a[u][v] < dist[v]) {
                q.erase({dist[v], v});
                dist[v] = dist[u] + a[u][v];
                previous[v] = u;
                q.insert({dist[v], v});
            }
        }
    }
   
    // Printing paths and distances from source
    for (int i = 0; i < num; ++i) {
        if (i != source) {
            cout << "\n*Path from node " << source + 1 << " to node " << i + 1 << "*" << endl;
            if (dist[i] == 10000) {
                cout << " There is no path." << endl;
            } else {
                cout << source + 1;
                printPath(previous, i);
                cout << "\n Shortest distance is " << dist[i] << " \n" << endl;
            }
        }
    }
   
    return 0;
}