/* Binary Tree Node Structure
class Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
  
  bool solve(Node* root, int target, unordered_map<int, int>& mp) {

      if(root == NULL)
          return false;

      // Check karo required complement pehle mila hai ya nahi
      int required = target - root->data;

      if(mp.find(required) != mp.end())
          return true;

      // Current element store karo
      mp[root->data]++;

      // Left ya right subtree mein search
      return solve(root->left, target, mp) ||
             solve(root->right, target, mp);
  }
  
    bool findTarget(Node *root, int target) {
        // code here.
        unordered_map<int, int> mp;
        return solve(root, target, mp);
    }
};