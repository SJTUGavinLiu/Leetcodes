struct Node{
    int key;
    int value;
    int freq;
    Node* next;
    Node* pre;
    Node(int k, int val): key(k), value(val), freq(1) {}
};


class LFUCache {
private:
    int count;
    int C;
    Node *head, * tail;
    unordered_map<int, Node*> dict;   //
    void addHead(Node* cur)
    {
        Node* p = head->next;
        while(p != tail && cur->freq >= p->freq)
            p = p->next;
        addNode(p, cur);
    }
    void deleteHead()
    {
        Node* tmp = head->next;
        head->next = tmp->next;
        tmp->next->pre = head;
        dict.erase(tmp->key);
        delete(tmp);
    }
    void addNode(Node* next, Node* cur)  
    {
        cur->pre = next->pre;
        cur->next = next;
        next->pre = cur;
        cur->pre->next = cur;
    }
    void removeNode(Node* cur)
    {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre; 
    }
    void move(Node* cur)
    {
        Node* p = cur->next;
        removeNode(cur);
        while(p != tail && cur->freq >= p->freq)
            p = p->next;
        addNode(p, cur);
    }
public:
    LFUCache(int capacity) {
        count = 0;
        C = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if(C == 0 || !dict.count(key))    return -1;
        dict[key]->freq++;
        move(dict[key]);
        return dict[key]->value;
    }
    
    void put(int key, int value) {
        if(C == 0)  return;
        if(dict.count(key))
        {
            dict[key]->value = value;
            dict[key]->freq++;
            move(dict[key]);
        }
        else
        {
            if(count == C)
                deleteHead();
            else
                count++;
            dict[key] = new Node(key, value);
            addHead(dict[key]);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */