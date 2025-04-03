#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findDists(int& n, vector<vector<int>>& edges, bool isDir) {
    vector<vector<int>> dists(n, vector<int>(n, INT_MAX));
    for (auto& edge : edges) {
        dists[edge[0]][edge[1]] = edge[2];
        if (!isDir) dists[edge[1]][edge[0]] = edge[2];
    }
    for (int i = 0; i < n; i++) dists[i][i] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (dists[j][i] != INT_MAX && dists[i][k] != INT_MAX)
                    dists[j][k] = min(dists[j][k], dists[j][i] + dists[i][k]);
            }
        }
    }

    return dists;
}

int main () {
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

    auto dists = findDists(n, edges, tolower(isDir) == 'y');

    cout << "Distances:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << i << " -> " << j << ": " << dists[i][j] << endl;
        }
    }
    
}