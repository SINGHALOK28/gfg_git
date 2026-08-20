/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
public:
    int ans = INT_MIN;

    int solve(Node* root){

        if(root == nullptr)
            return INT_MAX;

        int leftMin = solve(root->left);
        int rightMin = solve(root->right);

        int minDescendant = min(leftMin, rightMin);

        if(minDescendant != INT_MAX)
            ans = max(ans, root->data - minDescendant);

        return min(root->data, minDescendant);
    }

    int maxDiff(Node* root){
        solve(root);
        return ans;
    }
};