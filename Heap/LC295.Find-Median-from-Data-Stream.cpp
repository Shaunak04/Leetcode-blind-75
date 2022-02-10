/* Problem Statement:
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
*/

class MedianFinder 
{
public:
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right;// min heap
    
    MedianFinder() 
    {}
   
    void addNum(int num) 
    {
        if(left.empty() || left.top()>num) // if left is empty or left.top > num, push in left becuase left is MAX_HEAP, so top wont be affected here even on insertion
        {
            left.push(num);
        }
        else // else push in right MIN_HEAP
        {
            right.push(num);
        }
        
        // BALANCING
        if(left.size() > (right.size()+1)) // if size(left) > size(right) + 1
        {
            right.push(left.top()); // pop left's top and push in right
            left.pop();
        }
        else if(left.size()+1<right.size())// if size(left) + 1 < size(right)
        {
            left.push(right.top()); // pop right's top and push in left
            right.pop();
        }
    }
    
    double findMedian() 
    {
        if(left.size()==right.size()) // if balanced, return (top(left) + top(right)) / 2
        {
            return left.empty() ? 0 : ((left.top()+right.top())/2.0);
        }
        else // if not balanced heaps, if size(left) > size(right) return top(left), else return top(right)
        {
            return (left.size() > right.size()) ? left.top() : right.top();
        }
    }
};

// Time Complexity: O(NlogN)
// Space Complexity: O(N)