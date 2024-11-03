class MinStack {
private:
    stack<int> dataStack;  // Stack to store all elements
    stack<int> minStack;   // Stack to store minimum values

public:
    MinStack() {
        // No need to initialize stacks, as they're initialized by default.
    }
    
    void push(int val) {
        dataStack.push(val);
        // If minStack is empty or val is smaller than or equal to the current minimum, push it onto minStack
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        // Check if the element to be popped is the minimum
        if (dataStack.top() == minStack.top()) {
            minStack.pop();
        }
        dataStack.pop();
    }
    
    int top() {
        return dataStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
