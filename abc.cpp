#include<bits/stdc++.h>
using namespace std;

void find(vector<int>& a,vector<int>& present,int currsum,int index,int sum)
{
	if(currsum==sum)
	{
		for(int i=0;i<present.size();i++)
		{
			if(present[i]==1)
			{
				cout<<a[i]<<" ";
			}
		}
		cout<<"\n";
	}
	else if(index==a.size())
		return;
	else
	{
		currsum+=a[index];
		present[index]=1;
		find(a,present,currsum,index+1,sum);
		
		currsum-=a[index];
		present[index]=0;
		find(a,present,currsum,index+1,sum);	
	}
}

int main()
{
	vector<int>a;
	a.push_back(10);
	a.push_back(1);
	a.push_back(2);
	a.push_back(7);
	a.push_back(6);
	a.push_back(1);
	a.push_back(5);
	int sum=8;
	
	vector<int>present(9,-1);
	find(a,present,0,0,sum);
	return 0;
}
