#include "General_Graph.h"
#include <iostream>
#include <algorithm>
#include <ctime>


General_Graph::General_Graph()
{
}

General_Graph::~General_Graph()
{
	deleteAllNodes();
}

GraphNode* General_Graph::createNode(float inData, GraphNode* inNode)
{
	GraphNode* newNode = new GraphNode;
	newNode->data = inData;
	newNode->node = inNode;
	nodeList.push_back(newNode);

	return newNode;
}

GraphNode* General_Graph::createRandNode(float inData)
{
	srand(time(nullptr));
	int randomIndex = rand()%nodeList.size();
	GraphNode* randomNode = nodeList[randomIndex];
	return createNode(inData, randomNode);
}

void General_Graph::printData(GraphNode* inNode)
{
	std::cout<<inNode->data<<std::endl;
}


void General_Graph::deleteNode(GraphNode* inNode)
{
	for (auto node : nodeList) {
        delete node;
    }
    nodeList.clear();
}

void General_Graph::deleteAllNodes()
{
	for(int i = 0; i < nodeList.size(); i++){
		delete nodeList[i];
	}
	nodeList.clear();
}

std::vector<GraphNode*> General_Graph::adjacentNodes(GraphNode* inNode)
{
	 return inNode->adjacentList;
}

std::vector<std::pair<GraphNode*, GraphNode*>> General_Graph::getEdges() const
{
    std::vector<std::pair<GraphNode*, GraphNode*>> edges;

    for (const auto& node : nodeList) {
        for (const auto& neighbor : node->adjacentList) {
            edges.emplace_back(node, neighbor);
        }
    }

    return edges;
}

std::vector<GraphNode*> General_Graph::getVertices() const
{
    return nodeList;
}

int General_Graph::getSize()
{
	return nodeList.size();
}

bool General_Graph::isEmpty()
{
	return nodeList.empty();
}

void General_Graph::depthFirstTraversal() const
{
    std::vector<bool> visited(nodeList.size(), false);

    for (std::size_t i = 0; i < nodeList.size(); ++i) {
        if (!visited[i]) {
            depthFirstTraversalRecursive(nodeList[i], visited);
        }
    }
}

void General_Graph::depthFirstTraversalRecursive(GraphNode* currentNode, std::vector<bool>& visited) const
{
    auto currentIndex = std::find(nodeList.begin(), nodeList.end(), currentNode) - nodeList.begin();

    visited[currentIndex] = true;

    std::cout << "Visited Node: " << currentNode->data << std::endl;

    for (auto& neighbor : currentNode->adjacentList) {
        auto neighborIndex = std::find(nodeList.begin(), nodeList.end(), neighbor) - nodeList.begin();

        if (!visited[neighborIndex]) {
            depthFirstTraversalRecursive(neighbor, visited);
        }
    }
}