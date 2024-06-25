// // Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

https://leetcode.com/problems/min-stack/description/

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.


class MinStack {
    // Time Complexity: O(1) for each operation
    // Space Complexity: O(N)
    long arr[10000];
    long mini;
    int top_ind;
public:
    MinStack() {
        top_ind=-1;
        mini=LONG_MAX;
    }
    
    void push(int val) {
        long val_l = long(val);
        if(top_ind==9999) return;
        if(top_ind==-1){
            arr[++top_ind]=val_l; mini= val_l;
        }
        else{
            if(val_l<mini){
                arr[++top_ind]= 2*val_l-mini;
                mini= val;
            }
            else{
                arr[++top_ind]=val_l;
            }
        }
    }
    
    void pop() {
        if(top_ind==-1) return;
        if(arr[top_ind]<mini){
            mini= 2*mini-arr[top_ind];
            top_ind--; 
        }
        else{
            top_ind--;
        }
    }
    
    int top() {
        if(top_ind==-1) return -1;

        if(arr[top_ind]<mini){
            return mini;
        }
        return arr[top_ind];
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */