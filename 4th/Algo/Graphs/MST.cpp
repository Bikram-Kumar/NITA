#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> mst_prim(int n, vector<vector<pair<int,int>>>& neighs) {
    vector<vector<int>> mst;
    auto comp = [] (auto& e1, auto& e2) {
        return e1[2] > e2[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq(comp);
    vector<bool> added(n, false);
    added[0] = true;
    int remain = n-1;
    for (auto& e : neighs[0]) {
        pq.push({0, e.first, e.second});
    }
    while (remain != 0) {
        auto top = pq.top();
        pq.pop();
        if (added[top[1]]) continue;
        added[top[1]] = true;
        mst.push_back(top);
        for (auto& e : neighs[top[1]]) pq.push({top[1], e.first, e.second});
        remain--;
    }

    return mst;

}

vector<vector<int>> mst_kruskal(int n, vector<vector<int>> edges) {
    sort(edges.begin(), edges.end(), [&](auto& e1, auto& e2) {
        return e1[2] < e2[2];
    });
    vector<int> tree_id(n);
    for (int i = 0; i < n; i++) tree_id[i] = i;
    vector<vector<int>> mst;

    for (auto& e : edges) {
        if (tree_id[e[0]] == tree_id[e[1]]) continue;
        
        mst.push_back(e);
        int old_id = tree_id[e[0]], new_id = tree_id[e[1]];
        for (int i = 0; i < n; i++) {
            if (tree_id[i] == old_id) {
                tree_id[i] = new_id;
            }
        }
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
    cout << "MST Kruskal:\n";
    for (auto& e: mstk) {
        cout << e[0] << " " << e[1] << " " << e[2] << endl;
    }
    cout << "MST Prim:\n";
    for (auto& e: mstp) {
        cout << e[0] << " " << e[1] << " " << e[2] << endl;
    }
    

    return 0;
}