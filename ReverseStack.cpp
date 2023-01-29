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

void reverseStack(stack<int>& st, stack<int>& aux)
{
    if(st.size() <= 1)
        return;

    int tmp = st.top(); st.pop();
    reverseStack(st, aux);

    while(!st.empty()) {
        aux.push(st.top());
        st.pop();
    }

    st.push(tmp);

    while(!aux.empty()) {
        st.push(aux.top());
        aux.pop();
    }
}

int main()
{
    int n;
    cin>> n;

    stack<int> st;
    takeInput(st, n);

    stack<int> aux;
    reverseStack(st, aux);

    printData(st);

    return 0;
}
