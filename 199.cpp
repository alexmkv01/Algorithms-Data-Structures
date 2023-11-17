#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x)   : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> nodes;
        vector<int> rightNodes;

        if (root == nullptr){
            return rightNodes;
        }

        nodes.push(root);
        while (!nodes.empty()) {
            int levelSize = nodes.size();
            vector<int> level;
            
            for (int i=0; i<levelSize; i++){
                TreeNode* curr = nodes.front();
                nodes.pop();
                level.push_back(curr->val);

                if (curr->left != nullptr){
                    nodes.push(curr->left);
                }
                if (curr->right != nullptr){
                    nodes.push(curr->right);
                }
            }
            rightNodes.push_back(level.back());
        }
        return rightNodes;
    }
};