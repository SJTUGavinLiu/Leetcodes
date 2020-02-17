class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> new_set;
        multiset<int> height;
        vector<vector<int>> res;

        for(auto& b: buildings)
        {
            new_set.push_back({b[0], -b[2]});   
            new_set.push_back({b[1], b[2]});
        }

        sort(new_set.begin(), new_set.end());
        height.insert(0);
        int pre = 0;
        int cur = 0;
        for(auto line: new_set)
        {
            if(line.second < 0) height.insert(-line.second);
            else    height.erase(height.find(line.second));
            cur = *height.rbegin();
            if(cur != pre)  //转折点
            {
                res.push_back({line.first, cur});
                pre = cur;
            }
        }
        return res;
    }
};
using namespace std;
static const auto __ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

struct Node {
    int height;
    int left;
    int right;
    Node* next;
    Node* pre;
    bool isPoint()
    {
        return left == right;
    }
    Node(int i, int j): left(i), right(j),height(0) {}
    Node(int i, int j, int h): left(i), right(j),height(h) {}
    Node(int h): left(NULL), right(NULL), height(h) {}
};

// 在left，right间加入cur
void connect(Node* left, Node* right, Node* cur)
{
    left->next = cur;
    cur->next = right;
    right->pre = cur;
    cur->pre = left;
}

// 删除结点cur
void deleteNode(Node*cur)
{
    cur->pre->next = cur->next;
    cur->next->pre = cur->pre;
    delete cur;
}

//向左合并，直到遇到头节点或者高度不同的区间
void leftMerge(Node* cur)
{
    Node* pre = cur->pre;
    while(pre->height != -1 && pre->height == cur->height)
    {
        cur->left = pre->left;
        deleteNode(pre);
        pre = cur->pre;
    }
}

//向右合并，直到遇到尾节点或者高度不同的区间
void rightMerge(Node* cur)
{
    Node* next = cur->next;
    while(next->height != -1 && next->height == cur->height)
    {
        cur->right = next->right;
        deleteNode(next);
        next = cur->next;
    }
    
}



class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty())   return {};
        Node* head = new Node(-1);
        Node* tail = new Node(-1);
        Node* tmp = new Node(INT_MIN, INT_MAX);
        connect(head,tail,tmp);


        for(auto& b: buildings)
        {
            int left = b[0];
            int right = b[1];
            int height = b[2];

            Node* cur = head->next;
            while(cur != tail)
            {
                if(left >= cur->right)  
                {
                    cur = cur->next;
                    continue;
                }
                else    //找到头区间
                {
                    if(right <= cur->right) // 若新加入区间正好落在头区间内
                    {
                        if(height > cur->height)
                        {
                            Node* tmp1 = new Node(left,right,height);
                            Node* tmp2 = NULL;
                            if(cur->right != right)
                                tmp2 = new Node(right, cur->right,cur->height);
                            cur->right = left;
                            connect(cur, cur->next, tmp1);
                            if(tmp2)
                                connect(tmp1,tmp1->next,tmp2);
                            if(cur->isPoint())  deleteNode(cur);
                            leftMerge(tmp1);    
                            rightMerge(tmp1);
                            //左右合并相同高度的区间
                        }
                        
                    }
                    else
                    {
                        Node* h = cur;  //头区间
                        Node* t = cur->next;    // 确定尾区间
                        while(t->right < right)
                        {
                            if(height > t->height)
                                t->height = height;
                            t = t->next;
                        }

                        // 单独处理头区间
                        if(h->height < height)
                        {
                            if(h->left == left) // 新建筑物左侧与头区间左侧重合
                            {
                                h->height = height;
                                leftMerge(h);
                            }
                            else
                            {
                                Node* tmp = new Node(left,h->right, height);
                                h->right = left;
                                connect(h,h->next,tmp);
                                h = tmp;
                            }
                        }

                        //单独处理尾区间
                        if(t->height < height)
                        {
                            if(t->right == right)   // 新建筑物右侧与尾区间左侧重合
                            {
                                t->height= height;
                                rightMerge(t);
                            }
                            else
                            {
                                Node* tmp = new Node(right, t->right, t->height);
                                t->right = right;
                                t->height = height;
                                connect(t,t->next,tmp);
                            }
                        }

                        // 合并头尾区间之间的同高度区间
                        Node* p = h;
                        int temp = t->right;
                        while(p!=tail && p->right <= temp)
                        {
                            rightMerge(p);
                            p = p->next;
                        }
                        


                    }
                    break;
                }
            }

        }


        vector<vector<int>> res;
        Node* p = head->next;
        if(p->height != 0)  // INT_MIN也被建筑物覆盖的情况
            res.push_back({p->left, p->height});
        p = p->next;
        
        while(p != tail)
        {
            
            res.push_back({p->left, p->height});
            p = p->next;
        }

        // INT_MAX也被建筑物覆盖的情况
        p = p->pre;
        if(p->height != 0 && p->right == INT_MAX)
            res.push_back({INT_MAX,0});
        return res;
    }
};

struct Node {
    int left;
    bool isLeaf;
    int height;
    Node(): left(0), isLeaf(0), height(0) {}
};



class Solution {
private:
    Node* Tree;
    unordered_map<int, int> dict1;   // 实际坐标->新坐标
    vector<int> dict2;
public:
    void build(int root, int l, int r)
    {
        //cout << root << '\t' << l << '\t' << r << endl;
        //cout << Tree[root].left << endl;
        if(l > r)   return;
        else if(l == r)
        {
            
            Tree[root].left = dict2[l];
            Tree[root].isLeaf = 1;
        }
        else
        {
            int mid = (l + r) / 2;
            build(root*2, l, mid);
            build(root*2+1,mid+1, r);
        }

    }
    void update(int root, int tl, int tr, int l, int r, int height)
    {
        if(l > tr || r < tl)    return;
        else if(l <= tl && tr <= r)
        {
            if(height > Tree[root].height)
                Tree[root].height = height;
        }
        else
        {
            int mid = (tl + tr) / 2;
            update(2*root, tl, mid, l, r, height);
            update(2*root+1, mid+1, tr, l, r, height);
        }
    }

    void queryRes(vector<vector<int>>& res, int root)
    {
        if(Tree[root].isLeaf)
        {
            if(res.empty() || res.back()[1] != Tree[root].height)
                res.push_back({Tree[root].left, Tree[root].height});
        }
        else
        {
            if(Tree[root].height > 0)
            {
                Tree[2*root].height = max(Tree[2*root].height, Tree[root].height);
                Tree[2*root+1].height = max(Tree[2*root+1].height, Tree[root].height);
            }
            queryRes(res, 2*root);
            queryRes(res, 2*root+1);
        }
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if(buildings.empty())   return {};
        set<int> st;
        vector<vector<int>> res;
        for(auto& b: buildings)
        {
            st.insert(b[0]);
            st.insert(b[1]);
        }

        int cnt = 0;
        for(auto iter = st.begin(); iter != st.end(); iter++)
        {
            dict2.push_back(*iter);
            dict1[*iter] = cnt++; 
        }

        Tree = new Node[4*cnt];

        build(1, 0, cnt-1);

        for(auto& b: buildings)
        {
            update(1, 0, cnt-1, dict1[b[0]], dict1[b[1]]-1, b[2]);
        }

        queryRes(res, 1);
        return res;

    }
};