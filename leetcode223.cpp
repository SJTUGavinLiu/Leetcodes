class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long area1 = (C-A)*(D-B);
        long area2 = (G-E)*(H-F);
        if(E >= C || F >=D || B >= H || A >=G)  return area1 + area2;
        int leftX = max(A,E);
        int rightX = min(C,G);
        int upY = min(H,D);
        int downY = max(B,F);
        long res = area1 + area2 + long(leftX - rightX) * long(upY-downY);
        return res;
        
    }
};