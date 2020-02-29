class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty())    return {};
        multiset<int> window;
        vector<int> res;
        int i = 0;
        while(i < k)
        {
            window.insert(nums[i]);
            i++;
        }
           
        res.push_back(*window.rbegin());
        
        while(i < nums.size())
        {
            window.erase(window.find(nums[i-k]));
            window.insert(nums[i]);
            res.push_back(*window.rbegin());
            i++;
        }
        return res;
    }
};

struct Node{
    int idx;
    Node* next;
    Node* pre;
    Node(int v): idx(v) {}
};


class Solution {
private:
    Node* head;
    Node* tail;
    void show(vector<int>& nums)
    {
        Node* p = head->next;
        while(p!=tail)
        {
            cout << nums[p->idx] << '\t';
            p = p->next;
        }
        cout<<endl;
    }
    void deleteNode(Node* cur)
    {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        delete cur;
    }
    void addBack(vector<int>& nums, int idx)
    {
        Node* p = tail->pre;
        while(p!=head)
        {
            if(nums[p->idx] > nums[idx])    break;
            Node* tmp = p->pre;
            deleteNode(p);
            p = tmp;
        }
        Node* tmp = new Node(idx);
        Node* next = p->next;
        p->next = tmp;
        tmp->next = next;
        next->pre = tmp;
        tmp->pre = p;
    }

    


public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty())    return {};
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->pre = head;

        vector<int> res;

        int i = 0;
        while(i < k)
        {
            addBack(nums, i);
            i++;
        }
        res.push_back(nums[head->next->idx]);

        //show(nums);

        while(i < nums.size())
        {
            addBack(nums, i);
            if(head->next->idx <= (i-k))
                deleteNode(head->next);
            res.push_back(nums[head->next->idx]);
            //show(nums);
            i++;
        }
        return res;
        
    }
};




