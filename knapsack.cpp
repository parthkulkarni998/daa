#include<bits/stdc++.h>

using namespace std;

int knapsack(int profit[],int weight[],int n,int x,vector<int>& ans)
{
	int a[n+1][x+1];
	for(int i=0;i<=n;i++)
		a[i][0]=0;
	for(int i=0;i<=x;i++)
		a[0][i]=0;
		
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=x;j++)
		{
			if(j<weight[i-1])
			{
				a[i][j]=a[i-1][j];
			}
			else
			{
				a[i][j]=max(a[i-1][j],profit[i-1]+a[i-1][j-weight[i-1]]);
			}			
		}
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=x;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	int i=n;
	int j=x;
	while(a[i][j]!=0)
	{
		if(a[i][j]==a[i-1][j])
			i--;
		else
		{
			ans.push_back(i-1);
			j=j-weight[i-1];
			i=i-1;
		}
	}
	
	return a[n][x];
}

int main()
{
	int n,x;
	cout<<"Enter number of elements :\n";
	cin>>n;
	int profit[n];
	int weight[n];
	vector<int>ans;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the profit of item "<<i+1<<"\n";
		cin>>profit[i];
	}
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the weight of item "<<i+1<<"\n";
		cin>>weight[i];
	}
	
	cout<<"Enter the weight of bag:\n";
	cin>>x;
	
	cout<<"Weight of N items are:\n";
	for(int i=0;i<n;i++)
	{
		cout<<weight[i]<<"\t";
	}

	cout<<"\nProfit of N items are:\n";
	for(int i=0;i<n;i++)
	{
		cout<<profit[i]<<"\t";
	}
	
	cout<<"\nThe maximum profit is: \n";
	cout<<knapsack(profit,weight,n,x,ans);
	cout<<"\nItems in knapsack are:\n";
	cout<<"{ ";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<" }";
	cout<<"\n";
	return 0;
}
