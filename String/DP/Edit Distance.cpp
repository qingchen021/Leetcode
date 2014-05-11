/*
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

class Solution 
{

public:
   
 int minDistance(string word1, string word2) 
 {
 
	int len1 = word1.length(), len2 = word2.length();
	if( len1 == 0) return len2;
	if( len2 == 0) return len1;
	int m[len1 + 1][len2 +1];
	for(int i = 0;i <= len1;i++)
	    m[i][0]= i;
	for(int i = 0 ;i <= len2;i++)
	    m[0][i]=i;
	for(int i = 1; i<= len1;i++)
		for(int j = 1 ;j <= len2;j++)
		{
			if(word1[i -1] == word2[j-1])
				m[i][j] = m[i-1][j-1];
			else
			{
				int d1 = m[i-1][j-1] + 1;
				int d2 = m[i-1][j] + 1;
				int d3= m[i][j-1] +1;
				m[i][j]= min(d3, min(d1,d2));
			}
		}
	return m[len1][len2];
 }
};