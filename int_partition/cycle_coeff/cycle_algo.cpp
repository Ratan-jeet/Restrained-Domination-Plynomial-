//Program to calculate the coefficient of RDP of cycle
//input = order of cycle 'n' and cardinality of rds 'rds_size'
//output = number of rds of cardinality 'rds_size' in cycle of order 'n' {which is the coefficient of x^rds_size in the polynomail D_r(C_n,x)}

#include<bits/stdc++.h>
#include"find_partition.h"
#include"cir_arrange.h"
using namespace std;
int main()
{
	cout<<"Enter number of vertices in the path and rds size\n";
	int n,rds_size;   
	cin>>n>>rds_size;   // input 
	int min_rds=n-2*((n)/3);    // there is not any rds of cardinality rds_size < min_rds and 
	if((n-rds_size)%2!=0 || rds_size>n || rds_size<min_rds) // check rds_size dor which coefficient of x_rds_size is zero
	{
		cout<<"total number of rds of size "<<rds_size<<" in cycle of order "<<n<<" is "<<'0'<<'\n';
	}
	else if(rds_size==n)  // if rds_size==n then there is only one rds with cardinality rds_size
	{
		cout<<"total number of rds of size "<<rds_size<<" in cycle of order "<<n<<" is "<<'1'<<'\n';
	}
	else if(min_rds<=rds_size && rds_size<n) // 
	{
		int rds_count=0;
		int vertex_out_rds=n-rds_size;
		int int_partition=(vertex_out_rds/2); 
		vector<vector<int>>partition_vector=find_partition(rds_size,int_partition); // to calculate the intizer partition of rds_size into (n-rds_size)/2 partition
		for( auto it=partition_vector.begin();it!=partition_vector.end();it++) // for each partition
		{
			vector<int>temp=*it;
			rds_count+=int(cir_arrange(temp)*n); // compute number of circular arrangement and multiply by n
		}
		cout<<"total number of rds of size "<<rds_size<<" in cycle of order "<<n<<" is "<<rds_count<<'\n'; // 
	}
	return 0;
}
