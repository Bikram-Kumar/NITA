#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main () {
    int n, cap;
    cout << "Enter capacity of knapsack: ";
    cin >> cap;
    cout << "Enter no. of items: ";
    cin >> n;
    vector<float> weights(n), costs(n);
    cout << "Enter (weight cost) of items:\n";
    for (int i = 0; i < n; i++) cin >> weights[i] >> costs[i];
    
    vector<pair<float,int>> wcRatio(n);
    for (int i = 0; i < n; i++) wcRatio[i] = make_pair(costs[i] / weights[i], i);
    sort(wcRatio.begin(), wcRatio.end(), greater<pair<float,int>>());
    float cur = 0, profit = 0;
    for (auto& p: wcRatio) {
        if (weights[p.second] <= cap - cur) {
            cur += weights[p.second];
            profit += costs[p.second];
        } else {
            profit += (cap - cur) * p.first;
            cur += cap - cur;
            break;
        }
    }
    cout << "Max weight: " << cur << "\nMax profit: " << profit << endl;


}