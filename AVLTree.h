#pragma once
#include "AVLTreeNode.h"
class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	AVLTree(const AVLTree& tree);

	void copyTree(AVLTreeNode *treePtr, AVLTreeNode *& newTreePtr) const;

	void insert(int val); // inserts an element into the tree
	int getHeight(); // returns the height of the tree
	int calcHeight(AVLTreeNode* node);

	int heightD(AVLTreeNode * temp); 

	void printInorder(AVLTreeNode* node);

	AVLTreeNode* insert(const int &newItem ,AVLTreeNode *& treePtr);
	AVLTreeNode* right(AVLTreeNode *& node);
	AVLTreeNode* left(AVLTreeNode *&node);
	AVLTreeNode* leftRight(AVLTreeNode *&node);
	AVLTreeNode* rightLeft(AVLTreeNode *&node);
	void heightAnalysis();
public:
	AVLTreeNode* root;
};


