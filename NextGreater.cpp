#include<bits/stdc++.h>
using namespace std;

void takeInput(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++) {
        cin>> arr[i];
    }
}

void printData(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout<< arr[i] << ' ';
    cout<< endl;
}

vector<int> nextGreater(vector<int>& arr)
{

    vector<int> result;
    stack<int> st;

    for(int i = arr.size() -1; i >= 0; i--) {
        while(!st.empty() && st.top() < arr[i]) {
            st.pop();
        }

        if(st.empty()) {
            result.push_back(-1);
        } else {
            result.push_back(st.top());
        }

        st.push(arr[i]);
    }
    reverse(result.begin(), result.end());
    return result;
}

int main()
{
    int n; cin>> n;
    vector<int> arr(n);

    takeInput(arr);

    vector<int> ans = nextGreater(arr);

    printData(ans);
}
