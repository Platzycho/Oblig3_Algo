#pragma once
#include <vector>
class GraphNode
{
public:
	float data;
	GraphNode* node;
	std::vector<GraphNode*> adjacentList;
};

class General_Graph
{
public:
	General_Graph();

	~General_Graph();

	std::vector<GraphNode*> nodeList;

	GraphNode* createNode(float inData, GraphNode* inNode);

	GraphNode* createRandNode(float inData);

	void printData(GraphNode* inNode);

	void deleteNode(GraphNode* inNode);

	void deleteAllNodes();

	std::vector<GraphNode*> adjacentNodes(GraphNode* inNode);

	std::vector<std::pair<GraphNode*, GraphNode*>> getEdges() const;

	std::vector<GraphNode*> getVertices() const;

	int getSize();

	bool isEmpty();

	void depthFirstTraversal() const;

private:
	void depthFirstTraversalRecursive(GraphNode* startNode, std::vector<bool>& visited) const;
};

