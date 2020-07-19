class Solution {
public:
    // 判断 (xk, yk) 是否在「线段」(x1, y1)~(x2, y2) 上
    // 这里的前提是 (xk, yk) 一定在「直线」(x1, y1)~(x2, y2) 上
    bool inside(int x1, int y1, int x2, int y2, int xk, int yk) {
        // 若与 x 轴平行，只需要判断 x 的部分
        // 若与 y 轴平行，只需要判断 y 的部分
        // 若为普通线段，则都要判断
        return (x1 == x2 || (min(x1, x2) <= xk && xk <= max(x1, x2))) && (y1 == y2 || (min(y1, y2) <= yk && yk <= max(y1, y2)));
    }

    void update(vector<double>& ans, double xk, double yk) {
        // 将一个交点与当前 ans 中的结果进行比较
        // 若更优则替换
        if (!ans.size() || xk < ans[0] || (xk == ans[0] && yk < ans[1])) {
            ans = {xk, yk};
        }
    }

    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        int x1 = start1[0], y1 = start1[1];
        int x2 = end1[0], y2 = end1[1];
        int x3 = start2[0], y3 = start2[1];
        int x4 = end2[0], y4 = end2[1];

        vector<double> ans;
        // 判断 (x1, y1)~(x2, y2) 和 (x3, y3)~(x4, y3) 是否平行
        if ((y4 - y3) * (x2 - x1) == (y2 - y1) * (x4 - x3)) {
            if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)) {
                // 判断 (x3, y3) 是否在「线段」(x1, y1)~(x2, y2) 上
                if (inside(x1, y1, x2, y2, x3, y3)) {
                    update(ans, (double)x3, (double)y3);
                }
                // 判断 (x4, y4) 是否在「线段」(x1, y1)~(x2, y2) 上
                if (inside(x1, y1, x2, y2, x4, y4)) {
                    update(ans, (double)x4, (double)y4);
                }
                // 判断 (x1, y1) 是否在「线段」(x3, y3)~(x4, y4) 上
                if (inside(x3, y3, x4, y4, x1, y1)) {
                    update(ans, (double)x1, (double)y1);
                }
                // 判断 (x2, y2) 是否在「线段」(x3, y3)~(x4, y4) 上
                if (inside(x3, y3, x4, y4, x2, y2)) {
                    update(ans, (double)x2, (double)y2);
                }
            }

        }
        else {

            double t1 = (double)(x3 * (y4 - y3) + y1 * (x4 - x3) - y3 * (x4 - x3) - x1 * (y4 - y3)) / ((x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1));
            double t2 = (double)(x1 * (y2 - y1) + y3 * (x2 - x1) - y1 * (x2 - x1) - x3 * (y2 - y1)) / ((x4 - x3) * (y2 - y1) - (x2 - x1) * (y4 - y3));
            if (t1 >= 0.0 && t1 <= 1.0 && t2 >= 0.0 && t2 <= 1.0) {
                ans = {x1 + t1 * (x2 - x1), y1 + t1 * (y2 - y1)};
            }
        }
        return ans;
    }
};


/*
class Solution {
public:
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        if(start1[0] == end1[0] && start2[0] == end2[0])    
        {
            if(start1[0] == start2[0])
            {
                if(start1[1] < end2[1] || start2[1] < end1[1])
                    return {};
                else
                    return {float(start1[0]), float(max(min(start1[1], end1[1]), min(start2[1], end2[1])))};
            }
            else
                return {};
        }
        else if(start1[1] == end1[1] && start2[1] == end2[1])  
        {
            if(start1[1] == start2[1])
            {
                if(start1[0] < end2[0] || start2[0] < end1[0])
                    return {};
                else
                    return {float(max(min(start1[0], end1[0]), min(start2[0], end2[0]))), float(start1[1])};
            }
            else
                return {};
        }

        double x = 111.134;
        double y = 111.134;
        if(start1[0] == end1[0])  
        {
            x = float(start1[1] * end1[0] - start1[0] * end1[1]) / float(start1[1] - end1[1]);
            y = (x * float(start2[1] - end2[1]) + (start2[0] * end2[1] - end2[0] * start1[1])) / float(start2[0] - end2[0]);
            return {x, y};
        }  
        else if(start1[1] == end1[1]) 
        {
            y = float(start1[0] * end1[1] - start1[1] * end1[0]) / float(start1[0] - end1[0]);
            x = (y * (start2[0] - end2[0]) + (end2[0] * start2[1] - start2[0] * end2[1])) / float(start2[1] - end2[1]); 
            return {x, y};
        }   
        else if(start2[0] == end2[0])
        {
            x = float(start2[1] * end2[0] - start2[0] * end2[1]) / float(start2[1] - end2[1]);
            y = (x * float(start1[1] - end1[1]) + (start1[0] * end1[1] - end1[0] * start1[1])) / float(start1[0] - end1[0]);
            return {x, y};
        }    
        else if(start2[1] == end2[1])
        {
            y = float(start2[0] * end2[1] - start2[1] * end2[0]) / float(start2[0] - end2[0]);
            x = (y * (start1[0] - end1[0]) + (end1[0] * start1[1] - start1[0] * end1[1])) / float(start1[1] - end1[1]); 
            return {x, y};
        }    
        cout << 1;
        y = float((start1[0] * end1[1] - end1[0] * start1[1]) * (start2[1] - end2[1]));
        y -= float((start2[0] * end2[1] - end2[0] * start2[1]) * (start1[1] - end1[1]));
        y /= float((start1[0] - end1[0]) * (start2[1] - end2[1]) - (start2[0] - end2[0]) * (start1[1] - end1[1]));
        x = (y * (start1[0] - end1[0]) + (end1[0] * start1[1] - start1[0] * end1[1])) / float(start1[1] - end1[1]); 
        return {x, y};
            
    }
};
*/