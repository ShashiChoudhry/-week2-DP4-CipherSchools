#include<bits/stdc++.h>
using namespace std;

void takeInput(vector<int>&arr)
{
    for(int i = 0; i < arr.size(); i++)
        cin>> arr[i];
}

bool isSubset(vector<int>& arr, int n, int sum, vector<vector<int>>& dp)
{

    if(sum == 0) return true;
    if(n == 0) return false;

    if(dp[n][sum] != -1)
        return dp[n][sum];

    int take = isSubset(arr, n -1, sum - arr[n -1], dp);
    int ignore = isSubset(arr, n -1, sum, dp);

    return dp[n][sum] = take || ignore;
}

int main()
{
    int n, sum;
    cin>> n >> sum;

    vector<int> arr(n);

    takeInput(arr);

    vector<vector<int>> dp(n +1, vector<int>(sum +1, -1));
    bool result = isSubset(arr, n, sum, dp);

    if(result)
        cout<< "YES" << endl;
    else
        cout<< "NO" << endl;
}
