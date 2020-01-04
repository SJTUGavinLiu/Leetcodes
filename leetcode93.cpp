class Solution {
private:
    vector<string> res;
    vector<int> tmp;
    string origin;
public:
    void helper(int pos, int step)
    {

        
        if(step == 4)
        {
            //cout << tmp[0] << tmp[1] <<tmp[2]<<endl;
            if(origin.size() == pos)
                res.push_back(origin.substr(0, tmp[0]) + '.' + origin.substr(tmp[0], tmp[1]-tmp[0]) + '.' + origin.substr(tmp[1], tmp[2]-tmp[1])+  '.' + origin.substr(tmp[2], tmp[3]-tmp[2]));
        }
        else
        {

            if(pos >= origin.size()  || (int(origin.size()) - pos) > (4 - step) * 3)
                return;
            else
            {
                tmp.push_back(pos + 1);
                helper(pos+1,step+1);
                tmp.pop_back();
                if((pos+2) <= origin.size())
                {
                    if(origin[pos] != '0')
                    {
                        tmp.push_back(pos + 2);
                        helper(pos+2,step+1);
                        tmp.pop_back();
                    }               
                }
                
                if((pos+3) <= origin.size())
                    if(origin[pos] == '1' || (origin[pos] == '2' && origin[pos+1] <= '4') || (origin[pos] == '2' && origin[pos+1] == '5' && origin[pos+2] <= '5'))
                    {
                        tmp.push_back(pos + 3);
                        helper(pos+3, step+1);
                        tmp.pop_back();
                    }

            }
        } 
    }
    vector<string> restoreIpAddresses(string s) {
        origin = s;   
        helper(0,0);
        return res;
    }
};