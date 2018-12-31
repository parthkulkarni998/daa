#include<bits/stdc++.h>
using namespace std;

class student
{
	string roll;
	int art_marks;
	int science_marks;
	public:
	string get_roll();
	void put_roll(string);
	int get_art_marks();
	void put_art_marks(int);	
	int get_science_marks();
	void put_science_marks(int);
};

void student::put_roll(string s)
{
	roll=s;
}

void student::put_art_marks(int marks)
{
	art_marks=marks;
}

void student::put_science_marks(int marks)
{
	science_marks=marks;
}

int student::get_art_marks()
{
	return art_marks;
}

int student::get_science_marks()
{
	return science_marks;
}

string student::get_roll()
{
	return roll;
}

void search_arts(student s[],int n,int a,int b)
{
	for(int i=0;i<n;i++)
	{
		if(s[i].get_art_marks()  >=a && s[i].get_art_marks() <=b)
		{
			cout<<s[i].get_roll()<<"\t"<<s[i].get_art_marks()<<"\t"<<s[i].get_art_marks()<<"\n";
		}
	}
}

void search_science(student s[],int n,int a,int b)
{
	for(int i=0;i<n;i++)
	{
		if(s[i].get_science_marks() >=a && s[i].get_science_marks() <=b)
		{
			cout<<s[i].get_roll()<<"\t"<<s[i].get_science_marks()<<"\t"<<s[i].get_science_marks()<<"\n";
		}
	}
}

void rank_arts(student s[],int n)
{
	vector<pair<int,string> > marks;
	for(int i=0;i<n;i++)
	{
		marks.push_back(make_pair(s[i].get_art_marks(),s[i].get_roll()));
	}
	sort(marks.begin(),marks.end());
}

void rank_science(student s[],int n)
{
	vector<pair<int,string> > marks;
	for(int i=0;i<n;i++)
	{
		marks.push_back(make_pair(s[i].get_science_marks(),s[i].get_roll()));
	}
	sort(marks.begin(),marks.end());
}

int main()
{
	int n;
	cout<<"enter the number of students in record:\n";
	cin>>n;
	student s[n];
	string str;
	int x,choice,a,b;
	for(int i=0;i<n;i++)
	{
		cout<<"enter roll number:\n";
		cin>>str;
		s[i].put_roll(str);
		
		cout<<"enter arts mark:\n";
		cin>>x;
		s[i].put_art_marks(x);
		
		cout<<"enter science marks:\n";
		cin>>x;
		s[i].put_science_marks(x);
	}
	
	cout<<"The records are as follows:\n";
	
	for(int i=0;i<n;i++)
	{
		cout<<s[i].get_roll();
		cout<<"\t";
		cout<<s[i].get_art_marks();
		cout<<"\t";
		cout<<s[i].get_science_marks();
		cout<<"\n";
	}
	
	do
	{
		cout<<"Enter choice:\n";
		cout<<"0) break\n1) interval search for arts\n2) interval search for science\n";
		cin>>choice;
		switch(choice)
		{
			case 0:
				break;
			case 1:
				cout<<"enter the lower bound for arts:\n";
				cin>>a;
				cout<<"enter the upper bound for arts:\n";
				cin>>b;
				cout<<"The records are as follows:\n";
				search_arts(s,n,a,b);
				break;
			case 2:
				
				cout<<"enter the lower bound for arts:\n";
				cin>>a;
				cout<<"enter the upper bound for arts:\n";
				cin>>b;
				cout<<"The records are as follows:\n";
				search_science(s,n,a,b);
				break;
		}
	}while(choice!=0);
	
	rank_arts(s,n);
	rank_science(s,n);

}
