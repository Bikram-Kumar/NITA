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
    vector<int> weights(n), costs(n);
    cout << "Enter (weight cost) of items:\n";
    for (int i = 0; i < n; i++) cin >> weights[i] >> costs[i];
    
    
    vector<vector<int>> dp(n, vector<int>(cap+1, 0));

    // for only first item 
    for (int i = weights[0]; i <= cap; i++) dp[0][i] = costs[0];

    // add more items for all possible capacities
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= cap; j++) {
            if (j >= weights[i]) {
                dp[i][j] = max(dp[i-1][j], costs[i] + dp[i-1][j - weights[i]]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }


    cout << "Max profit: " << dp.back().back() << endl;

    return 0;
}