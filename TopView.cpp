#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:

    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void printArr(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout<< arr[i] << ' ';
    cout<< endl;
}


TreeNode* takeInput()
{
    int data;
    cin>> data;

    TreeNode* root = new TreeNode(data);

    queue<TreeNode*> q;
    q.push(root);


    while(!q.empty()) {

        TreeNode* curr = q.front();

        int lData, rData;

        cin>> lData >> rData;

        if(lData != -1) {
            TreeNode *left = new TreeNode(lData);
            curr -> left = left;
            q.push(left);
        }

        if(rData != -1) {
            TreeNode *right = new TreeNode(rData);
            curr -> right = right;
            q.push(right);
        }
        q.pop();
    }

    return root;
}

vector<int> topView(TreeNode* root)
{

    if(root == NULL)
        return {};

    int col = 0;

    queue<pair<TreeNode*, int>> q;
    q.push({root, col});

    map<int, int> mp;

    while(!q.empty())
    {
        pair<TreeNode*, int> curr = q.front();
        col = curr.second;

        if(mp.find(col) == mp.end()) {
            mp[col] = curr.first -> data;
        }

        if(curr.first -> left)
            q.push({curr.first -> left, col -1});
        if(curr.first -> right)
            q.push({curr.first -> right, col +1});

        q.pop();
    }

    vector<int> holdLeft;
    for(auto x: mp) {
        holdLeft.push_back(x.second);
    }

    return holdLeft;
}

int main()
{
    // i/p : 1 2 3 -1 -1 4 8 -1 6 7 -1 -1 -1 -1 -1
    // i/p : 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    TreeNode* root = takeInput();

    vector<int> holdTop = topView(root);

    printArr(holdTop);

    return 0;
}



