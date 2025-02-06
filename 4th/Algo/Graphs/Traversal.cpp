#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


vector<int> dfs(int n, vector<vector<int>>& neigh);
vector<int> bfs(int n, vector<vector<int>>& neigh);


int main() {
    int n, e;
    cout << "Enter no of nodes: ";
    cin >> n;
    cout << "Enter no of edges: ";
    cin >> e;
    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter edges:\n";
    for (auto& edge : edges) cin >> edge[0] >> edge[1];

    vector<vector<int>> neigh(n);
    for (auto& edge : edges) {
        neigh[edge[0]].push_back(edge[1]);
        neigh[edge[1]].push_back(edge[0]);
    }
    
    vector<int> obfs = bfs(n, neigh);
    vector<int> odfs = dfs(n, neigh);
    cout << "BFS Result: ";
    for (auto& i : obfs) cout << i << " ";
    cout << endl;
    cout << "DFS Result: ";
    for (auto& i : odfs) cout << i << " ";
    cout << endl;

    return 0;
}

vector<int> dfs(int n, vector<vector<int>> &neigh){
    vector<int> res;

    stack<int> st;
    vector<bool> visited(n, false);
    st.push(0);
    while (!st.empty()) {
        int cur = st.top();
        st.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        res.push_back(cur);
        for (auto& i : neigh[cur]) {
            if (!visited[i]) st.push(i);
        }
    }

    return res;
}



/*

0 - 2 - 1
|\  /
3  4 - 5
 \   /
   6
*/


vector<int> bfs(int n, vector<vector<int>> &neigh){
    vector<int> res;

    queue<int> q;
    vector<bool> visited(n, false);
    q.push(0);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        res.push_back(cur);
        for (auto& i : neigh[cur]) {
            if (!visited[i]) q.push(i);
        }
    }

    return res;
}
