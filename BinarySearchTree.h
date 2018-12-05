/**
 * CS300 Assignment 5 BinarySearchTree/Array/HashTable UPC Scanner
 * Purpose: To create a UPC Scanner with BST, Array, and HasTable Data Structures
 * and to see the difference in time to search for a specific item.
 *
 * @author Daniyal Adzhiyev
 * @version 1.0 12/03/2018
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <iostream>

using namespace std;

//bstNode structure for BST
template <class T>
struct bstNode
{
	T data;
	bstNode<T> *left;
	bstNode<T> *right;
};
/*
 *Template class for BST
 */
template <class T>
class BinarySearchTree
{

  public:
	BinarySearchTree();
	void printInOrder() { printInOrder(root); }
	void printPreOrder() { printPreOrder(root); }
	void printPostOrder() { printPostOrder(root); }
	int height() { return height(root); }
	void insert(T &item) { insert(root, item); }
	//altered to return item in the BST Tree
	T search(T &item) { return search(root, item); }
	T findMax() { return findMax(root); }
	T findMin(T &e) { return findMin(root, e); }
	void deletebstNode(T &item) { deletebstNode(root, item); }
	~BinarySearchTree() { destroy(root); }

  private:
	bstNode<T> *root;
	void printInOrder(bstNode<T> *);
	void printPreOrder(bstNode<T> *);
	void printPostOrder(bstNode<T> *);
	void destroy(bstNode<T> *);
	int height(bstNode<T> *);
	int max(int, int);
	void insert(bstNode<T> *&, T &);
	T search(bstNode<T> *, T &);
	T findMax(bstNode<T> *, T &);
	T findMin(bstNode<T> *, T &);
	void deletebstNode(bstNode<T> *&, T &);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	root = NULL;
}

template <class T>
void BinarySearchTree<T>::printInOrder(bstNode<T> *p)
{
	if (p != NULL)
	{
		printInOrder(p->left);
		cout << p->data << " ";
		printInOrder(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::printPreOrder(bstNode<T> *p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		printPreOrder(p->left);
		printPreOrder(p->right);
	}
}

template <class T>
void BinarySearchTree<T>::printPostOrder(bstNode<T> *p)
{
	if (p != NULL)
	{
		printPostOrder(p->left);
		printPostOrder(p->right);
		cout << p->data << " ";
	}
}
template <class T>
int BinarySearchTree<T>::max(int x, int y)
{
	if (x > y)
		return x;
	return y;
}

template <class T>
int BinarySearchTree<T>::height(bstNode<T> *p)
{
	if (p != NULL)
	{
		return 1 + max(height(p->left), height(p->right));
	}
	return -1;
}

template <class T>
void BinarySearchTree<T>::destroy(bstNode<T> *p)
{
	if (p != NULL)
	{
		destroy(p->left);
		destroy(p->right);
		delete p;
		p = NULL;
	}
}

template <class T>
void BinarySearchTree<T>::insert(bstNode<T> *&p, T &item)
{
	if (p == NULL)
	{
		p = new bstNode<T>;
		p->data = item;
		p->left = p->right = NULL;
	}
	else if (item < p->data)
	{
		insert(p->left, item);
	}
	else
	{
		insert(p->right, item);
	}
}

template <class T>
T BinarySearchTree<T>::search(bstNode<T> *p, T &item)
{
	if (p == NULL)
		return item;
	else if (item < p->data)
		return search(p->left, item);
	else if (item > p->data)
		return search(p->right, item);
	return p->data;
}

template <class T>
T BinarySearchTree<T>::findMax(bstNode<T> *p, T &e)
{
	if (p == NULL)
		return e;
	else if (p->right == NULL)
		return p->data;
	else
		return findMax(p->right, e);
}

template <class T>
T BinarySearchTree<T>::findMin(bstNode<T> *p, T &e)
{
	if (p == NULL)
		return e;
	else if (p->left == NULL)
		return p->data;
	else
		return findMin(p->left, e);
}

template <class T>
void BinarySearchTree<T>::deletebstNode(bstNode<T> *&p, T &item)
{
	//item not found, do nothing
	if (p == NULL)
		return;
	else if (item < p->data) //item is on the left subtree
		deletebstNode(p->left, item);
	else if (item > p->data) //item is on the right subtree
		deletebstNode(p->right, item);
	else
	{ //item is equal to data,  it is found
		if (p->left != NULL && p->right != NULL)
		{ // with two children
			int e = -1;
			p->data = findMax(p->left, e);
			deletebstNode(p->left, p->data);
		}
		else
		{
			bstNode<T> *old = p;
			if (p->left != NULL)
				p = p->left;
			else
				p = p->right;

			delete old;
		}
	}
}

#endif /* BINARYSEARCHTREE_H_ */
