#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& value, int n,vector<int>& weight, int W, vector<vector<int>>& dp)
{
    if(n == 0) return 0;
    if(W == 0) return 0;

    if(dp[n][W] != -1)
        return dp[n][W];

    int ans = INT_MIN;

    int op1 = -1;
    if(weight[n -1] <= W)
        op1 = value[n -1] + knapsack(value, n -1, weight, W - weight[n -1], dp);

    int op2 = knapsack(value, n -1, weight, W, dp);

    ans = max(op1, op2);

    return dp[n][W] = ans;
}

int main()
{
    int n, W;
    cin>> n >> W;

    vector<int> value(n), weight(n);

    for(int i = 0; i < n; i++) {
        cin>> value[i];
    }

    for(int i = 0; i < n; i++) {
        cin>> weight[i];
    }

    vector<vector<int>> dp(n +1, vector<int>(W +1, -1));
    cout<<knapsack(value, n, weight, W, dp);
}
