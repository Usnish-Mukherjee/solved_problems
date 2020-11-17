		                               //shubham arya
		                               //NIT Patna
                                       //Samsung 
                                       //mobile problem
#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pi pair<ll,ll>
using namespace std;
const ll MAX=1e13;
const ll MOD=1e9+7;
int n,a[25][25];
bool vis[25][25];
int front=-1,rear=-1;
int k=0;
int select[6]={0};

struct que
{
	int x1,y1;
};

struct que q[626];
struct que q2[626];

void push(int i,int j)
{
	if(front==-1) front=0;
	struct que tmp;
	tmp.x1=i;
	tmp.y1=j;
	q[++rear]=tmp;
}
struct que front2()
{
	return q[front];
}
void pop()
{
  front++;
}

void dfs(int i,int j)
{
	if(vis[i][j]) return;
	vis[i][j]=true;
	q2[k].x1=i;
	q2[k].y1=j; k++;
	if(j+1<n && a[i][j+1]==0 && !vis[i][j+1]) dfs(i,j+1);
	if(i+1<n && a[i+1][j]==0 && !vis[i+1][j]) dfs(i+1,j);
	if(j-1>=0 && a[i][j-1]==0 && !vis[i][j-1]) dfs(i,j-1);
	if(i-1>=0 && a[i-1][j]==0 && !vis[i-1][j]) dfs(i-1,j);
}

int bfs(int i,int j)
{
	if(i<0 || j< 0 || i>=n || j>=n || a[i][j]==0) return -1;
	push(i,j);
	int cnt=0;
	while(front!=rear+1)
	{
		struct que tmp=front2();
		pop();
		int x=tmp.x1;
		int y=tmp.y1;
		int num=a[x][y];
		vis[x][y]=true;
		cnt++;
		if(y+1<n && a[x][y+1]==num && !vis[x][y+1]) push(x,y+1);
	    if(x+1<n && a[x+1][y]==num && !vis[x+1][y]) push(x+1,y);
	    if(y-1>=0 && a[x][y-1]==num && !vis[x][y-1]) push(x,y-1);
	    if(x-1>=0 && a[x-1][y]==num && !vis[x-1][y]) push(x-1,y);
	}
	return cnt;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>a[i][j]; vis[i][j]=false;
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
			   if(a[i][j]==0 && !vis[i][j])
			   {
                  k=0; 
                  int fmxm=-1; int phone=0;
                  memset(select,0,sizeof select);
                  dfs(i,j);                        //used for clustering of zeros(0) and storing them in a queue q2 to use them later.
                  for (int ii = 0; ii <k; ++ii)
                  {
                  	struct que tmp=q2[ii];
                  	int x=tmp.x1;
                  	int y=tmp.y1;

                  	front=-1;rear=-1;
                    int r1=bfs(x,y+1);

                    front=-1;rear=-1;
                    int r2=bfs(x+1,y);

                    front=-1;rear=-1;
                    int r3=bfs(x,y-1);

                    front=-1;rear=-1;
                    int r4=bfs(x-1,y);

                    select[a[x][y+1]]+=r1;
                    select[a[x+1][y]]+=r2;
                    select[a[x][y-1]]+=r3;
                    select[a[x-1][y]]+=r4;
                  }
                  for (int jj = 1; jj < 6; ++jj)
                    {
                    	if(select[jj]>=fmxm)
                    	{
                    		fmxm=select[jj]; phone=jj;
                    	}
                    }
                  for (int p = 0; p < k; ++p)   //replace all the zeros(0) in cluster with highest selling phone
                  {
                     struct que tmp=q2[p];
                     int x=tmp.x1;
                  	 int y=tmp.y1;
                  	 a[x][y]=phone*6;
                  }
                  for (int i = 0; i < n; ++i)
			      {
			      	for (int j = 0; j < n; ++j)
				     {
				   	   if(a[i][j]!=0) vis[i][j]=false;
				     }
			      }
			   }	
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
		    {
			   vis[i][j]=false;
			   if(a[i][j]>5)a[i][j]/=6; 
		    }
		}
		int res=0;
		cout<<endl;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<a[i][j]<<" ";
				if(!vis[i][j])
				{
					front=-1;rear=-1;
					res++; bfs(i,j);
				}
			}
			cout<<endl;
		}
		cout<<res<<endl;
	}
	return 0;
}

/*
1
5
5 5 1 4 4
4 0 2 4 2
5 0 0 2 0
5 4 3 0 1
1 3 3 2 1
out
--11
*/