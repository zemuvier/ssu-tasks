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
			b->left = b->right = 0;
			int nl = n/2;
			int nr = n - nl - 1;
			push(nl, b->left); //рекурсивно вызываем для левой части
			push(nr, b->right); //рекурсивно для правой
		}
	}

	void add(int n, Node *root) //добавление в корень дерева
	{push(n, root);}

	void print(Node *r) //выводим дерево в симметрическом порядке
	{
		if (r->left != 0)
			print(r->left);

		if (r->right != 0)
			print(r->right);

		cout << r->k << " ";
	}

	void ans(int &sum, Node *root) //сумма листьев
	{
		Node *root;
		if ((root->left == NULL) && (root->right == NULL))
			sum = sum + root->k;
	}

int main()
{
    
    Node *root;
    root = NULL;

    int l;
    cin >> l;

    int sum = 0; 

    add(l,root);
  
    /*cout << "Balanced tree: " << endl;
    print();*/

    ans(sum,root);

    cout << "Sum of the tree: " << sum << endl;
    return 0;

}