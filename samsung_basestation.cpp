		                               //shubham arya
		                               //NIT Patna
                                       //Base station (Samsung)
#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pi pair<ll,ll>
using namespace std;
const ll MAX=1e13;
const ll MOD=1e9+7;
int n,m;
int a[50][50];
bool vis[50][50];
int fans=0;

void dfs(int d,int sum,int i,int j)
{
	vis[i][j]=true;
	if(d>=4)
	{
		vis[i][j]=false;
		fans=max(fans,sum); return;
	}
	if(j+1<m && vis[i][j+1]==false) dfs(d+1,sum+a[i][j+1],i,j+1);
	if(i+1<n && j+1<m && vis[i+1][j+1]==false)dfs(d+1,sum+a[i+1][j+1],i+1,j+1);
	if(i+1<n && vis[i+1][j]==false) dfs(d+1,sum+a[i+1][j],i+1,j);
	if(i+1<n && j-1>=0 && vis[i+1][j-1]==false) dfs(d+1,sum+a[i+1][j-1],i+1,j-1);
	if(j-1>=0 && vis[i][j-1]==false) dfs(d+1,sum+a[i][j-1],i,j-1);
	if(i-1>=0 && j-1>=0 && vis[i-1][j-1]==false) dfs(d+1,sum+a[i-1][j-1],i-1,j-1);
	if(i-1>=0 && vis[i-1][j]==false) dfs(d+1,sum+a[i-1][j],i-1,j);
	if(i-1>=0 && j+1<m && vis[i-1][j+1]==false) dfs(d+1,sum+a[i-1][j+1],i-1,j+1);
	vis[i][j]=false;
}
void y_shape()
{
	for (int i = 0; i+2 < n; ++i)
	{
		for (int j = 0; j+2< m; ++j)
		{
			//cout<<"hello\n";
			int x1,y1,x2,y2,x3,y3,x4,y4;
			x1=i;y1=j;
			x2=i+1;y2=j+1;
			x3=i;y3=j+2;
			x4=i+2;y4=j+1;
			if((x1+x2+y1+y2)%2==0 && (x2+x3+y2+y3)%2==0 && (x2+x4+y2+y4)%2!=0) fans=max(fans,a[x1][y1]+a[x2][y2]+a[x3][y3]+a[x4][y4]);
			x1=i+2;y1=j;
			x2=i+1;y2=j+1;
			x3=i+2;y3=j+2;
			x4=i;y4=j+1;
			if((x1+x2+y1+y2)%2==0 && (x2+x3+y2+y3)%2==0 && (x2+x4+y2+y4)%2!=0) fans=max(fans,a[x1][y1]+a[x2][y2]+a[x3][y3]+a[x4][y4]);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin>>a[i][j];
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
                memset(vis,false,sizeof vis);
				dfs(1,a[i][j],i,j);
			}
		}
        y_shape();
        cout<<fans*fans<<endl;
	}
	return 0;
}
/*
1
3 4
460` 100 200 320
120 230` 230` 220
10 6000` 200 220
output
-------
6920
*/