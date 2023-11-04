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

	std::vector<GraphNode*> getVertices();

	void insertEdge(GraphNode* source, GraphNode* destination);

	std::vector<std::pair<GraphNode*, GraphNode*>> getEdges();

	void deleteEdge(GraphNode* source, GraphNode* destination);

	void depthFirstTraversal(GraphNode* startNode);

	int getSize();

	bool isEmpty();
};

