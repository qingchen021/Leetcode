/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 
*/

class LRUCache{
    //此题主要思路是通过一个hash map快速找到链表的元素，和一个双向链表保存这些最近访问的元素。
	struct ListNode
	{
		ListNode * pre, *next;
		int key, val;
		ListNode(int k, int v) :key(k), val(v), pre(NULL), next(NULL)
		{
		}
	};

	map<int, ListNode* > caches;
	int _capacity;
	int _curCapacity;
	ListNode * least, *most;

public:
	LRUCache(int capacity) {
		least = most = NULL;
		_capacity = capacity;
		_curCapacity = 0;
		caches.clear();
	}

	int get(int key) {
		ListNode * node = Touch(key);
		if (node == NULL)
			return -1;
		else
			return node->val;
	}

	void set(int key, int value) {
		if (caches.find(key) != caches.end())
		{
			Touch(key)->val = value;
		}
		else
		{
			if (_curCapacity < _capacity)
			{
				ListNode * newNode = new ListNode(key, value);
				if (least == NULL)
					least = newNode;
			    if (most == NULL)
					most = newNode;
				else
				{
					most->next = newNode;
					newNode->pre = most;
					most = newNode;
				}
				++_curCapacity;
				caches[key] = newNode;
			}
			else
			{
				int leastKey = least->key;				
				ListNode * node = Touch(leastKey);

				//更新node 
				node->val = value;
				node->key = key;
				
				//更新map的映射
				caches.erase(leastKey);
				caches[key] = node;
			}
		}

	}
	ListNode * Touch(int key)
	{
		if (caches.find(key) != caches.end())
		{
			ListNode * node = caches[key];
		
			//注意这个地方有可能会造成环路
		    if (most == node)
					return most;
				else
				{
				    //判断是否要更新least结点
					if (node == least)
						least = node->next;
						
					//更新当前node的前后node的指针
					if (node->pre != NULL)
						node->pre->next = node->next;
					if (node->next != NULL)
						node->next->pre = node->pre;
						
					//将这个node 移到最后面，并且更新most node 的值
					most->next = node;
					node->pre = most;
					node->next = NULL;
					most = node;
					return node;
				}
		}
		else
			return NULL;
	}
};