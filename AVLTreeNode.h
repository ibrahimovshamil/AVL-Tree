#pragma once
class AVLTreeNode
{
public:
	AVLTreeNode();
	~AVLTreeNode();

	AVLTreeNode(const int& item);
	AVLTreeNode(const int& item, AVLTreeNode* leftPtr, AVLTreeNode* rightPtr);

	int item; 		// a data item in the tree
	AVLTreeNode *leftChildPtr;	// pointers to children
	AVLTreeNode *rightChildPtr;
};

