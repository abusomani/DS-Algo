#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void topView(Node *root)
    {
        map<int, int> Mp;

        queue<pair<Node *, int>> Q;
        Q.push({root, 0});

        while (!Q.empty())
        {
            pair<Node *, int> P = Q.front();
            Q.pop();

            if (Mp.find(P.second) == Mp.end())
                Mp[P.second] = P.first->data;

            if (P.first->left != NULL)
                Q.push({P.first->left, P.second - 1});

            if (P.first->right != NULL)
                Q.push({P.first->right, P.second + 1});
        }

        for (map<int, int>::iterator it = Mp.begin(); it != Mp.end(); it++)
        {
            pair<int, int> P = *it;
            cout << P.second << " ";
        }
    }

}; //End of Solution