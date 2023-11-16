#include <iostream>

class TreeNode {
    // attributes
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    
    // constructor
    TreeNode(int val){
        this->val = val;
    }
};
