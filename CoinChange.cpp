#include<bits/stdc++.h>
using namespace std;

unordered_map<string, long long int> dp;
long long int coinChange(int coins[], int n, int amt)
{
    if(amt == 0)
        return 1;
    if(n == 0)
        return 0;

    string key = to_string(n) + "*" + to_string(amt);

    if(dp.count(key))
        return dp[key];

    long long int op1 = 0;
    if(coins[n -1] <= amt)
        op1 = coinChange(coins, n, amt - coins[n -1]);

    long long int op2 = coinChange(coins, n -1, amt);

    return dp[key] = op1 + op2;
}

int main()
{
    int n, amt;
    cin>> n >> amt;

    vector<int> coins(n);

    for(int i = 0; i < n; i++)
        cin>> coins[i];

    cout<< coinChange(coins, n, amt);
}
