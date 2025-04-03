#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<int> bellman(int& n, vector<vector<int>>& edges, bool isDir) {
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    for (int i = 0; i < n-1; i++) {
        for (auto& e : edges) {
            if (dist[e[0]] != INT_MAX) dist[e[1]] = min(dist[e[1]], dist[e[0]] + e[2]);
            if (!isDir && dist[e[1]] != INT_MAX) dist[e[0]] = min(dist[e[0]], dist[e[1]] + e[2]);
        }
    }
    // go one more round and if cheaper cost is possible, negative cycle exists
    for (auto& e : edges) {
        if (dist[e[1]] > dist[e[0]] + e[2]) {
            cout << "Negative cycle detected\n";
            break;
        }
    }

    return dist;
}


int main() {
    int n;
    cout << "Enter no of nodes: ";
    cin >> n;
    char isDir;
    cout << "Is the graph directed?(Y/N): ";
    cin >> isDir;
    vector<vector<int>> edges;
    cout << "Enter edges [u v w] (Enter [-1 X X] to stop):\n";
    
    vector<int> v(3);
    while (true) {
        cin >> v[0] >> v[1] >> v[2];
        if (v[0] == -1) break;
        edges.push_back(v);
    } 
    

    auto dist = bellman(n, edges, tolower(isDir) == 'y');
    cout << "Distances: \n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << dist[i] << endl;
    }
}