#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
    public:
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};


// root -> left -> right
void inOrderTraversalIterative(TreeNode* root)
{
    // root -> left -> right
    stack<TreeNode*> s;
    vector<int> result;
    while(!s.empty() || root!=NULL)
    {
       while(root!=NULL)
       {
           s.push(root);
           root = root->left;
       }
        TreeNode* top = s.top();
        s.pop();
        result.push_back(top->data);

        if(top->right != NULL)
        {
            s.push(top->right);
        }
    }
    cout<<"InOrder Traversal\n";
    for(int element : result)
    {
        cout<<element<<" ";
    }
    cout<<"\n------------------------------\n";

}






// root -> left -> right
void preOrderTraversalIterative(TreeNode* root)
{
    // root -> left -> right
    stack<TreeNode*> s;
    s.push(root);
    vector<int> result;
    while(!s.empty())
    {
        TreeNode* top = s.top();
        s.pop();
        result.push_back(top->data);
        if(top->right != NULL)
        {
            s.push(top->right);
        }
        if(top->left != NULL)
        {
            s.push(top->left);
        }
    }
    cout<<"PreOrder Traversal\n";
    for(int element : result)
    {
        cout<<element<<" ";
    }
    cout<<"\n------------------------------\n";
}


// left -> right -> root
void postOrderTraversalIterative(TreeNode* root)
{
    stack<TreeNode*> s;
    s.push(root);
    vector<int> result;
    while(!s.empty())
    {
        TreeNode* top = s.top();
        s.pop();
        result.push_back(top->data);
        if(top->left != NULL)
        {
            s.push(top->left);
        }
        if(top->right != NULL)
        {
            s.push(top->right);
        }
    }
    reverse(result.begin(), result.end());
    cout<<"PostOrder Traversal\n";
    for(int element : result)
    {
        cout<<element<<" ";
    }
    cout<<"\n------------------------------\n";
}

int main() 
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    /* Preorder traversal of binary tree is
        1 2 4 5 3 
        Inorder traversal of binary tree is
        4 2 5 1 3 
        Postorder traversal of binary tree is
        4 5 2 3 1
    */



    preOrderTraversalIterative(root);
    inOrderTraversalIterative(root);
    postOrderTraversalIterative(root);
    return 0;
}