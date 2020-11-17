		                               //shubham arya
		                               //NIT Patna
#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pi pair<ll,ll>
using namespace std;
const ll MAX=1e13;
const ll MOD=1e9+7;
int n,m;

struct Node
{
	int data;
	struct Node *next;
};
struct list_
{
	struct Node *head;
};

struct Node *create_node(int d)
{
	struct Node *tmp=(struct Node*)malloc(sizeof(struct Node));
    tmp->data=d;
    tmp->next=NULL;
    return tmp;
}
struct Node *add_edge(int src,int dest,struct list_ *root)
{
	struct Node *tmp=create_node(dest);
	tmp->next=root[src].head;
	root[src].head=tmp;

	/*struct Node *tmp2=create_node(src);
	tmp2->next=root[dest].head;
	root[dest].head=tmp2;*/
}

bool isCycle(struct list_ *root,int *vis,int *rec,int u)
{
	if(!vis[u])
	{
      vis[u]=1;
      rec[u]=1;
      struct Node *tmp=root[u].head;
      while(tmp)
      {
      	int v=tmp->data;
      	if(!vis[v] && isCycle(root,vis,rec,v)) return true;
      	else if(rec[v]) return true;
      	tmp=tmp->next;
      }
	}
	rec[u]=0;
	return false;
}

bool util_cycle(struct list_ *root)
{
	int *vis=new int[n];
	int *rec=new int[n];
	for (int i = 0; i < n; ++i)
	{
		vis[i]=0; rec[i]=0;
	}
	for (int i = 0; i < n; ++i)
	if(isCycle(root,vis,rec,i)) return true;
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	struct list_ *root=(struct list_*)malloc(n*sizeof(struct list_));
    	for (int i = 0; i < n; ++i)
    		root[i].head=NULL;

    	for (int i = 0; i < m; ++i)
    	{
    		int a,b;
    		cin>>a>>b;
    		add_edge(a,b,root);
    	}
        if(util_cycle(root))                      //Also works for disconnected graph
          cout<<"graph contains cycle\n";
          else
          	cout<<"graph does not contain cycle\n";
        free(root);
	return 0;
}