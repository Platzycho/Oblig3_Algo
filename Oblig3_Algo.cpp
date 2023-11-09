#include <iostream>
#include "General_Tree.h"
#include "General_Graph.h"

int main()
{
   /* General_Tree bigTree;   
    TreeNode* rootNode = bigTree.createNode(6, nullptr);
    TreeNode* firstChild = bigTree.createNode(3, rootNode);
    bigTree.createNode(10, firstChild);
    TreeNode* firstRandom = bigTree.createRandNode(78);
    TreeNode* secondRandom = bigTree.createRandNode(45);
    TreeNode* thirdRandom = bigTree.createRandNode(109);
    TreeNode* fourthRandom = bigTree.createRandNode(60);
    TreeNode* fifthRandom = bigTree.createRandNode(159);

    bigTree.printData(bigTree.getParent(thirdRandom));*/



    General_Graph bigGraf;
    GraphNode* firstNode = bigGraf.createNode(82, nullptr);
    GraphNode* secondNode = bigGraf.createRandNode(107);
    GraphNode* thirdNode = bigGraf.createRandNode(504);
    GraphNode* fourthNode = bigGraf.createRandNode(607);
    GraphNode* fifthNode = bigGraf.createRandNode(7);
    bigGraf.createNode(78, firstNode);

    /*std::vector<std::pair<GraphNode*, GraphNode*>> edges = bigGraf.getEdges();
    for (const auto& edge : edges) {
        std::cout << "Edge: " << edge.first->data << " -> " << edge.second->data << std::endl;
    }*/

    /*std::vector<GraphNode*> vertices = bigGraf.getVertices();
    for (const auto& vertex : vertices) {
        std::cout << "Vertex data: " << vertex->data << std::endl;
    }*/

    std::cout << "Depth-First Traversal:" << std::endl;
    bigGraf.depthFirstTraversal();
}

