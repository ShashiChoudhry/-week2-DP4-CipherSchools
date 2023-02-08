#include<bits/stdc++.h>
using namespace std;

void takeInput(vector<int>& arr, int n)
{
    for(int i = 0; i < n; i++)
        cin>> arr[i];
}

int kthLargest(vector<int>& arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < k; i++)
        pq.push(arr[i]);

    for(int i = k; i < arr.size(); i++) {
        if(pq.top() < arr[i]) {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    int n, k;
    cin>> n >> k;

    vector<int> arr(n);
    takeInput(arr, n);

    cout<< kthLargest(arr, k);

    return 0;
}
