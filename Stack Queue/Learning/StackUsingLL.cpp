class MyStack {
  private:
    StackNode *top;

  public:
    StackNode* head = top;
    void push(int x) {
        // code here
        StackNode* curr = new StackNode(x);
        curr -> next = head;
        head = curr;
    }

    int pop() {
        // code here
        StackNode *op = top;
        if(op -> next == NULL){
            return -1;
        }
        
        while(op -> next  != NULL && op -> next -> next != NULL){
            op = op -> next;
        }
        StackNode *curr = op -> next;
        op -> next = NULL;
        
        return (curr -> data);
    }

    MyStack() { top = NULL; }
};