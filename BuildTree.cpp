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

void postOrder(TreeNode* root)
{
    if(root == NULL)
        return;

    postOrder(root -> left);
    postOrder(root -> right);
    cout<< root -> data << ' ';
}

int searchIn(vector<int>& inOrder, int x, int lb, int rb)
{
    for(int i = lb; i <= rb; i++) {
        if(inOrder[i] == x)
            return i;
    }

    return -1;
}

TreeNode* buildTree(vector<int>& preOrder, vector<int>& inOrder, int& j, int lb, int rb)
{
    if(lb > rb) return NULL;

    int temp = preOrder[j++];
    TreeNode* root = new TreeNode(temp);

    int ind = searchIn(inOrder, temp, lb, rb);
    root -> left = buildTree(preOrder, inOrder, j, lb, ind -1);
    root -> right = buildTree(preOrder, inOrder, j, ind +1, rb);

    return root;
}

/*
  pre :  [1 2 3 4 6 8 7]
  in  :  [2 1 4 6 3 7 8]
  post:  [2 6 4 7 8 3 1]

*/

int main()
{
    // i/p : 1 2 3 -1 -1 4 8 -1 6 7 -1 -1 -1 -1 -1
    // i/p : 1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
//    TreeNode* root = takeInput();

    vector<int> preOrder{1, 2, 3, 4, 6, 8, 7};
    vector<int> inOrder {2, 1, 4, 6, 3, 7, 8};

    int j = 0;
    TreeNode* root = buildTree(preOrder, inOrder, j, 0, preOrder.size() -1);

    postOrder(root);

    return 0;
}




