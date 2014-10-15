#include <iostream>

using namespace std;

struct Node
{
    int k;
    Node *left;
    Node *right;
    
    Node()
    {
        left = 0;
        right = 0;
    }
};

void tree(Node *root)
{root = NULL;}

void push(int n, Node *&b) //добавление в дерево
{
    int x;
    if (n > 0)
    {
        cin >> x;
        b = new Node;
        b->k = x;
        b->left = b->right = NULL;
        int nl = n/2;
        int nr = n - nl - 1;
        push(nl, b->left); //рекурсивно вызываем для левой части
        push(nr, b->right); //рекурсивно для правой
    }
}

void print(Node *&root) //выводим дерево в симметрическом порядке
{
    
    if (root->left != NULL)
        print(root->left);
    
    if (root->right != NULL)
        print(root->right);
    
    cout << root->k << " ";
    
}

void ans(int &sum, Node *&root) //сумма листьев
{
    if (root != NULL)
    {
        if ((root->left == NULL) && (root->right == NULL))
        {sum += root->k;
        }
        ans(sum, root->right);
        ans(sum, root->left);
    }
    
}

int main()
{
    
    Node *root;
    root = NULL;
    int l;
    cout << "input number" << endl;
    cin >> l;
    
    int sum=0; 
    
    cout << "input symbols" << endl;
    
    push(l,root);
    
    cout << "Balanced tree: " << endl;
    print(root);
    
    ans(sum, root);
    
    cout << endl;
    cout << "Sum of the tree: " << endl; 
    cout << sum << endl;
    
    system("pause");
    return 0;
    
}