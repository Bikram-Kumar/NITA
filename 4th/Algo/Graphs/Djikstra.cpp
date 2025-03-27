#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector<int> djikstra(int n, vector<vector<pair<int,int>>>& neighs) {
    vector<int> dist(n, INT_MAX);
    dist[0] = 0;
    auto comp = [](auto& p1, auto& p2) {
        return p1.second > p2.second;
    };
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
    for (auto& neigh: neighs[0]) {
        pq.push(neigh);
        dist[neigh.first] = neigh.second;
    } 
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        for (auto& neigh: neighs[cur.first]) {
            if (dist[neigh.first] == INT_MAX) {
                pq.push(make_pair(neigh.first, cur.second + neigh.second));
                dist[neigh.first] = cur.second + neigh.second;
            } else {
                dist[neigh.first] = min(dist[neigh.first], cur.second + neigh.second);
            }
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
    cout << "Enter u v w (Enter -1 X X to stop):\n";
    
    vector<int> v(3);
    while (true) {
        cin >> v[0] >> v[1] >> v[2];
        if (v[0] == -1) break;
        edges.push_back(v);
    } 
    

    vector<vector<pair<int,int>>> neighs(n);
    for (auto& edge : edges) {
        neighs[edge[0]].push_back(make_pair(edge[1], edge[2]));
        if (tolower(isDir) != 'y') neighs[edge[1]].push_back(make_pair(edge[0], edge[2]));
    }

    auto dist = djikstra(n, neighs);
    cout << "Distances: \n";
    for (int i = 0; i < n; i++) {
        cout << i << ": " << dist[i] << endl;
    }
}