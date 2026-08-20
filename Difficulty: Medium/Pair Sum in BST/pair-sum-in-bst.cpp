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
  vector<int>result;
   void solve(Node* node){
       if(node==NULL) return;

       solve(node->left);
       result.push_back(node->data);
       solve(node->right);
       return;
   }
  
    bool findTarget(Node *root, int target) {
        // code here.
        solve(root);
        int i=0, j=result.size()-1;
        
        while(i<j){
            if(result[i]+result[j]==target) return true;
            else if(result[i]+result[j]>target){
                j--;
            }
            else if(result[i]+result[j]<target){
                i++;
            }
        }
      return false;
    }
};