#include<iostream>
using namespace std;
int main()
{
	int i,n,a[50][50],j,k,m[50],l,h=0,y=0,s,q[50],b[50][50],g,f=1,t,y1=0,w,w1,w2,y2=0;
	cout<<"Enter the total number of transaction:\n";
	cin>>n;
	cout<<"Enter the Minimum Acceptance Level\n";
	cin>>g;
	cout<<"Enter the maximum number of items per transaction:\n";
	cin>>s;
	cout<<"Enter the transaction:\n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter items for Transaction "<<i+1<<"\n";
		cin>>k;
		cout<<"\n";
		for(j=0;j<k;j++)
		{
			cin>>a[i][j];
			if(h == 0)
			{
				m[0]=a[i][j];
				h++;
			}
			else
			{
				for(l=0;l<h;l++)
				{
					if(m[l] != a[i][j])
					{
						y = 1;
					}
					else
					{
						y = 0;
						break;
					}
				}
			}
			if(y == 1)
			{
				m[h] = a[i][j];
				h++;
				y = 0;
			}
		}
	}
	
	y = 0;
	
	cout<<"\nThe Entered Matrix is:\n";
	for(i=0;i<n;i++)
	{
		for(j=0;j<s;j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<"\n";
	}
	
	cout<<"\nThe Unique Elements are :\n";
	for(i=0;i<h;i++)
	{
		cout<<m[i]<<"\t";
	}
	
	cout<<"\n";
	
	for(t=0;t<f;t++)
	{
		cout<<"\nC"<<t+1;
		for(k=0;k<h;k++)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<s;j++)
				{
					if(a[i][j] == m[k])
					{
						y++;
						q[k] = y;
						b[i][j] = a[i][j];
						a[i][j] = 0;
					}
				}
			}
			y = 0;
		}
		for(k=0;k<h;k++)
		{
			cout<<"\n";
			cout<<m[k]<<":\t"<<q[k];
		}
		cout<<"\n";
		cout<<"\nL"<<t+1;
		for(k=0;k<h;k++)
		{
			if(q[k]<g)
			{
				for(i=k;i<h;i++)
				{
					m[i]=m[i+1];
					q[i]=q[i+1];
				}				
				h--;
				k--;
			}
			else
			{
				cout<<"\n";
				cout<<m[k]<<":\t"<<q[k];		
			}
		}
	}	
	
	cout<<"\n";
	cout<<"\nC2:\n";
	for(t=0;t<h;t++)
	{
		w = m[t];
		for(k=t+1;k<h;k++)
		{
			w1 = m[k];
			for(i=0;i<n;i++)
			{
				for(j=0;j<s;j++)
				{
					if(w == b[i][j])
					{
						y++;
					}
					if(b[i][j] == w1)
					{
						y1++;
					}
				}
				if(y == y1)
					continue;
				else
				{
					if(y>y1)
						y = y - 1;
					else if(y1>y)
						y1 = y1 - 1;
				}
					
			}
			cout<<w<<","<<w1<<":\t"<<y<<"\n";
			y = 0;
			y1 = 0;
		}
	}
	
	cout<<"\nL2:\n";
	for(t=0;t<h;t++)
	{
		w = m[t];
		for(k=t+1;k<h;k++)
		{
			w1 = m[k];
			for(i=0;i<n;i++)
			{
				for(j=0;j<s;j++)
				{
					if(w == b[i][j])
					{
						y++;
					}
					if(b[i][j] == w1)
					{
						y1++;
					}
				}
				if(y == y1)
					continue;
				else
				{
					if(y>y1)
						y = y - 1;
					else if(y1>y)
						y1 = y1 - 1;
				}
					
			}
			if(y>=g)
			{
				cout<<w<<","<<w1<<":\t"<<y<<"\n";
			}
			y = 0;
			y1 = 0;
		}
	}	
	
	cout<<"\n";
	cout<<"\nC3:\n";
	for(t=0;t<h-1;t++)
	{
		w = m[t];
		for(k=t+1;k<h-1;k++)
		{
			w1 = m[k];
			w2 = m[k+1];
			for(i=0;i<n;i++)
			{
				for(j=0;j<s;j++)
				{
					if(w == b[i][j])
					{
						y++;
					}
					if(b[i][j] == w1)
					{
						y1++;
					}
					if(b[i][j] == w2)
					{
						y2++;
					}
				}
				if(y == y1 && y1 == y2 && y == y2)
					continue;
				else
				{
					if(y == 0 || y1 == 0 || y2 == 0)
						y=y1=y2=0;
					else if(y>y1 || y>y2)
					{
						y = y - 1;
					}				
					else if(y1>y || y1>y2)
						y1 = y1 - 1;
					else if(y2>y || y2>y1)
						y2 = y2 - 1;
				}					
			}
			if(y>=g)
				cout<<w<<","<<w1<<","<<w2<<":\t"<<y<<"\n";
			y = 0;
			y1 = 0;
			y2 = 0;
		}
	}
	
	cout<<"\nL3:\n";
	for(t=0;t<h-2;t++)
	{
		w = m[t];
		for(k=t+1;k<h-1;k++)
		{
			w1 = m[k];
			w2 = m[k+1];
			for(i=0;i<n;i++)
			{
				for(j=0;j<s;j++)
				{
					if(w == b[i][j])
					{
						y++;
					}
					if(b[i][j] == w1)
					{
						y1++;
					}
					if(b[i][j] == w2)
					{
						y2++;
					}
				}
				if(y == y1 && y1 == y2 && y == y2)
					continue;
				else
				{
					if(y == 0 || y1 == 0 || y2 == 0)
						y=y1=y2=0;
					else if(y>y1 || y>y2)
					{
						y = y - 1;
					}				
					else if(y1>y || y1>y2)
						y1 = y1 - 1;
					else if(y2>y || y2>y1)
						y2 = y2 - 1;
				}		
			}
			if(y>=g)
				cout<<w<<","<<w1<<","<<w2<<":\t"<<y<<"\n";
			y = 0;
			y1 = 0;
			y2 = 0;
		}
	}	
	
	
	return 0;
}
