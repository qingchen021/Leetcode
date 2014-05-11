/*
 Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack. 
*/

class Solution {
public:
	char *strStr(char *haystack, char *needle) {
		int len1 = strlen(haystack);
		int len2 = strlen(needle);
		if (len1 == 0 && len2 == 0)
			return "";
		char* p2 = needle;
		for (int i = 0; i <= len1 - len2; i++)
		{
			int j;
			for (j = 0; j < len2; j++)
			{
				if (*(haystack + i + j) != *(needle + j))
					break;
			}
			if (j == len2)
				return haystack + i;
		}
		return NULL;
	}
};
