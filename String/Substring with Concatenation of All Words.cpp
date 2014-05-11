/*
 You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter). 
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int allLen = L.size() * L[0].length();
        int strLen = L[0].length();
        vector<int> ret;
        map<string,int> strMap;
        for(int i = 0 ;i < L.size() ;i++)
        {
        	strMap[L[i]] += 1;
        }
       	map<string,int> curMap;
       	int found = 0;
       	int len = S.length();
        for(int i = 0 ;i <= len -allLen;i++)
        {
        	for(int j = i ; j <= len-strLen; j += strLen)
        	{
        		string curStr = S.substr(j,strLen);
        		if(strMap.find(curStr) != strMap.end())
        		{
        			curMap[curStr]++;
        			if(curMap[curStr] > strMap[curStr])
        			{
        				break;
        			}
        			else
        			{
        				found++;
        				if(found == L.size())
        				{
        					ret.push_back(i);
        				}
        			}
        		}
        		else
        			break;
        	}
        	curMap.clear();
        	found = 0;
        }
        return ret;
    }
};