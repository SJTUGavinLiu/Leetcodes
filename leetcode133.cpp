class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)   return NULL;
        Node* clone = new Node(node->val);
        unordered_map<Node*, Node*> dict;
        dict[node] = clone;
        queue<Node*> qu1,qu2;
        qu1.push(node);

        while(!qu1.empty())
        {
            while(!qu1.empty())
            {
                //cout<<"hi"<<endl;
                Node* cur = qu1.front();
                qu1.pop();
                for(auto n: cur->neighbors)
                {
                    if(dict.count(n))
                        dict[cur]->neighbors.push_back(dict[n]);
                    else
                    {
                        //cout<<n->val<<endl;
                        dict[n] = new Node(n->val);
                        dict[cur]->neighbors.push_back(dict[n]);
                        qu2.push(n);
                    }
                }
            }
            swap(qu1,qu2);
        }
        return clone;
    }
};