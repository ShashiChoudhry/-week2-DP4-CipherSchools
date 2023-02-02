#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> dp;
int lcs(string& str1, int m, string& str2, int n)
{

    if(m == 0 || n == 0)
        return 0;

    string key = to_string(m) + "*" + to_string(n);

    if(dp.count(key)) {
        return dp[key];
    }

    int ans = 0;
    if(str1[m -1] == str2[n -1]) {
        ans = 1 +lcs(str1, m -1, str2, n -1);
    }
    else {
        int op1 = lcs(str1, m, str2, n -1);
        int op2 = lcs(str1, m -1, str2, n);

        ans = max(op1, op2);
    }

    return dp[key] = ans;

}

int main()
{
    string str1, str2;
    cin>> str1 >> str2;

    cout<< lcs(str1, str1.length(), str2, str2.length());
}
