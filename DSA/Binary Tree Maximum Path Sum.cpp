#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        maxGain(root, max_sum);
        return max_sum;
    }
    
private:
    int maxGain(TreeNode* node, int& max_sum) {
        if (node == nullptr) return 0;
        
        int left_gain = max(maxGain(node->left, max_sum), 0);
        int right_gain = max(maxGain(node->right, max_sum), 0);
        
        int price_newpath = node->val + left_gain + right_gain;
        
        max_sum = max(max_sum, price_newpath);
        
        return node->val + max(left_gain, right_gain);
    }
};

int main() {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;

    return 0;
}
