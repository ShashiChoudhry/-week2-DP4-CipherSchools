#include<bits/stdc++.h>
using namespace std;

void takeInput(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++) {
        cin>> arr[i];
    }
}

int largestRectangleArea(vector<int>& heights)
{

    int n = heights.size();
    vector<int> leftMin(n);
    stack<int> st;

    for(int i = 0; i < n; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if(st.empty())
            leftMin[i] = -1;
        else
            leftMin[i] = st.top();

        st.push(i);
    }

    vector<int> rightMin(n);
    stack<int> s;

    for(int i = n -1; i >= 0; i--) {
        while(!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }

        if(s.empty())
            rightMin[i] = n;
        else
            rightMin[i] = s.top();

        s.push(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, (rightMin[i] - leftMin[i] -1) * heights[i]);
    }

    return ans;
}

int main()
{
    int n; cin>> n;
    vector<int> heights(n);

    takeInput(heights);

    int ans = largestRectangleArea(heights);
    cout<< ans << endl;
}

