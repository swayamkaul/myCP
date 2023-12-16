#include<bits/stdc++.h>
using namespace std;

int N=100001;
struct Node
{
      Node *left;
      Node *right;
      int val;
  
};

struct Node* newNode(int val)
{
    struct Node* node = new Node;
    node->val = val;
    node->left = node->right = NULL;
    return node;
}



vector<vector<int>> VerticalOrder(Node* root) // function to be completed 
    map < int,vector<int> > m;
    int hd = 0;
    getVerticalOrder(root, hd, m);
    vector<vector<int>> v(N);

    map< int,vector<int> > :: iterator it;

    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
           v[it->first].push_back(it->second[i]) ;
    }
    return v;
}


void getVerticalOrder(Node* root, int h, map<int, vector<int>> &m)
{
    if (root == NULL)  
        return;

    m[h].push_back(root->val);  
    getVerticalOrder(root->left, hd-1, m); // left subtree traversal
    getVerticalOrder(root->right, hd+1, m);// right subtree traversal
}
 
void printVerticalOrder(Node* root) // testing output function 
{
    map < int,vector<int> > m;
    vector<vector<int>> v(N);
    int h = 0;
    getVerticalOrder(root, h, m);
    map< int,vector<int> > :: iterator it;
    for (it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
            cout << it->second[i] << " ";
        cout << endl;
    }
}
int main()
{
    Node *root = newNode(10);
    root->left = newNode(8);
    root->right = newNode(12);
    root->left->left = newNode(4);
    root->left->right = newNode(9);
    root->right->left = newNode(11);
    root->right->right = newNode(17);
    cout << "Vertical order traversal :\n";
    printVerticalOrder(root);
    return 0;
}
// Time Complexity O(N);