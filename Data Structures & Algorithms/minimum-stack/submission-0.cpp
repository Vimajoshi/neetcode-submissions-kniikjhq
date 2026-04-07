#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<int> st;     // Main stack to store all elements
    std::stack<int> minSt;  // Auxiliary stack to store minimums

public:
    MinStack() {
        // Constructor
    }
    
    void push(int val) {
        st.push(val);
        
        // If min stack is empty or new value is smaller/equal to current min,
        // push it to min stack.
        // We use <= to handle duplicate minimum values correctly.
        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }
    
    void pop() {
        // If the value being popped is the current minimum,
        // pop it from the min stack as well.
        if (st.top() == minSt.top()) {
            minSt.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};