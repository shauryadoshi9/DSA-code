//Dijikstra's All Pair Shortest Path Algorithm
#include<bits/stdc++.h>
using namespace std;
class dJ{
	enum{max_size=10};
	int a[max_size][max_size];
	public:
		dJ()
		{
			for(int i=0;i<max_size;i++)
			{
				for(int j=0;j<max_size;j++)
				{
					a[i][j]=0;
				}
			}
		}
		void add_edge(int u,int v,int w)
		{
			a[u][v]=w;
		}
		void display(int V)
		{
			for(int i=0;i<V;i++)
			{
				for(int j=0;j<V;j++)
					cout<<a[i][j]<<" ";
				cout<<"\n";
			}
		}
		void dijikstra(int V)
		{
			for(int k=0;k<V;k++)
			{
				for(int i=0;i<V;i++)
				{
					for(int j=0;j<V;j++)
					{
						if(a[i][j] > a[i][k]+a[k][j])
						{
							a[i][j]=a[i][k]+a[k][j];
						}
					}
				}
			}
		}
};
int main()
{
	dJ d;
	int V=3;
	d.add_edge(0,1,4);
	d.add_edge(0,2,11);
	d.add_edge(1,0,6);
	d.add_edge(1,2,2);
	d.add_edge(2,0,3);
	d.add_edge(2,1,400);
	cout<<"Before Replacing values \n\n";
	d.display(V);
	d.dijikstra(V);
	cout<<"\n\n After applying Dijikstra's Algorithm \n\n";
	d.display(V);
	return 0;
}

//Output

/*
Before Replacing values

0 4 11
6 0 2
3 400 0


After applying Dijikstra's Algorithm

0 4 6
5 0 2
3 7 0

*/

/*
visit all nodes from all nodes via node 0
0---> 0 ---->0 = 0+0=0   0
0---> 0 ---->1 = 0+4=4   4        
0---> 0 ---->2 = 0+11=11 11

1--->0 ---->0  =6+0=6    6 
1--->0 ---->1 = 6+4=10   0
1--->0 ---->2 = 6+11=17  2

2--->0 ---->0 = 3+0=3    3
2--->0 ---->1 = 3+4=7    1000 *
2--->0 ---->2 = 3+11=14  0
ao--------------------------
0---> 1 ---->0=4+6=10   0 
0---> 1 ---->1=4+0=4    4 
0---> 1 ---->2=4+2=6    11 *

1---> 1 ---->0=0+6 =6   6 
1---> 1 ---->1=0+0 =0   0
1---> 1 ---->2=0+2 =2   2

2---> 1 ---->0=7+6=13   3
2---> 1 ---->1=7+0=7    7
2---> 1 ---->2=7+2=9    0
--------------------------------
0---> 2 ---->0=6+3=9      0
0---> 2 ---->1=6+7=13     4
0---> 2 ---->2=6+0=6      6

1---> 2 ---->0=2+3=5     6 *
1---> 2 ---->1=2+7=2     0
1---> 2 ---->2=2+0=2      2

2---> 2 ---->0=0+3=3     3
2---> 2 ---->1=0+7=7     7
2---> 2 ---->2=0+0=0      0
*/