
#include "AVLTree.h"
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include <ctime>
#define pow2(n) (1 << (n))
using namespace std;

AVLTree::AVLTree()
{
}


AVLTree::~AVLTree()
{

}

AVLTree::AVLTree(const AVLTree & tree)
{
	copyTree(tree.root, root);
}

void AVLTree::copyTree(AVLTreeNode *treePtr, AVLTreeNode *& newTreePtr) const {

	if (treePtr != NULL) {		// copy node
		newTreePtr = new AVLTreeNode(treePtr->item, NULL, NULL);
		copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
		copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
	}
	else
		newTreePtr = NULL;	// copy empty tree
}


void AVLTree::insert(int val)
{
	insert(val, root);
}

// this part of the code is ispired from the https://users.cs.fiu.edu/~weiss/dsaajava/code/DataStructures/AvlTree.java 
AVLTreeNode* AVLTree::insert(const int &val , AVLTreeNode *&treePtr)// throw(TreeException)
{
		int a = 5;	
		int b=4;
		if (treePtr == NULL){
			treePtr = new AVLTreeNode(val, NULL, NULL);
		}
		else if (treePtr != NULL && (treePtr->item) > val) //
		{	
			//cout<<"asdas"<<endl; 
			treePtr->leftChildPtr = insert(val, treePtr->leftChildPtr);

			if (calcHeight(treePtr->leftChildPtr) - calcHeight(treePtr->rightChildPtr)  > 1)
				if (val - (treePtr->leftChildPtr->item) < 0)
					treePtr = right(treePtr); //
				else
					treePtr = leftRight(treePtr); //
		}
		else if (treePtr != NULL && val > (treePtr->item)) //val > (treePtr->item) val > (treePtr->item)
		{	//cout<< "e"<< endl;
			treePtr->rightChildPtr = insert(val, treePtr->rightChildPtr);
			if (calcHeight(treePtr->rightChildPtr) - calcHeight(treePtr->leftChildPtr)  > 1)
				if (val - (treePtr->rightChildPtr->item) > 0)
					treePtr = left(treePtr); //treePtr = left(treePtr);
				else
					treePtr = rightLeft(treePtr); //;
		}
		return treePtr;
}


AVLTreeNode* AVLTree::right(AVLTreeNode *& node)
{
	AVLTreeNode* temp;
	temp= node->leftChildPtr;
	node->leftChildPtr = temp->rightChildPtr;
	temp->rightChildPtr = node;
	return temp;

}


AVLTreeNode* AVLTree::left(AVLTreeNode *& node)
{

	AVLTreeNode* temp;
	temp= node->rightChildPtr;
	node->rightChildPtr = temp->leftChildPtr;
	temp->leftChildPtr = node;
	return temp;
}

AVLTreeNode* AVLTree::rightLeft(AVLTreeNode *& node)
{
	node->rightChildPtr = right(node->rightChildPtr);
	return left(node);
}

AVLTreeNode* AVLTree::leftRight(AVLTreeNode *& parent)
{
	parent->leftChildPtr = left(parent->leftChildPtr);
	return right(parent);
}

int AVLTree::getHeight()
{
	if (root == NULL)
	{
		return -1;
		
	}
	else return calcHeight(root);
}

int AVLTree::calcHeight(AVLTreeNode* node)
{
	int height = 0;
	if (node != NULL)
	{
		int max_height = std::max(calcHeight(node->leftChildPtr), calcHeight(node->rightChildPtr));
		height = max_height + 1;
	}
	return height;
}

int AVLTree::heightD(AVLTreeNode *temp)
{

	int a = calcHeight(temp->leftChildPtr) - calcHeight(temp->rightChildPtr);
	return a;
}

void AVLTree::printInorder(AVLTreeNode* tree)
{
	if (tree == NULL)
		return;
	printInorder(tree->leftChildPtr);
	cout << tree->item << "  ";
	printInorder(tree->rightChildPtr);
}


