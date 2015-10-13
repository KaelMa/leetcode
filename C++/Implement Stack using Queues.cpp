// Implement Stack using Queues

// Implement the following operations of a stack using queues.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.
// Notes:
// You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
// Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
// You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
// Update (2015-06-11):
// The class name of the Java function had been updated to MyStack instead of Stack.


//My solution

class Stack {
public:
    queue<int> q1;
    queue<int> q2;

    // Push element x onto stack.
    void push(int x) 
    {
        q1.push(x);
        
    }

    // Removes the element on top of the stack.
    void pop() 
    {
        int temp;
        while(q1.size() != 1)
        {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        
        q1.pop();
        
        while(!q2.empty())
        {
            temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
    }

    // Get the top element.
    int top() 
    {
        int temp;
        while(!q1.empty())
        {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        
        int res = temp;
        
        while(!q2.empty())
        {
            temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
        
        return res;
        
    }

    // Return whether the stack is empty.
    bool empty()
    {
        return q1.empty();
        
    }
};