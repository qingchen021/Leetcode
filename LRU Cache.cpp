/*
 Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 
*/

class LRUCache{
    struct Node
    {
        Node(int v = INT_MAX,int k=INT_MAX):value(v),key(k),pre(NULL),next(NULL){}
        Node * pre, * next ;
        int value,key;
    };
    int MaxCapacity, _capacity;
    Node head , tail;
    unordered_map<int, Node*> hash;
public:
    LRUCache(int capacity) {
        MaxCapacity = capacity;
        _capacity = 0;
        head.next = & tail;
        tail.pre = & head;
        hash.clear();
    }
    
    int get(int key) {
        if(hash.find(key)!=hash.end())
        {
            Node * node = hash[key];
            node->pre->next = node->next;
            node->next->pre = node->pre;
            MoveToHead(node);
            return node->value;
        }
        else
            return -1;
    }
    
    void set(int key, int value) {
        if(get(key) != -1)
        {
            hash[key]->value = value;
            return ;
        }
        if(_capacity == MaxCapacity)
        {
            Node * removeNode = tail.pre;
            removeNode->pre->next = &tail;
            tail.pre = removeNode->pre;
            delete(removeNode);
            hash.erase(removeNode->key);
            --_capacity;
        }
        Node * n = new Node(value,key);
        hash[key] = n;
        MoveToHead(n);
        _capacity++;
    }
    
    void MoveToHead(Node* node)
    {
        node->next = head.next;
        node->pre = &head;
        (head.next)->pre = node;
        (head.next) = node;
    }
};