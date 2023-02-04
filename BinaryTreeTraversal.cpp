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

void printLvl(TreeNode* root)
{
    if(root == NULL)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* curr = q.front();

        if(curr -> left) {
            q.push(curr -> left);
        }
        if(curr -> right) {
            q.push(curr -> right);
        }

        cout<< curr -> data << ' ';

        q.pop();
    }
}

void printPreOrder(TreeNode* root)
{
    if(root == NULL)
        return;

    cout << root -> data << ' ';
    printPreOrder(root -> left);
    printPreOrder(root -> right);
}

void printInOrder(TreeNode* root)
{
    if(root == NULL)
        return;

    printInOrder(root -> left);
    cout << root -> data << ' ';
    printInOrder(root -> right);
}

void printPostOrder(TreeNode* root)
{
    if(root == NULL)
        return;

    printPostOrder(root -> left);
    printPostOrder(root -> right);
    cout << root -> data << ' ';
}

int main()
{
    // i/p : 1 2 3 -1 -1 4 8 -1 6 7 -1 -1 -1 -1 -1
    // i/p : 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    TreeNode* root = takeInput();

    printLvl(root);
    cout<< endl;

    printPreOrder(root);
    cout<< endl;

    printInOrder(root);
    cout<< endl;

    printPostOrder(root);

    return 0;
}
