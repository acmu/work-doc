// 线段树(区间更改,区间查最值)模板

#include <cstdio>
#include <bitset>
#include <iostream>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
#define ll long long
const int maxn = 1e5 + 7;
struct nd {
    int l, r, v, lz;
} seg[maxn << 2];
int n;
inline void pushup(int rt) {
    seg[rt].v = max(seg[rt << 1].v, seg[rt << 1 | 1].v);
}
void pushdown(int rt) {
    if(seg[rt].lz) {
        seg[rt << 1].lz += seg[rt].lz;
        seg[rt << 1 | 1].lz += seg[rt].lz;
        seg[rt << 1].v += seg[rt].lz;
        seg[rt << 1 | 1].v += seg[rt].lz;
        seg[rt].lz = 0;
    }
}
void bulid(int b = 1, int e = n, int rt = 1) {
    seg[rt].l = b;
    seg[rt].r = e;
    if(b == e) {
        seg[rt].v = 0;
        return ;
    }
    int m = b + e >> 1;
    bulid(b, m, rt << 1);
    bulid(m + 1, e, rt << 1 | 1);
    pushup(rt);
}
void update(int l, int r, int xx, int b = 1, int e = n, int rt = 1) {
    if(l <= b && e <= r) {
        seg[rt].lz += xx;
        seg[rt].v += xx;
        return ;
    }
    pushdown(rt);
    int m = b + e >> 1;
    if(l <= m)
        update(l, r, xx, b, m, rt << 1);
    if(r > m)
        update(l, r, xx, m + 1, e, rt << 1 | 1);
    pushup(rt);
}
int query(int l, int r, int b = 1, int e = n, int rt = 1) {
    if(l <= b && e <= r) {
        return seg[rt].v;
    }
    pushdown(rt);
    int m = b + e >> 1;
    int re = 0;
    if(l <= m)
        re = max(re, query(l, r, b, m, rt << 1));
    if(r > m)
        re = max(re, query(l, r, m + 1, e, rt << 1 | 1));
    return re;
}
int main() {
    freopen("E:1.in", "r", stdin);
    n = 10;
    bulid();
    update(3, 5, 1);
    update(3, 5, 1);
    update(3, 5, 1);
    update(5, 6, 1);
    update(2, 8, 1);
    printf("%d\n", query(1, 10));
    printf("%d\n", query(5, 6));
    printf("%d\n", query(1, 3));
    printf("%d\n", query(1, 2));
    for(int i = 0; i < 100; i++) {
        if(seg[i].l) {
            printf("id=%d [%d , %d] val = %d  lz = %d\n", i, seg[i].l, seg[i].r, seg[i].v, seg[i].lz);
        }
    }
    return 0;
}
