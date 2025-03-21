#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;

vector<vector<int>> mst_prim(int n, vector<vector<pair<int,int>>>& neighs) {
    vector<vector<int>> mst;
    auto comp = [] (auto& e1, auto& e2) {
        return e1[2] > e2[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
    vector<bool> added(n, false);
    added[0] = true;
    for (auto& e : neighs[0]) {
        pq.push({0, e.first, e.second});
    }
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (added[top[1]]) continue;
        added[top[1]] = true;
        mst.push_back(top);
        for (auto& e : neighs[top[1]]) pq.push({top[1], e.first, e.second});
    }

    return mst;

}

vector<vector<int>> mst_kruskal(int n, vector<vector<int>> edges) {
    sort(edges.begin(), edges.end(), [&](auto& e1, auto& e2) {
        return e1[2] < e2[2];
    });

    vector<vector<int>> mst;

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    function<int(int)> dsu_find = [&](int a) {
        if (parent[a] == a) return a;
        parent[a] = dsu_find(parent[a]);
        return parent[a];
    };

    auto dsu_union = [&](int a, int b) {
        a = dsu_find(a), b = dsu_find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a,b);
        parent[b] = a;
        if (rank[a] = rank[b]) rank[a]++;
    };

    for (auto& e : edges) {
        if (dsu_find(e[0]) == dsu_find(e[1])) continue;
        dsu_union(e[0], e[1]);
        mst.push_back(e);
    }


    return mst;

}



int main() {
    int n;
    cout << "Enter no of nodes: ";
    cin >> n;
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
        neighs[edge[1]].push_back(make_pair(edge[0], edge[2]));
    }

    auto mstp = mst_prim(n, neighs);
    auto mstk = mst_kruskal(n, edges);
    
    cout << "MST Prim:\n";
    for (auto& e: mstp) cout << e[0] << " " << e[1] << " " << e[2] << endl;
    
    cout << "MST Kruskal:\n";
    for (auto& e: mstk) cout << e[0] << " " << e[1] << " " << e[2] << endl;
    
    return 0;
}