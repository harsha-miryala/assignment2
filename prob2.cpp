#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

#define ll long long int
#define PB push_back
#define MP make_pair

class AvoidRoads
{
	public:
	ll numWays(int w, int h,vector < pair<int,int> > v[2]);
};

//for checking the bad paths
int check(int a,int b,int c,int d,vector < pair<int,int> > v[2])
{
	int n=v[0].size();
	for(int i=0;i<n;i++)
	{
		if(v[0][i].first==a&&v[0][i].second==b&&v[1][i].first==c&&v[1][i].second==d)
		return 1;
		if(v[0][i].first==c&&v[0][i].second==d&&v[1][i].first==a&&v[1][i].second==b)
		return 1;
	}
	return 0;
}

ll AvoidRoads::numWays(int w, int h,vector < pair<int,int> > v[2])
{
	ll dp[h+1][w+1];
	for(int i=h;i>=0;i--)
	{
		for(int j=w;j>=0;j--)
		{
			ll ans=0;
			if(j<w)
			{
				//checking with the right one
				if(check(i,j,i,j+1,v)==0)
				ans+=dp[i][j+1];
			}
			if(i<h)
			{
				//checking with the upper one
				if(check(i,j,i+1,j,v)==0)
				ans+=dp[i+1][j];
			}
			if(j==w&&i==h)
			ans=1;
			dp[i][j]=ans;
		}
	}
	return dp[0][0];
}

int main() {
	int w,h;
	cin>>w>>h;
	int k;
	int n=0;
	vector < pair<int,int> > v[2];
	while(cin>>k)
	{
		if(k<0)
		break;
		int p,q,r;
		cin>>p>>q>>r;
		v[0].PB(MP(k,p));
		v[1].PB(MP(q,r));
		n++;
	}
	AvoidRoads xyz;
	cout<<xyz.numWays(w,h,v);
	return 0;
}