#include<bits/stdc++.h>
using namespace std;

void takeInput(stack<int>& st, int n)
{
    while(n--) {
        int x; cin>> x;
        st.push(x);
    }
}

void printData(stack<int> &st)
{
    while(!st.empty()) {
        cout<< st.top() << endl;
        st.pop();
    }
}

void insertAtBottom(stack<int>& st, int x)
{
    if(st.empty()) {
        st.push(x);
        return;
    }
    else {
        int temp = st.top(); st.pop();
        insertAtBottom(st, x);
        st.push(temp);
    }
}

int main()
{
    int n, x;
    cin>> n >> x;

    stack<int> st;
    takeInput(st, n);

    insertAtBottom(st, x);

    printData(st);

    return 0;
}
