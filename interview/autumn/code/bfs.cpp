#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <queue>
#include <set>
#include <cstdlib>
#include <bitset>
#include <algorithm>
using namespace std;
#define ll long long

int const maxn = 25;
char str[maxn][maxn];
int vis[maxn][maxn];
int w,h;
int ex,ey;

int dir[4][2] = {0,1,0,-1,-1,0,1,0};

struct  node
{
	int x,y;
};

void bfs()
{
	queue<node> q;
	node cur , next;
	cur.x = ex , cur.y = ey;
	vis[ex][ey]=1;
	q.push(cur);
	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		for(int i = 0 ; i < 4 ; i++)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];

			if(next.x>=0&&next.x<h&&next.y>=0&&next.y<w
				&&!vis[next.x][next.y]&&str[next.x][next.y]!='#')
			{
				q.push(next);
				vis[next.x][next.y] = 1;
			}
		}
	}
}

int main()
{
	while(scanf("%d%d",&w,&h)&&(w||h))
	{
		for (int i = 0 ; i < h ; i++)
		{
			scanf("%s",str[i]);
			for(int j = 0 ; j < w ; j++)
			{
				if(str[i][j]=='@')
				{
					ex = i;
					ey = j;
				}
			}
		}
		memset(vis,0,sizeof(vis));
		int ans = 0;
		bfs() ;
		for(int i = 0 ; i < h ; i++)
		{
			for(int j = 0 ; j < w ; j++)
			{
				if(vis[i][j])ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
