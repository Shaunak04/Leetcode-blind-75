/* Problem Statement:
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
*/

class Solution 
{
private:
    unordered_map<Node*, Node*> mp;
public:
    Node* cloneGraph(Node* node) 
    {
        if(!node) return NULL;
        if(mp.find(node)==mp.end())
        {
            mp[node] = new Node(node->val, {});
            for(Node* neighbor : node->neighbors)
            {
                mp[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return mp[node];
    }
};

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)