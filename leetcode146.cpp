struct Node{
    int key;
    int val;
    Node* pre;
    Node* next;
    Node(int x, int y): key(x), val(y), pre(NULL), next(NULL) {}
    Node(int x, int y, Node* a, Node* b): key(x), val(y), pre(a), next(b) {}
};


class LRUCache {
private:
    int cap;
    int size_;
    Node *head, *tail;
    unordered_map<int, Node*> dict;   // store the key and the value
    void moveTohead(Node* cur)
    {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        Node* tmp = head->next;
        head->next = cur;
        tmp->pre = cur;
        cur->next = tmp;
        cur->pre = head;
    }

    void addTohead(Node* cur)
    {
        Node* tmp = head->next;
        head->next = cur;
        tmp->pre = cur;
        cur->next = tmp;
        cur->pre = head;
    }
    void removeTail()
    {
        Node* tmp = tail->pre;
        dict.erase(tmp->key);
        tmp->pre->next = tail;
        tail->pre = tmp->pre;
        delete tmp;
    }
public:
    LRUCache(int capacity) {
        head = new Node(-1,-1);
        tail = new Node(-1,-1, head, NULL);
        head->next = tail;
        cap = capacity;
        size_ = 0;
    }
    
    int get(int key) {
        if(dict.count(key))
        {
            moveTohead(dict[key]);
            return dict[key]->val;
        }    
        return -1;
    }
    
    void put(int key, int value) {
        if(dict.count(key))
        {
            dict[key]->val = value;
            moveTohead(dict[key]);
            return;
        }    
        if(size_ == cap)
            removeTail();
        else
            size_++;

        
        Node* cur = new Node(key, value);
        addTohead(cur);
        dict[key] = cur;

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */