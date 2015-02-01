class Solution {
public:
	string fractionToDecimal(int n, int d) {
			if (n == 0)
				return "0";
		string result;
		if (n< 0 ^ d < 0)
			result = "-";
		long long nL = n, dL = d;
		if (nL<0) nL = -nL;
		if (dL<0) dL = -dL;
		result += to_string(nL / dL);
		long long  l = nL%dL;
		if (l != 0)
			result += ".";
		map<long long, int> hash;
		while (l)
		{
			if (hash.find(l) != hash.end())
			{
				result.insert(hash[l], 1, '(');
				result.append(1, ')');
				break;
			}
			hash[l] = result.length();
			l *= 10;
			result += to_string(l / dL);
			l = l % dL;
		}
		return result;
	}
};