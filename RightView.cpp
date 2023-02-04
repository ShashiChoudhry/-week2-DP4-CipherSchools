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

void rightView(TreeNode* root, int lvl, vector<int>& holdRight)
{

    if(root) {

        if(holdRight.size() == lvl)
            holdRight.push_back(root -> data);

        rightView(root -> right, lvl +1, holdRight);
        rightView(root -> left, lvl +1, holdRight);
    }
}

int main()
{
    // i/p : 1 2 3 -1 -1 4 8 -1 6 7 -1 -1 -1 -1 -1
    // i/p : 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    TreeNode* root = takeInput();

    int lvl = 0;
    vector<int> holdRight;
    rightView(root, lvl, holdRight);

    printArr(holdRight);

    return 0;
}



