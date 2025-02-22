void MyStack ::push(int x) {
    // Your Code
    if(top < 999){
        arr[++top] = (x);
    }
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    if(top>=0){
        return arr[top--];
    }
    else return -1;
}
