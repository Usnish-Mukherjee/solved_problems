#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <list>
#include <queue>
#define ll long long
using namespace std;
 
struct my{
  bool up;
  bool down;
  bool left;
  bool right;
};
 
my over[1005][1005];
ll arr[1005][1005];
ll dist[1005][1005];
 
ll solve(ll sx,ll sy,ll n,ll m,ll l)
{
  queue<pair<ll,ll> > q;
  q.push(make_pair(sx,sy));
  dist[sx][sy]=1;
  bool visited[n][m];
  for(ll i=0;i<n;i++)
  {
    for(ll j=0;j<m;j++)
      visited[i][j]=false;
  }
  visited[sx][sy]=true;
  ll ans;
  if(arr[sx][sy]==0){
    ans=0;
    return ans;
  }
  else
    ans=1;
  while(!q.empty())
  {
    sx = q.front().first;
    sy = q.front().second;
    if((sx-1>=0) &&  (arr[sx-1][sy]!=0) && (over[sx][sy].up==true) && (over[sx-1][sy].down==true) && (visited[sx-1][sy]==false))
    {
      dist[sx-1][sy]=dist[sx][sy]+1;
      if(dist[sx-1][sy]<=l){
        q.push(make_pair(sx-1,sy));
        visited[sx-1][sy]=true;
        ans++;
      }
    }
    if((sx+1<n) && (arr[sx+1][sy]!=0) && (over[sx][sy].down==true) && (over[sx+1][sy].up==true) && (visited[sx+1][sy]==false))
    {
      dist[sx+1][sy]=dist[sx][sy]+1;
        if(dist[sx+1][sy]<=l){
          q.push(make_pair(sx+1,sy));
          visited[sx+1][sy]=true;
          ans++;
        }
    }
    if((sy-1>=0) && (arr[sx][sy-1]!=0) && (over[sx][sy].left==true) && (over[sx][sy-1].right==true) && (visited[sx][sy-1]==false))
    {
      dist[sx][sy-1]=dist[sx][sy]+1;
        if(dist[sx][sy-1]<=l){
          q.push(make_pair(sx,sy-1));
          visited[sx][sy-1]=true;
          ans++;
        }
    }
    if((sy+1<m) && (arr[sx][sy+1]!=0) && (over[sx][sy].right==true) && (over[sx][sy+1].left==true) && (visited[sx][sy+1]==false))
    {
      dist[sx][sy+1]=dist[sx][sy]+1;
        if(dist[sx][sy+1]<=l){
          q.push(make_pair(sx,sy+1));
          visited[sx][sy+1]=true;
          ans++;
        }
    }
    q.pop();
  }
  return ans;
}
 
int main()
{
  ios_base::sync_with_stdio(0);
  ll test;
  cin >> test;
  while(test--)
    {
      ll n,m;
      cin >> n >> m;
      ll sx,sy;
      cin >> sx >> sy;
      ll l ;
      cin >> l;
      for(ll i=0;i<n;i++)
      {
        for(ll j=0;j<m;j++){
          cin >> arr[i][j];
          if(arr[i][j]==1){
            over[i][j].up=true;
            over[i][j].down=true;
            over[i][j].left=true;
            over[i][j].right=true;
          }
          else if(arr[i][j]==2){
            over[i][j].up=true;
            over[i][j].down=true;
            over[i][j].left=false;
            over[i][j].right=false;
          }
          else if(arr[i][j]==3){
            over[i][j].up=false;
            over[i][j].down=false;
            over[i][j].left=true;
            over[i][j].right=true;
          }
          else if(arr[i][j]==4){
            over[i][j].up=true;
            over[i][j].down=false;
            over[i][j].left=false;
            over[i][j].right=true;
          }
          else if(arr[i][j]==5){
            over[i][j].up=false;
            over[i][j].down=true;
            over[i][j].left=false;
            over[i][j].right=true;
          }
          else if(arr[i][j]==6){
            over[i][j].up=false;
            over[i][j].down=true;
            over[i][j].left=true;
            over[i][j].right=false;
          }
          else if(arr[i][j]==7){
            over[i][j].up=true;
            over[i][j].down=false;
            over[i][j].left=true;
            over[i][j].right=false;
          }
        }
      }
      cout << solve(sx,sy,n,m,l) << endl;
    }
  return 0;
}