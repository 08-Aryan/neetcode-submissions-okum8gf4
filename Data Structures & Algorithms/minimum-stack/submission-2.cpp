class MinStack {
        stack<int> minStack;
        stack<int> Stack;
public:
    MinStack() {

    }
    
    void push(int val) {
        Stack.push(val);
        if(minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }
        
    }
    
    void pop() {
        
        if(!minStack.empty() && minStack.top()== Stack.top()){
            minStack.pop();
        }
        if(!Stack.empty()){
            Stack.pop();
        }
        
    }
    
    int top() {
        if(!Stack.empty()){
            return Stack.top();
        }

    }
    
    int getMin() {
        if(!minStack.empty()){
            return minStack.top();
        }

    }
};
