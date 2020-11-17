		                               //shubham arya
		                               //NIT Patna
                                  //samsung R&D Delhi
                                  // Research team  
#include <bits/stdc++.h>
#include <string>
#define ll long long int
#define mp make_pair
#define pi pair<ll,ll>
using namespace std;
const ll MAX=1e13;
const ll MOD=1e9+7;
bool vis[500][500];
int check[500][500];
int a[25][25];
int n;
struct abc
{
	int x;
	int y;
};

int bfs(int si,int sj,int di,int dj)
{
	int m=n;
    //pair-->(i,j)...pair((i,j),value(d))
    queue< pair <pair<int,int>,int> >q;
    if(a[si][sj]==1)
    q.push(make_pair(make_pair(si,sj),0));

    while(!q.empty())
    {
    int i=q.front().first.first;
    int j=q.front().first.second;
    vis[i][j]=true;
    int d=q.front().second;
    if(di==i && dj==j)return d;
    q.pop();
    
    if(j+1<m && vis[i][j+1]==false&& a[i][j+1]==1)
    q.push(make_pair(make_pair(i,j+1),d+1));
    if(i+1<n && vis[i+1][j]==false&& a[i+1][j]==1)
    q.push(make_pair(make_pair(i+1,j),d+1));
    if(i-1>=0 && vis[i-1][j]==false&& a[i-1][j]==1)
    q.push(make_pair(make_pair(i-1,j),d+1));
    if(j-1>=0 && vis[i][j-1]==false&& a[i][j-1]==1)
    q.push(make_pair(make_pair(i,j-1),d+1));
    }
    return -1;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int m,rc1,rc2;
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
		cin>>a[i][j],check[i][j]=0;
   

   //string sss=to_string(42);
     cin>>rc1>>rc2;
     struct abc b[m];
     for (int i = 0; i < m; ++i)
     {
        //cin>>b[i].x>>b[i].y;
     	int xx,yy;
     	cin>>xx>>yy;
     	b[i].x=xx;b[i].y=yy;
     	check[xx][yy]=1;
     }
     
     int res=INT_MAX;
     for (int i = 0; i < n; ++i)
     {
     	for (int j = 0; j < n; ++j)
     	{
     		if(a[i][j]==1)
     		{
              int mxm=INT_MIN,flag=0;

               for (int k = 0; k < m; ++k)
               {
                 //make vis[n][n]={false} for each distance calculation;
               	    for (int ii = 0; ii < n; ++ii)
               	    for (int jj = 0; jj < n; ++jj)
               		  vis[ii][jj]=false;

               	  int d=bfs(i,j,b[k].x,b[k].y);
                  if(d!=-1) mxm=max(mxm,d);
                  else 
                  {
                    mxm=INT_MIN;
                    flag=1; break;
                  }
               }
               if(flag==0) res=min(res,mxm);
        }
      }
     }
     cout<<"res="<<res<<endl;
	return 0;
}
/*
TEST CASES:1
8 3
1 1 0 0 0 0 0 0
1 1 0 0 1 1 1 1
1 1 0 0 1 0 0 0
1 1 1 1 1 0 0 0 
0 1 0 0 1 0 0 0 
0 1 0 0 1 0 0 0
0 1 0 0 1 1 1 1
0 1 0 0 0 0 0 0
3 3
1 1
1 7
6 7
mnm=6
TEST CASES:2
8 3
0 0 1 0 0 1 0 0
0 0 1 0 1 1 1 1 
0 0 1 0 1 0 0 1
0 0 1 1 1 0 0 0
0 1 0 0 1 1 1 1
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 
1 5
0 2
1 7
4 7
mnm=5

*/