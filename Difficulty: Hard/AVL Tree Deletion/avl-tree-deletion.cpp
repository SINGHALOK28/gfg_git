/* Structure of AVL Tree Node
class Node {
  public:
    int data, height;
    Node *left, *right;

    Node(int x) {
        data = x;
        height = 1;
        left = right = nullptr;
    }
}; */
class Solution {
public:

    // Height nikalna
    int getHeight(Node* root) {
        if (root == NULL)
            return 0;

        return root->height;
    }

    // Balance Factor
    int getBalance(Node* root) {
        if (root == NULL)
            return 0;

        return getHeight(root->left) -
               getHeight(root->right);
    }

    // Right Rotation
    Node* rightRotation(Node* root) {

        Node* child = root->left;
        Node* childRight = child->right;

        // Rotation
        child->right = root;
        root->left = childRight;

        // Height update
        root->height = 1 + max(
            getHeight(root->left),
            getHeight(root->right)
        );

        child->height = 1 + max(
            getHeight(child->left),
            getHeight(child->right)
        );

        return child;
    }

    // Left Rotation
    Node* leftRotation(Node* root) {

        Node* child = root->right;
        Node* childLeft = child->left;

        // Rotation
        child->left = root;
        root->right = childLeft;

        // Height update
        root->height = 1 + max(
            getHeight(root->left),
            getHeight(root->right)
        );

        child->height = 1 + max(
            getHeight(child->left),
            getHeight(child->right)
        );

        return child;
    }

    // Minimum value node
    Node* getMinValueNode(Node* root) {

        Node* current = root;

        while (current->left != NULL) {
            current = current->left;
        }

        return current;
    }

    // Delete Node from AVL
    Node* deleteNode(Node* root, int data) {

        // Tree empty
        if (root == NULL)
            return root;

        // Search left
        if (data < root->data) {

            root->left =
                deleteNode(root->left, data);
        }

        // Search right
        else if (data > root->data) {

            root->right =
                deleteNode(root->right, data);
        }

        // Node found
        else {

            // No child
            if (root->left == NULL &&
                root->right == NULL) {

                delete root;
                return NULL;
            }

            // Only right child
            else if (root->left == NULL) {

                Node* temp = root->right;

                delete root;

                return temp;
            }

            // Only left child
            else if (root->right == NULL) {

                Node* temp = root->left;

                delete root;

                return temp;
            }

            // Two children
            else {

                // Inorder successor
                Node* temp =
                    getMinValueNode(root->right);

                // Successor ki value copy
                root->data = temp->data;

                // Successor delete
                root->right =
                    deleteNode(root->right,
                               temp->data);
            }
        }

        // Height update
        root->height = 1 + max(
            getHeight(root->left),
            getHeight(root->right)
        );

        // Balance factor
        int balance = getBalance(root);

        // LL
        if (balance > 1 &&
            getBalance(root->left) >= 0) {

            return rightRotation(root);
        }

        // LR
        if (balance > 1 &&
            getBalance(root->left) < 0) {

            root->left =
                leftRotation(root->left);

            return rightRotation(root);
        }

        // RR
        if (balance < -1 &&
            getBalance(root->right) <= 0) {

            return leftRotation(root);
        }

        // RL
        if (balance < -1 &&
            getBalance(root->right) > 0) {

            root->right =
                rightRotation(root->right);

            return leftRotation(root);
        }

        return root;
    }
};