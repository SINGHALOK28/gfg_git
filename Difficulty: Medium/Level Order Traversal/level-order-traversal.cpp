/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        vector<int> result;
        queue<Node*>q;
        q.push(root);
        while( !q.empty()){
            int levelsize=q.size();
            vector<int> temp;
            while(levelsize--){
                Node* t=q.front();
                q.pop();
                
                result.push_back(t->data);
                if(t->left != nullptr)
                    q.push(t->left);
                if(t->right != nullptr)
                    q.push(t->right);
            }
        }
    return result;
    }
};