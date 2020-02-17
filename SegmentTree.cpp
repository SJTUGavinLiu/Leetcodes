#define MAXN 1000


/*
    Sum Version
*/
int t[4*MAXN];

void build(int a[], int v, int tl, int tr)
{
    if(tl == tr)
        t[v] = a[tl];
    
    else
    {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int query(int v, int tl, int tr, int l, int r)
{
    if(l > r)
        return 0;
    if(l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum(v*2,t1, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1) ,r);
}


void update(int v, int tl, int tr, int pos, int val)
{
    if(tl = tr)
        t[v] = val;
    else
    {
        tm = (tl + tr) / 2;
        if(pos <= tm)
            update(v*2, tl, tm, pos, val);
        else    
            update(v*2+1, tm+1, tr, pos, val);
    }
}