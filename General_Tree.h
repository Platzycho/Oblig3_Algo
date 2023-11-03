#pragma once
#include <vector>


class TreeNode
{
public:
	float data;
	TreeNode* parent;
	std::vector<TreeNode*> childrenList;

};

class General_Tree
{
public:
	General_Tree();

	~General_Tree();

	std::vector<TreeNode*> nodeList;

	TreeNode* createNode(float inData, TreeNode* inParent);

	TreeNode* createRandNode(float inData);

	void deleteNode(TreeNode* inNode);

	void deleteNodeFromChildrenList(TreeNode* inNode, TreeNode* nodeToDelete);

	void deleteAllChildren(TreeNode* inNode);

	void deleteAllNodes();

	void addToChildrenList(TreeNode* inNode, TreeNode* inChild);

	void depthTraversal(TreeNode* inNode);

	TreeNode* getParent(TreeNode* inNode);

	std::vector<TreeNode*> getChildren(TreeNode* inNode);

	TreeNode* getRoot(TreeNode* inNode);

	bool isLeaf(TreeNode* inNode);

	bool isRoot(TreeNode* inNode);

	bool isEmpty();

	int getSize();

	int getDepth(TreeNode* inNode);

	void printData(TreeNode* inNode);
};

