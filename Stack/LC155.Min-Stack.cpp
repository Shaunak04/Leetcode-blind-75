/* Problem Statement:
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
*/

class MinStack 
{
public:
    stack<int> main;
    stack<int> aux;
    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        if(main.empty())
        {
            aux.push(val);
        }
        else if(val <= aux.top())
        {
            aux.push(val);
        }
        main.push(val);
    }
    
    void pop() 
    {
        if(main.empty()) return;
        if(main.top() == aux.top()) aux.pop();
        main.pop();
    }
    
    int top() 
    {
        if(main.empty()) return -1;
        return main.top();    
    }
    
    int getMin() 
    {
        if(main.empty()) return -1;
        return aux.top();
    }
};


// Time Complexity:  O(n)
// Space Complexity: O(n)