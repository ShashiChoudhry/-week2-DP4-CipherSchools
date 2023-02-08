#include<bits/stdc++.h>
using namespace std;

void takeInput(vector<int>& arr, int n)
{
    for(int i = 0; i < n; i++)
        cin>> arr[i];
}

int kthSmallest(vector<int>& arr, int k)
{
    priority_queue<int> pq;

    for(int i = 0; i < k; i++)
        pq.push(arr[i]);

    for(int i = k; i < arr.size(); i++) {
        if(pq.top() > arr[i]) {
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

    cout<< kthSmallest(arr, k);

    return 0;
}
