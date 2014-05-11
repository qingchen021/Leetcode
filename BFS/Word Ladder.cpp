/*
 Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.

*/

class Solution 
{
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) 
    {
        queue<string> que;
        que.push(start);
        que.push("");
        int ret = 0;
        int level = 1;
        unordered_set<string> visitedHash;
        visitedHash.insert(start);        
        while(!que.empty())
        {
        	string front = que.front();
        	que.pop();
        	if(front == "")
        	{
        		++level;
        		if(!que.empty())
        			que.push("");
        	}
        	else
        	{
        		if(front == end)
        		{
        			ret = level;
        		}
        	
        		for(int i = 0 ;i < end.length();i++)
        		{
        			for(int j =0 ;j < 26;j++)
        			{
        				string tmp = front;
        				tmp[i] = 'a' + j;
        				if(tmp == front || dict.find(tmp) == dict.end()||visitedHash.find(tmp) != visitedHash.end())
        				{
        					continue;
        				}
        				else
        				{
        					que.push(tmp);
        					visitedHash.insert(tmp);
        				}
        			}
        		}
        	}
        }
        return ret;
    }
};