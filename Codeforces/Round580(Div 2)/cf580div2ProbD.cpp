#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
long long num[100005];
int n;
int p[130][130],d[130][130];
int inf=0xffffff;
 
int floyd()
{
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(num[i]&num[j]) p[i][j]=p[j][i]=1,d[i][j]=d[j][i]=1;
			else p[i][j]=p[j][i]=0,d[i][j]=d[j][i]=inf;
		}
	int ans=inf;
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			if(i==k) continue;
			for(int j=0;j<n;j++)
			{
				if(i==j || j==k) continue;
				if(p[j][k] && p[k][i] && d[i][j]<inf)
					ans=min(ans,d[i][j]+2);
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	if(ans==inf) return -1;
	else return ans;
}
 
int main(int argc, char *argv[]) {
	cin >> n;
	int ans =0;
	for(int i=0;i<n;i++)
	{
		cin>> num[i];
		if(!num[i]) 
		{
			--i;
			--n;
		}
	}	
	if(n>126)  printf("3\n");
	else cout << floyd() << endl;
}
