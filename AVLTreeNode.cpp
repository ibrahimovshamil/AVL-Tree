
#include "AVLTreeNode.h"
#include <cstddef>

AVLTreeNode::AVLTreeNode()
{
	item = 0;
	leftChildPtr = NULL;
	rightChildPtr = NULL;
}


AVLTreeNode::~AVLTreeNode()
{
}

AVLTreeNode::AVLTreeNode(const int & item)
{
	this->item = item;
	this->leftChildPtr = NULL;
	this->rightChildPtr = NULL;
}

AVLTreeNode::AVLTreeNode(const int & item, AVLTreeNode * leftPtr, AVLTreeNode * rightPtr)
{
	this->item = item;
	this->leftChildPtr = leftChildPtr;
	this->rightChildPtr = rightChildPtr;
}

