/*
 Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if(node == NULL)
    		return NULL;
        queue<UndirectedGraphNode *> que;
        que.push(node);
        map<int,UndirectedGraphNode*> clonedMap;
        clonedMap[node->label] = new UndirectedGraphNode(node->label);
        UndirectedGraphNode * ret = NULL;
        while(!que.empty())
        {
        	UndirectedGraphNode * gNode = que.front();
        	que.pop();
        	UndirectedGraphNode * clonedNode = clonedMap[gNode->label];

        	if(ret == NULL) 
        		ret = clonedNode;
        	//在压栈的过程中，也要set 它的邻居已经被访问了.
        	vector<UndirectedGraphNode *> & nNodes = gNode->neighbors;
        	for(int i = 0; i < nNodes.size() ;i++)
        	{
        		if(clonedMap.find(nNodes[i]->label) != clonedMap.end())
        		{
        		    (clonedNode->neighbors).push_back(clonedMap[nNodes[i]->label]);
        			continue;
        		}
        	
        		que.push(nNodes[i]);
        		UndirectedGraphNode * neighborNode = new UndirectedGraphNode(nNodes[i]->label);
        		clonedMap[nNodes[i]->label] = neighborNode;
        		(clonedNode->neighbors).push_back(neighborNode);
        	}
        }
        return ret;
    }
};