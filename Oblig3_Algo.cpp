#include <iostream>
#include "General_Tree.h"

int main()
{
    General_Tree bigTree;   
    TreeNode* rootNode = bigTree.createNode(6, nullptr);
    TreeNode* firstChild = bigTree.createNode(3, rootNode);
    bigTree.createNode(10, firstChild);
    TreeNode* firstRandom = bigTree.createRandNode(78);
    TreeNode* secondRandom = bigTree.createRandNode(45);
    TreeNode* thirdRandom = bigTree.createRandNode(109);
    TreeNode* fourthRandom = bigTree.createRandNode(60);
    TreeNode* fifthRandom = bigTree.createRandNode(159);

    bigTree.printData(bigTree.getParent(thirdRandom));

    
    
}

