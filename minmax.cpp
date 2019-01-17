#include<bits/stdc++.h>
using namespace std;

void minmax(int a[],int l,int r,int& min,int& max)
{		
	if(l<=r)
	{
		int m=(l+r)/2;
		
		if(a[m]<min)
		{
			min=a[m];
		}
		if(a[m]>max)
		{
			max=a[m];
		}
		
		minmax(a,l,m-1,min,max);
		minmax(a,m+1,r,min,max);
	}
}

int main()
{
	int a[]={2,1,4,6,20,7};
	int min=INT_MAX;
	int max=INT_MIN;
	
	minmax(a,0,5,min,max);
	cout<<"minimum is"<<min<<"\n";
	cout<<"maximum is"<<max<<"\n";
	return 0;
}
