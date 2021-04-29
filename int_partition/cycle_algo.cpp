#include<bits/stdc++.h>
#include"find.h"
#include"cir_arrange.h"
using namespace std;
int main()
{
	cout<<"Enter number of vertices in the cycle\n";
	int n;
	cin>>n;
	int rds_size=n-2*((n)/3);
	vector<int>polynomial;
	for(int i=1;i<rds_size;i++)
	{
	polynomial.push_back(0);
	}
	while(rds_size<n)
	{
		int rds_count=0;
		int vertex_out_rds=n-rds_size;
		int int_partition=(vertex_out_rds/2);
		vector<vector<int>>partition_vector=find(rds_size,int_partition); //  function 1
		for( auto it=partition_vector.begin();it!=partition_vector.end();it++)
		{
			vector<int>temp=*it;
			rds_count+=int(cir_arrange(temp)*n); // function 2
		}
		//cout<<rds_count<<'\n';
		polynomial.push_back(rds_count);
		polynomial.push_back(0);
		rds_size+=2;
	}
	polynomial.push_back(1);
	for(auto it=polynomial.begin();it!=polynomial.end();it++)
	{
		cout<<*it<<" ";
	}
	cout<<'\n';
	return 0;
}
