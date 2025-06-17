#pragma once;
#include <iostream>
#include <string>
#include "Action.h"

using namespace std;

class TreeNode
{
public:
   void insert_node(TreeNode* new_node);
   void print_nodes() const;
   bool find(string value) const;

   /*Helper function for printLevel(int level)
   @peram int 
   @return void*/
   void print_nodesLevel(int level) const;

   /*Helper function for postorder(Action* a)
   @peram Action*
   @return void*/
   void postorderTraversal(Action* a);

private:
   string data;
   TreeNode* left;
   TreeNode* right;
friend class BinarySearchTree;
};
