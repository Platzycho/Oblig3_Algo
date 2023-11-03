#include "General_Tree.h"
#include <iostream>

General_Tree::General_Tree()
{

}

General_Tree::~General_Tree()
{
	deleteAllNodes();
}

TreeNode* General_Tree::createNode(float inData, TreeNode* inParent)
{
	TreeNode* newNode = new TreeNode;
	newNode->data = inData;
	newNode->parent = inParent;
	nodeList.push_back(newNode);

	if(inParent != nullptr){
		addToChildrenList(inParent, newNode);
	}

	return newNode;

}

TreeNode* General_Tree::createRandNode(float inData)
{
	srand(time(nullptr));
	int randomIndex = rand()%nodeList.size() - 1;
	TreeNode* randomNode = nodeList[randomIndex];
	return createNode(inData, randomNode);
}

void General_Tree::deleteNode(TreeNode* inNode)
{
	if(getParent(inNode) != nullptr){
		deleteNodeFromChildrenList(getParent(inNode), inNode);			
	}

	for(int i = 0; i < nodeList.size(); i++){
		if(nodeList[i] == inNode){
			nodeList.erase(nodeList.begin()+i);
			break;
		}
	}

	delete inNode;
}

void General_Tree::deleteNodeFromChildrenList(TreeNode* inNode, TreeNode* nodeToDelete)
{
	for(int i = 0; i < inNode->childrenList.size(); i++){
		if(inNode->childrenList[i] == nodeToDelete){
			inNode->childrenList.erase(inNode->childrenList.begin()+i);
			break;
		}
	}
}

void General_Tree::deleteAllChildren(TreeNode* inNode)
{
	if(isLeaf(inNode)){
		return;
	}

	for(int i = 0; i < nodeList.size(); i++){
		if(nodeList[i] == inNode){
			nodeList.erase(nodeList.begin()+i);
			break;
		}
	}

	for(int i = 0; i < inNode->childrenList.size(); i++){
		deleteAllChildren(inNode->childrenList[i]);
		delete inNode->childrenList[i];
	}

}

void General_Tree::deleteAllNodes()
{
	for(int i = 0; i < nodeList.size(); i++){
		delete nodeList[i];
	}
	nodeList.clear();
}

void General_Tree::addToChildrenList(TreeNode* inNode, TreeNode* inChild)
{
	inNode->childrenList.push_back(inChild);
}

void General_Tree::depthTraversal(TreeNode* inNode)
{
	printData(inNode);
	if(isLeaf(inNode)){
		return;
	}

	for(int i = 0; i < inNode->childrenList.size(); i++){
		depthTraversal(inNode->childrenList[i]);

	}
}

TreeNode* General_Tree::getParent(TreeNode* inNode)
{	
	return inNode->parent;
}

std::vector<TreeNode*> General_Tree::getChildren(TreeNode* inNode)
{
	return inNode->childrenList;
}

TreeNode* General_Tree::getRoot(TreeNode* inNode)
{

	if(isRoot(inNode)){
		return inNode;
	} 
	
	return getRoot(inNode->parent);
}

bool General_Tree::isLeaf(TreeNode* inNode)
{	
	return inNode->childrenList.empty();
}

bool General_Tree::isRoot(TreeNode* inNode)
{	
	return inNode->parent == nullptr;
}

bool General_Tree::isEmpty()
{
	return nodeList.empty();
}

int General_Tree::getSize()
{
	return nodeList.size();
}

int General_Tree::getDepth(TreeNode* inNode)
{
	int depth = 1;
	if(isRoot(inNode)){
		return 0;
	}
	depth += getDepth(getParent(inNode));
	return depth;
}



void General_Tree::printData(TreeNode* inNode)
{
	std::cout<<inNode->data<<std::endl;
}

