#include<bits/stdc++.h>
using namespace std; 

// A utility function to print an array p[] of size 'n' 
vector<vector<int>>part;
void printArray(int p[], int n,int kth) 
{ 
	vector<int>temp;
	if(n==kth)
	{
	for (int i = 0; i < n; i++) 
	{
	//cout << p[i] << " "; 
	temp.push_back(p[i]);
	}
	part.push_back(temp);
	}
	//cout << endl; 
} 

vector<vector<int>> find(int n,int kth) 
{
       part.clear();	
	int p[n]; // An array to store a partition 
	int k = 0; // Index of last element in a partition 
	p[k] = n; // Initialize first partition as number itself 

	// This loop first prints current partition then generates next 
	// partition. The loop stops when the current partition has all 1s 
	while (true) 
	{ 
		// print current partition 
		printArray(p, k+1,kth); 

		// Generate next partition 

		// Find the rightmost non-one value in p[]. Also, update the 
		// rem_val so that we know how much value can be accommodated 
		int rem_val = 0; 
		while (k >= 0 && p[k] == 1) 
		{ 
			rem_val += p[k]; 
			k--; 
		} 

		// if k < 0, all the values are 1 so there are no more partitions 
		if (k < 0) return part; 

		// Decrease the p[k] found above and adjust the rem_val 
		p[k]--; 
		rem_val++; 


		// If rem_val is more, then the sorted order is violated. Divide 
		// rem_val in different values of size p[k] and copy these values at 
		// different positions after p[k] 
		while (rem_val > p[k]) 
		{ 
			p[k+1] = p[k]; 
			rem_val = rem_val - p[k]; 
			k++; 
		} 

		// Copy rem_val to next position and increment position 
		p[k+1] = rem_val; 
		k++; 
	} 
	return part;
} 
/*
// Driver program to test above functions 
int main() 
{
	int kth;
	int n;
       cin>>n>>kth;	
	cout << "All Unique Partitions of "<<n<<" "<<'\n'; 
	printAllUniqueParts(n); 

	cout << "\nAll Unique Partitions of "<<n+1<<" "<<'\n'; 
	printAllUniqueParts(n+1); 

	cout << "\nAll Unique Partitions of "<<n+2<<" "<<'\n'; 
	printAllUniqueParts(n+2); 

	return 0; 
}*/ 
