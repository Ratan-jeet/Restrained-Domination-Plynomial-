#include<bits/stdc++.h>
using namespace std;
/*void subset(vector<int>&vertex,vector<vector<int>>&vertex_subset,vector<int>sub_set,int n)
{
	if(n>=vertex.size())
		return;
	if(sub_set.size()!=0)
		vertex_subset.push_back(sub_set);
	subset(vertex,vertex_subset,sub_set,n+1);
	sub_set.push_back(vertex[n]);
	subset(vertex,vertex_subset,sub_set,n+1);
}*/
void print(vector<int>arr);
vector<vector<int>>subset(vector<int>&vertex,int n)
{
	if(n==(int)vertex.size())
		return {{}};
	vector<vector<int>>vertex_subset,temp;
	temp=subset(vertex,n+1);
	for(int i=0;i<temp.size();i++)
	{
		vertex_subset.push_back(temp[i]);
	}
//	cout<<vertex[n]<<" ";
	for(int i=0;i<temp.size();i++)
        {
		temp[i].push_back(vertex[n]);
                vertex_subset.push_back(temp[i]);
        }
	return vertex_subset;
}
void print_vector(vector<vector<int>>arr)
{
	cout<<"Cardinility   \n";
	for(auto it=arr.begin();it!=arr.end();it++)
	{
		cout<<(*it).size()<<" ";
		print(*it);
	}
}
void print(vector<int>arr)
{
	for(int i=0;i<arr.size();i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
}
int main()
{
	cout<<"Enter number of vertices  and  edges  ";
	int n,m;
	cin>>n>>m;
	int mat[n+1][n+1];
	vector<int>vertex;
	for(int i=0;i<n;i++)
        {
                vertex.push_back(n-i-1);
        }
	vector<vector<int>>vertex_subset=subset(vertex,0);   //  find all subset possible 
	
	map<int,vector<vector<int>>>cardinility;          // map acc to card. of set eg 1={{1},{2},{3}}  ,   2={{1,2},{1,3}}
	for(auto it=vertex_subset.begin();it!=vertex_subset.end();it++)
	{
		if((*it).size()!=0)                       // neglect null set
			cardinility[(*it).size()].push_back(*it);
		//print(*it);
	}
//	map<int,vector<vector<int>>>::iterator it;

	/*for(it=cardinility.begin();it!=cardinility.end();it++)
	{
		print_vector(it->second);
	}*/

	memset(mat,0,sizeof(mat));
	int t=1;
	unordered_map<int,int>deg;
	while(t==1)
	{
		int a,b;
		cout<<"Enter all edge (u,v) don't enter again (v,u)   \n";
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			mat[a][b]=1;
			mat[b][a]=1;
			deg[a]++;
			deg[b]++;
		}


		// start the coding
		////////////////////////////////// Dominational Polynomial //////////////////////////////////////

		vector<int>coff_vect;
		coff_vect.resize(n+1);
//		memset(coff_vect,0,sizeof(coff_vect));
		//coff_vect.push_back(0);  // coff of x^0
		cout<<"Domination Polynomial\n";
		for(int i=1;i<=n;i++)
		{
			int coff=0;     //coff of i
			if(i==1)                        //   for single vertex in S (domination set)  will have degree n-1
			{
				for(int j=0;j<n;j++)
				{
					if(deg[j]==n-1)
						coff++;
				}
			}
			else if(i==n)
			{
				coff=1;
			}
			else if(i==n-1)
			{
				for(int k=0;k<n;k++)
				{
					if(deg[k]>=1)
						coff++;
				}
			}
			else
			{
				vector<vector<int>>temp=cardinility[i];        //  set of cardinility i
				for(auto itr=temp.begin();itr!=temp.end();itr++)  //// for each set of cardinility i
				{
					vector<int>tp=*itr;
					//cout<<"tp[0] tp[1] "<<tp[0]<<" "<<tp[1]<<'\n';
					set<int>other;                         // neighbourhood vertex out of set
					int flag=0;
					for(int p=0;p<tp.size();p++)
					{
						if(deg[tp[p]]==n-1)
						{
							coff++;
							flag=1;
							break;
						}
						else
						{
							for(int k=0;k<n;k++)
							{
								if(mat[tp[p]][k]==1)
								{
									if(find(tp.begin(),tp.end(),k)==tp.end())//not in S
									{
										other.insert(k);  // other= Neighbourhood(S)
									}
								}
							}
						}
					}
					if(flag==0)
					{
						if(other.size()+i==n)//if  then N(S)=(other)==V[G]\S then S is Domination set of card i
							coff++;      //number of domination set of card i increase by 1
					}
				}
			}
			coff_vect[i]=coff;  // total number of domination set of card i = coff
		}

		//for(int i=0;i<=n;i++)
		//{
		//	cout<<coff_vect[i]<<"x^"<<i<<" ";
		//}
		//cout<<'\n';
		

		//Non-Dominational Polynomial
		cout<<"Non-Domination Polynomial\n";
		vector<int>coff_vect1;
		coff_vect1.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			int coff=0;
			/*if(i==1 && i!=n-1)
			{
				for(int j=0;j<n;j++)
				{
					if(deg[j]==n-1)
						coff++;
				}
			}
			else*/ if(i==n-1)
			{
				coff=0;
			}
			else if(i==n)
			{
				coff=1;
			}
			else
			{
				vector<vector<int>>temp=cardinility[i];        //  set of cardinility i
                                for(auto itr=temp.begin();itr!=temp.end();itr++)  //// for each set of cardinility i
                                {
                                        vector<int>tp=*itr;
                                        set<int>other;                         //all vertex out of set  
					for(int j=0;j<n;j++)
					{
						if(find(tp.begin(),tp.end(),j)==tp.end())
						{
							other.insert(j);
						}
					}
					int cont=0;
					for(auto j:other)
					{
						if(deg[j]>1)
						{
							int t1=0,t2=0;
							for(int l=0;l<n;l++)
							{
								if(mat[j][l]==1)
								{
									if(other.find(l)!=other.end())               //if connection is out side 
										t1=1;                  
									else                                         // if connection is inside
										t2=1;
								}
								if(t1==1 && t2==1)                                   // if connected both out and in
								{
									cont++;
									break;                                     // no need to check further connection
								}
							}
						}
					}
					if(cont==other.size())
						coff++;
					////////////////////////////////////////////////////////////////////////////////////*
                                        /*for(int p=0;p<tp.size();p++)
                                        {
                                                //if(deg[tp[p]]==n-1)
                                                //{
                                                //        coff++;
                                                //        flag=1;
                                                //        break;
                                                //}
                                                //else
                                                //{
                                                        for(int k=0;k<n;k++)
                                                        {
                                                                if(mat[tp[p]][k]==1)
                                                                {
                                                                        if(find(tp.begin(),tp.end(),k)==tp.end())//not in S
                                                                        {
                                                                                other.insert(k);  // other= Neighbourhood(S)
                                                                        }
                                                                }
                                                        }
                                               // }
                                        }
                                        if(flag==0)
                                        {
						set<int>other1;
						for(auto k:other)
						{
							for(int p=0;p<n;p++)
							{
								if(mat[k][p]==1)
								{
									if(other.find(p)!=other.end())
									{
										other1.insert(k);
									}
								}
							}
						}
                                                if(other1.size()+i==n)//if  then N(S)=(other)==V[G]\S then S is Domination set of card i
                                                        coff++;      //number of domination set of card i increase by 1
                                        }*/
                                }
			}
			coff_vect1[i]=coff;
		}
		for(int i=1;i<=n;i++)
                {
                        //cout<<coff_vect1[i]<<"x^"<<i<<" ";
			cout<<coff_vect1[i]<<" ";
                }
		cout<<'\n';
		//cout<<"Press 1 to continue   ";
		//cin>>t;
		t--;
	}
	return 0;
}
