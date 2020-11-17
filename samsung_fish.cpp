		                               //shubham arya
		                               //NIT Patna
                                       //Samsung fishing problem
#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pi pair<ll,ll>
using namespace std;
const ll MAX=1e13;
const ll MOD=1e9+7;
int n,fans=INT_MAX;
int pr[3],g[3],fm[3],a[50];

void fun(int);

void fisher_men(int j,int pos,int men)
{
	if(men<=0)
	{
		fun(j+1); return;
	}
	if(a[pos]==0)
	{
		a[pos]=1;
		fisher_men(j,pos,men-1);
		a[pos]=0;
	}
	else
	{
        int left=pos-1,right=pos+1; int l=-1,r=-1;
        while(left>=0 && a[left]!=0)left--;
        if(left!=-1) l=pos-left+1;
        while(right<n && a[right]!=0) right++;
        if(right!=n) r=right-pos+1;

        if(l==-1)                       //when no space in left side
        {
        	a[right]=r; fisher_men(j,pos,men-1); a[right]=0;
        } 
        else if(r==-1)                  //when no space in right side
        {
        	a[left]=l; fisher_men(j,pos,men-1); a[left]=0;
        } 
        // use it (upto next comment),otherwise use next else code inside /*comment*/ for all cases,but it takes more time
        else if(l<r)
        {
        	a[left]=l; fisher_men(j,pos,men-1); a[left]=0;
        }
        else if(r<l)
        {
        	a[right]=r; fisher_men(j,pos,men-1); a[right]=0;
        }
        else if(l==r)                 //for equal distance,go each side
        {
        	a[left]=l; fisher_men(j,pos,men-1); a[left]=0;
        	a[right]=r; fisher_men(j,pos,men-1); a[right]=0;
        }
        /*
        else
        {
        	a[left]=l; fisher_men(j,pos,men-1); a[left]=0;
        	a[right]=r; fisher_men(j,pos,men-1); a[right]=0;
        }*/
	}
}

void fun(int j)
{
  if(j==3)
  {
  	int sum=0;
  	for (int i = 0; i < n; ++i)
  	sum+=a[i];
  //if(sum==18)cout<<"yes"<<endl;
   fans=min(fans,sum);
   return;
  }
  int pos=g[pr[j]];
  int men=fm[pr[j]];
  fisher_men(j,pos,men);
}

void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void permu(int l,int r)
{
	int i;
	if(l==r)
	{
		/*for (int j = 0; j < 3; ++j)
		{
			cout<<pr[j]<<" ";
		}
		cout<<endl;*/
       fun(0);
	}
	else
	{
		for (i = l; i <=r; ++i)
		{
			swap(&pr[l],&pr[i]);
			permu(l+1,r);
			swap(&pr[l],&pr[i]);
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
		cin>>n;
		for (int i = 0; i < 3; ++i)
		{
			int x,y;
			cin>>x>>y;
			g[i]=x-1; fm[i]=y; pr[i]=i;
		}
		for (int i = 0; i < n; ++i)
			a[i]=0;
		permu(0,2);
		cout<<fans<<endl;
		fans=INT_MAX;
	}
	return 0;
}