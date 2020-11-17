		                               //shubham arya
		                              //NIT Patna
                                     //Samsung Robot car fueling
#include<bits/stdc++.h>
using namespace std;
int n,fans=INT_MAX;
int a[50];
bool vis[50],vis2[50];                     //vis2[] is used for avoiding infinite recursion, if not maintained in case of "Don't fill car & move next" 

void fuel(int r,int pos,int litres,int cnt,int ans)
{
	if((r==1 && a[pos]==1) || (r==2 && a[pos]==2)) cnt++;
	if(cnt>=n)
	{
		//cout<<"solution: "<<ans<<endl;
		if(ans<fans) fans=ans;
		 return;
	}

	int i=pos+1;
    while(i<n+1 && vis[i])i++;
    int j=pos-1;
	while(j>0 && vis[j])j--;

	if(pos==0)
	{
		if(i==n+1) return;
		fuel(1,i,2,cnt,ans+i);
	}
	else if(pos==n+1)
	{
		if(j==0) return;
		fuel(2,j,2,cnt,ans+n+1-j);
	}
	else
	{
		if(r==1)
		{
			if(a[pos]==1)
			{
				if(litres > 1)
			   {
			   	//Fill the car & move next
			   	vis[pos]=true;                         //Mark the car        
				fuel(r,i,litres-1,cnt,ans+i-pos);
 
                //Fill the car & move back
				fuel(r,j,litres-1,cnt,ans+pos-j);
                vis[pos]=false;                       //unmark the car

                //Don't fill the car & move next
                if(i<n+1 && vis2[i]==false)
                {
                	vis2[pos]=true;
                	fuel(r,i,litres,cnt-1,ans+i-pos);
                	vis2[pos]=false;
                }
			  }
			  else if(litres == 1)  
			   {
			   	//when robot has last 1 litre
			   	vis[pos]=true;
				fuel(r,0,litres-1,cnt,ans+pos);
				fuel(r,n+1,litres-1,cnt,ans+n+1-pos);
				vis[pos]=false;

				//Don't fill the car & move next
                if(i<n+1 && vis2[i]==false)
                {
                	vis2[pos]=true;
                	fuel(r,i,litres,cnt-1,ans+i-pos);
                	vis2[pos]=false;
                }
			   }
			}
			else if(a[pos]==2)
			{
				//when fuel carried by robot and car is not same....move next without filling
				fuel(r,i,litres,cnt,ans+i-pos);
			}
		}
		else if(r==2)
		{
			if(a[pos]==2)
			{
				if(litres > 1)
			   {
			   	//Fill the car & move next
			   	vis[pos]=true;
		        fuel(r,j,litres-1,cnt,ans+pos-j);
			
	            //Fill the car & move back		
				fuel(r,i,litres-1,cnt,ans+i-pos);
                vis[pos]=false;

				//Don't fill the car & move next
				if(j>0 && vis2[j]==false)
                {
                	vis2[pos]=true;
                	fuel(r,j,litres,cnt-1,ans+pos-j);
                	vis2[pos]=false;
                }
			  }
			  else if(litres == 1)
			   {
			   	//when robot has last 1 litre
			   	vis[pos]=true;
			   	fuel(r,n+1,litres-1,cnt,ans+n+1-pos);
				fuel(r,0,litres-1,cnt,ans+pos);
				vis[pos]=false;

				//Don't fill the car & move next
				if(j>0 && vis2[j]==false)
                {
                	vis2[pos]=true;
                	fuel(r,j,litres,cnt-1,ans+pos-j);
                	vis2[pos]=false;
                }
			   }
			}
			else if(a[pos]==1)
			{
				//when fuel carried by robot and car is not same....move next without filling
				fuel(r,j,litres,cnt,ans+pos-j);
			}
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
		a[0]=5;a[n+1]=5;
		for(int i=1;i<=n;i++) 
		{
			cin>>a[i];
		}
		for(int i=0;i<=n+1;i++) 
		{
			 vis[i]=false; vis2[i]=false;
		}
		fans=INT_MAX;
		fuel(1,0,2,0,0);
		cout<<fans<<endl;
	}
	return 0;
}

/* TEST CASES
--------------
16                       //test cases (t)
5                       // n
1 2 1 2 1              //element of a[n]
12                    //output

5
2 1 1 2 1
14

4
1 1 1 2
8

1
2
3

2
1 2
4

2
2 1
5

7
1 2 2 1 2 1 2
22

8
1 1 1 1 1 1 1 1
32

8
2 1 1 1 1 1 1 1
36

8
2 2 2 2 2 2 2 2
41

3
1 1 1
5

4
1 1 1 1
8

5
1 1 1 1 1
13

4
2 2 2 2
13

5
2 2 2 2 2
19

4
1 1 2 1
9
*/
