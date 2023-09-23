#include <iostream>
#include <queue>

class BST {

private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* root;

    void insertNode(Node* ptr, int val);
    void inOrder(Node* ptr);
    void preOrder(Node* ptr);
    void postOrder(Node* ptr);
    void levelOrder(Node* ptr);

public:
    BST()
    {
        root = NULL;
    }
    void breadthOrderTraversal();
    void depthOrderTraversal();
    void addNode(int val);
};


void BST::insertNode(Node* ptr, int val)
{
    if (root == NULL)
    {
        Node* new_node = new Node;
        new_node->data = val;
        new_node->left = NULL;
        new_node->right = NULL;

        root = new_node;
    }
    else
    {
        ptr = root;
        Node* tmp = ptr;

        while (tmp != NULL)
        {
            if (tmp->data == val)   //duplicate
            {
                std::cout << "duplicate\n";
                return;
            }
            if (val < tmp->data)    //left
            {
                if (tmp->left != NULL)
                {
                    tmp = tmp->left;
                }
                else
                {
                    Node* new_node = new Node;
                    new_node->data = val;
                    new_node->left = NULL;
                    new_node->right = NULL;

                    tmp->left = new_node;
                }
            }
            else if (val > tmp->data)    //right
            {
                if (tmp->right != NULL)
                {
                    tmp = tmp->right;
                }
                else
                {
                    Node* new_node = new Node;
                    new_node->data = val;
                    new_node->left = NULL;
                    new_node->right = NULL;

                    tmp->right = new_node;
                }
            }
        }
    }
}


void BST::addNode(int val)
{
    insertNode(root, val);
}


void BST::inOrder(Node* tmp)
{
    if (tmp != NULL)
    {
        inOrder(tmp->left);
        std::cout << tmp->data << " ";
        inOrder(tmp->right);
    }
}


void BST::preOrder(Node* tmp)
{
    if (tmp != NULL)
    {
        std::cout << tmp->data << " ";
        preOrder(tmp->left);
        preOrder(tmp->right);
    }
}


void BST::postOrder(Node* tmp)
{
    if (tmp != NULL)
    {
        postOrder(tmp->left);
        postOrder(tmp->right);
        std::cout << tmp->data << " ";
    }
}


void BST::depthOrderTraversal()
{
    std::cout << "InOrder traversal" << std::endl;
    inOrder(root);

    std::cout << "PreOrder traversal" << std::endl;
    preOrder(root);

    std::cout << "PostOrder traversal" << std::endl;
    postOrder(root);
}


void BST::levelOrder(Node* tmp)
{
    if (root == NULL)
    {
        return;
    }
    std::queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        tmp = q.front();
        std::cout << tmp->data << " ";

        if (tmp->left != NULL)
        {
            q.push(tmp->left);
        }
        if (tmp->right != NULL)
        {
            q.push(tmp->right);
        }
        q.pop();
    }

}


void BST::breadthOrderTraversal()
{
    levelOrder(root);
}


int main()
{
    int treeLeaves[10] = { 8, -12, 5, 43, 5, 7, 21, -3, 78, 1 };
    BST bst;

    for (int i = 0; i < 10; i++)
    {
        bst.addNode(treeLeaves[i]);
    }

    bst.depthOrderTraversal();

    std::cout << "\nlevel order traversal\n";
    bst.breadthOrderTraversal();

    return 0;
}

