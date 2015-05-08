/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.

*/

class TrieNode {
public:
	// Initialize your data structure here.
	TrieNode() :endNode(false)
	{
		
	}
	void insert(string s)
	{
		TrieNode *tree = this;
		for (int i = 0; i < s.length(); i++)
		{
			if (tree->children.find(s[i]) != tree->children.end())
			{
				tree = tree->children[s[i]];
			}
			else
			{
				auto newNode = new TrieNode();
				tree->children[s[i]] = newNode;
				tree = newNode;
			}
			if (i == s.length() - 1)
			{
				tree->endNode = true;
			}
		}
	}

	bool endNode;

	bool search(string key,bool expectEnd)
	{
		TrieNode *tree = this;
		for (int i = 0; i < key.length(); i++)
		{
			if (tree->children.find(key[i]) == tree->children.end())
				return false;
			else
			{
				tree = tree->children[key[i]];
			}
			if (i == key.length() - 1)
			{
				if (expectEnd == true)
					return tree->endNode == true;
			}
		}
		return true;
	}

	unordered_map<char, TrieNode*> children;
};

class Trie {
public:
	Trie() {
		root = new TrieNode();
	}

	// Inserts a word into the trie.
	void insert(string s) {
		root->insert(s);
	}

	// Returns if the word is in the trie.
	bool search(string key) {
		return root->search(key, true);
	}

	// Returns if there is any word in the trie
	// that starts with the given prefix.
	bool startsWith(string prefix) {
		return root->search(prefix, false);
	}

private:
	TrieNode* root;
};