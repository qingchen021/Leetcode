/*
 Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.
Corner Cases:

    A line other than the last line might contain only one word. What should you do in this case?
    In this case, that line should be left-justified.
*/

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> res;
        for(int i = 0 ;i < words.size();)
        {
            vector<string> v(1,words[i++]);
            int used = v[0].size();
            for(;i<words.size() && words[i].size()+1+used<=L;i++)
            {
                v.push_back(" " + words[i]);
                used+= words[i].size()+1;
            }
            string line ;
            int space_size = L -used;
            int space_num = v.size()-1;
            if(space_num>0)
            {
                vector<string> v_space(space_num,"");
                for(int j = 0;j<space_size;j++)
                    v_space[j%space_num] += " ";
                for(int j = 0 ; j < space_num;j++)
                {
                    line += v[j] + ((i==words.size())?"":v_space[j]);
                }
            }
            line += v[space_num];
            line.resize(L,' ');
            res.push_back(line);
        }
        return res;
    }
};