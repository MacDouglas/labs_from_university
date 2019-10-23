// Lad_4.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

using namespace std;

struct NodeTree
{
	int key;
	struct NodeTree *Left;
	struct NodeTree *Right;
};

NodeTree *BinaryTree;

void init()
{
	BinaryTree = NULL;
}
 NodeTree *Search(NodeTree *node, int k, int count)
{
	 if ((node->Left != NULL) || (node->Right != NULL))
	 {
		 if (node->key >= k)
		 {
			 if (node->key == k)
				 count++;
			 node->Left = Search(node->Left, k, count);
		 }
		 else if (k >= node->key)
		 {
			 if (node->key == k)
				 count++;
			 node->Right = Search(node->Right, k, count);
		 }
	 }
	cout << "count = " << count << endl;
	return (node);
}

NodeTree *AddNode(NodeTree *node, int k)
{
	if (node == NULL)
	{
		node = new NodeTree;
		node->key = k;
		node->Left = NULL;
		node->Right = NULL;
	}
	else if (k <= node->key)
	{
			node->Left = AddNode(node->Left, k);
	}
	else if (k >= node->key)
	{
		node->Right = AddNode(node->Right, k);
	}
	return (node);
}

void DeleteTree(NodeTree *node)
{
	if (node != NULL)
	{
		NodeTree *p;
		DeleteTree(node->Left);
		DeleteTree(node->Right);
		p = node;
		node->Left = NULL;
		node->Right = NULL;
		delete(p);
	}
}

void PrintTree(NodeTree*node, int h)
{
	if (node != NULL)
	{
		PrintTree(node->Right, h + 1);
		for(int i = 0; i<h; ++i)
			printf("   ");
		cout << node->key<<endl;
		PrintTree(node->Left, h + 1);
	}
}


int main()
{
	init();
	BinaryTree = AddNode(BinaryTree, rand()%10 );

	int n,key;
	cout << "Enter a hight the tree:" << endl;
	cin >> n;
	cout << "Enter a key:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> key;
		AddNode(BinaryTree, key);
	}
	PrintTree(BinaryTree, 0);
	cout << "Enter a search key" << endl;
	cin >> key;
	Search(BinaryTree, key, 0);


 	system("pause");
    return 0;
}

