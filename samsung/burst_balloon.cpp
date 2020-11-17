		                               //shubham arya
		                               //NIT Patna
                                       //iiit allahabad....samsung noida
#include <bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pi pair<ll,ll>
using namespace std;
const ll MAX=1e13;
const ll MOD=1e9+7;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,test=1;
	cin>>t;
	while(t--)
	{
    int n;
	cin>>n;
	vector<int>a;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	a.insert(a.begin(),1);
	a.push_back(1);
	vector<vector<int> >dp(a.size(),vector<int>(a.size(),0));
    
	for (int l = 1; l <=n; ++l)
	{
		for (int i = 1; i+l <=n+1; ++i) // here we start with 1 so....i+l<=size of array ie from 1 to n+1;		
		{
			int j=i+l-1;
			for (int k = i; k <=j; ++k)
			{
				dp[i][j]=max(dp[i][j], dp[i][k-1]+dp[k+1][j] + (a[i-1]*a[k]*a[j+1]));
			}
		}
	}
	cout<<"#"<<test++<<" "<<dp[1][n]<<endl;
	}
	return 0;
}	
