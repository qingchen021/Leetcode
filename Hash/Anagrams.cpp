/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        map<string,const char *> hash;
        for(int i = 0 ;i < strs.size() ; i++)
        {
            string findStr = strs[i];
            sort(findStr.begin(),findStr.end());
            if(hash.find(findStr) != hash.end())
            {
		        if(hash[findStr] != NULL)
		        {
			        ret.push_back(hash[findStr]);
			        hash[findStr] = NULL;
		        }
                ret.push_back(strs[i]);
            }
	    else
	    {
		    hash[findStr] = strs[i].c_str() ;
	    }
        }
        return ret;
    }
};