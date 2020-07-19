#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;


int main(){
    /*
    std::tr1::unordered_map<int,int> dict;
    dict[233] = 23333;
    dict[244] = 24444;
    std::cout<<dict[233]<<dict[244]<<std::endl;
    */

    queue<int> qu1;
    queue<int> qu2;

    qu1.push(1);
    qu1.push(2);
    qu1.push(3);
    qu1.push(4);
    qu2 = qu1;
    qu1.pop();
    cout << qu1.front() << qu2.front() << endl;
    return 0;
}


static const auto __ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();
// Author: Huahua
// Running time: 39 ms (better than 93.74%)
class Solution {
private:
    int wordLen;
    string end;
    bool isAjac(string& a, string& b)
    {
        // 0: not ajacent or same
        // 1: ajacent

        bool flag = 0;
        for(int i = 0; i < wordLen; i++)
        {
            if(flag && a[i] != b[i])    return 0;
            if(a[i] != b[i])    flag = 1;    
        }
        return flag;
    }

    void backtrack(string& cur, vector<vector<string>>& res, vector<string>& tmp, unordered_map<string, vector<string>>& nextStep)
    {
        if(isAjac(cur,end))
        {
            tmp.push_back(end);
            res.push_back(tmp);
            tmp.pop_back();
        }
        else
        {
            for(auto& word: nextStep[cur])
            {
                tmp.push_back(word);
                backtrack(word, res, tmp, nextStep);
                tmp.pop_back();
            }
        }

    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return ans;
        
        int l = beginWord.length();
        wordLen = l;
        end = endWord;
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        unordered_set<string> q;
        unordered_map<string, vector<string>> children;

        bool found = false;
        bool backward = false;
        dict.erase(endWord);
        while (!q1.empty() && !q2.empty() && !found) {            
            // Always expend the smaller queue first
            if (q1.size() > q2.size()) {
                std::swap(q1, q2);
                backward = !backward;
            }
            
            for (const string& w : q1)
                dict.erase(w);
            for (const string& w : q2)
                dict.erase(w);
                        
            
            
            for (const string& word : q1) {
                string curr = word;
                for (int i = 0; i < l; i++) {
                    char ch = curr[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        curr[i] = j;
                        
                        const string* parent = &word;
                        const string* child = &curr;
                        
                        if (backward)
                            std::swap(parent, child);
                        
                        if (q2.count(curr)) {
                            found = true;
                            children[*parent].push_back(*child);
                        } else if (dict.count(curr) && !found) {
                            q.insert(curr);
                            children[*parent].push_back(*child);
                        }
                    }
                    curr[i] = ch;
                }
            }
            
            std::swap(q, q1);
            q.clear();
        }
        
        if (found) {
            vector<string> path{beginWord};
            backtrack(beginWord, ans, path, children);
            //getPaths(beginWord, endWord, children, path, ans);
        }
        
        return ans;
    }

};





class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> count(501, 0);
        for(auto& num: arr)
        {
            count[num]++;
        }
        for(int i = 500; i >= 1; i++)
        {
            if(count[i] == i)   return i;
        }
        return -1;
    }
};


class Solution {
public:
    int numTeams(vector<int>& rating) {
        vector<int> count(n, 0);
        int res = 0;
        for(int i = 0; i < rating.size(); i++)
        {
            for(int j = i+1; j < rating.size(); j++)
            {
                if(rating[i] < rating[j])
                    count[i]++;
            }
        }

        for(int i = 0; i < rating.size(); i++)
        {
            for(int j = i+1; j < rating.size(); j++)
            {
                if(rating[i] < rating[j])
                    res += count[j];
                else
                    res += (rating.size() - 1 - j - count[j]);
            }
        }
        return res;
    }
};


class UndergroundSystem {
private:
    unordered_map<string, pair<int, int>> dict;
    unordered_map<int, pair<string, int>> id2start;
public:
    UndergroundSystem() {

    }
    
    void checkIn(int id, string stationName, int t) {
        id2start[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string cur = id2start[id].first+stationName;
        if(!dict.count(cur))
            dict[cur]  = {1, t - id2start[id].second};
        else
            dict[cur].first++;
            dict[cur].second += (t - id2start[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        return float(dict[startStation + endStation].second) / dict[startStation + endStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

class Solution {
private:
    int pos;
public:
    long long helper(string& s1, string &s2,int r)
    {
        int l = pos;
        if(l == r)  return s2[l] - s1[l] + 1;
        else
            return (s2[l] - s1[l] + 1) * pow(26, r-l);
    }
    int findGoodStrings(int n, string s1, string s2, string evil) {
        if(s1.substr(0, evil.size()) == evil && (s2.substr(0, evil.size()) == evil))
            return 0;
        long long cnt = 0;
        bool flag = 0;
        for(int i = 0; i < n; i++)
        {
            if(evil.size() + i > n) break;
            if(!flag)
            {
                if(s1[i] == s2[i])  continue;
                else
                {
                    flag = 1;
                    pos = i;
                    if(evil[0] >= s1[i] && evil[0] <= s2[i])
                        cnt += pow(26,n - i - evil.size());
                }
            }
            else
            {
                cnt += helper(s1, s2, i-1) * pow(26,n - i - evil.size());
            }
        }
        cout << helper(s1, s2, n-1) << endl;
        return helper(s1, s2, n-1) - cnt;
    
    }
};



class Solution {
private: 
    int len;
    string s;
    vector<string> res;
    void helper(int l, int r, int pos)
    {
        if(pos == len)
        {
            res.push_back(s);
            return;
        }
        if(l > 0)
        {
            s[pos] = '(';
            helper(l-1,r,pos+1);
        }
        if(l < r)
        {
            s[pos] = ')'; 
            helper(l, r-1, pos+1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        len = 2* n;
        s = string(2*n, '0');
        helper(n, n, 0);
        return res;
    }
};


public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())    return -1;
        int len = nums.size();
        int l = 0;
        int r = len - 1;
        int mid;
        int front = nums.front();
        int back = nums.back();
        if(target == front) return 0;
        if(target == back)  return len-1;
        while(l <= r)
        {
            mid = (l + r) / 2;
            if(nums[mid] == target) return mid;
            else if(target > front && nums[mid] < front)
                r = mid - 1;
            else if(target < back && nums[mid] > back)
                l = mid + 1;
            else
            {
                if(nums[mid] < target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};





/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   return root;
        if(root == p) return p;
        if(root == q)    return q;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        if(l && r)  return root;
        if(l)   return l;
        if(r)   return r;
        return null;
    }
};


