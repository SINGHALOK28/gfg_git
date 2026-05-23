/*
class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        // code here
        if(x==1){
            Node* temp = head;
            head=head->next;
            delete temp;
            return head;
        }
        else if(x>1){
            Node* curr=head;
            for(int i=1;i<x-1 && curr!=nullptr;i++)
            {
                curr=curr->next;
            }
            
            if(curr!=nullptr && curr->next!=nullptr) {
                //Node* temp=curr->next;
                curr->next =curr->next->next;
                //delete temp;
        }
            
        }
        return head;
        
    }
};