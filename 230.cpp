#include <stdio.h>
#include <vector>

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> values;
        values = inOrder(root, values);
        return values[k-1];
    }
    
private:
    vector<int> inOrder(TreeNode* root, vector<int> &values){
        if (root == nullptr){
            return values;
        }
        inOrder(root->left, values);
        values.push_back(root->val);
        inOrder(root->right, values);
        return values;
    }
};