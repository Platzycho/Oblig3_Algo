#include "General_Graph.h"
#include <iostream>
#include <stack>


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
	int randomIndex = rand()%nodeList.size() - 1;
	GraphNode* randomNode = nodeList[randomIndex];
	return createNode(inData, randomNode);
}

void General_Graph::printData(GraphNode* inNode)
{
	std::cout<<inNode->data<<std::endl;
}


void General_Graph::deleteNode(GraphNode* inNode)
{
	auto it = std::find(nodeList.begin(), nodeList.end(), inNode);
    if (it != nodeList.end()) {
        nodeList.erase(it);
        delete inNode;
    }
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

std::vector<GraphNode*> General_Graph::getVertices()
{
    return nodeList;
}

void General_Graph::insertEdge(GraphNode* source, GraphNode* destination)
{
    source->adjacentList.push_back(destination);
}

void General_Graph::deleteEdge(GraphNode* source, GraphNode* destination)
{
    auto it = std::find(source->adjacentList.begin(), source->adjacentList.end(), destination);
    if (it != source->adjacentList.end()) {
        source->adjacentList.erase(it);
    }
}

std::vector<std::pair<GraphNode*, GraphNode*>> General_Graph::getEdges()
{
    std::vector<std::pair<GraphNode*, GraphNode*>> edges;
    for (auto node : nodeList) {
        for (auto adjacent : node->adjacentList) {
            edges.push_back({node, adjacent});
        }
    }
    return edges;
}

void General_Graph::depthFirstTraversal(GraphNode* startNode)
{
    std::vector<GraphNode*> visited;
    std::stack<GraphNode*> stack;
    stack.push(startNode);

    while (!stack.empty()) {
        GraphNode* current = stack.top();
        stack.pop();

        if (std::find(visited.begin(), visited.end(), current) == visited.end()) {
            visited.push_back(current);
            std::cout << current->data << " ";

            for (auto neighbor : current->adjacentList) {
                stack.push(neighbor);
            }
        }
    }
}

int General_Graph::getSize()
{
	return nodeList.size();
}

bool General_Graph::isEmpty()
{
	return nodeList.empty();
}
