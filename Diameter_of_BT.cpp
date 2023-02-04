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

int height(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int lh = height(root -> left);
    int rh = height(root -> right);

    return max(lh, rh) +1;
}

int diameter(TreeNode* root)
{
    if(root == NULL)
        return 0;

    int lh = height(root -> left);
    int rh = height(root -> right);

    return max(max(diameter(root -> left), diameter(root -> right)), lh + rh);
}

int main()
{
    // i/p : 1 2 3 -1 -1 4 8 -1 6 7 -1 -1 -1 -1 -1
    // i/p : 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    TreeNode* root = takeInput();

    cout<< diameter(root) << endl;
    return 0;
}
