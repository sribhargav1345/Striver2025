class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* a = head;
        Node* p = new Node(x);
        
        while(a -> next != NULL){
            a = a -> next;
        }
        a -> next = p;
        
        return head;
    }
};
