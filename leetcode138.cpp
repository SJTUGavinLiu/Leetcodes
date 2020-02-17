/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)   return head;
        unordered_map<Node*, Node*> d;
        d[head] = new Node(head->val);
        d[NULL] = NULL;

        Node* p = head;

        while(p)
        {
            if(!d.count(p->next))
                d[p->next] = new Node(p->next->val);
            if(!d.count(p->random))
                d[p->random] = new Node(p->random->val);
            d[p]->next = d[p->next];
            d[p]->random = d[p->random];
            p = p -> next;
        }

        return d[head];
         
    }
};