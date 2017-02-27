#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class ZigZag
{
     public:
     int longestZigZag(vector <int>&a);
};	

int ZigZag::longestZigZag(vector <int>&a)
{
	int n=a.size();
	int dp[n][2];
	for(int i=0;i<n;i++)
	{
		dp[i][0]=1;
		dp[i][1]=1;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(a[i]-a[j]>0)
			dp[i][0]=max(dp[j][1]+1,dp[i][0]);
			else if(a[i]-a[j]<0)
			dp[i][1]=max(dp[j][0]+1,dp[i][1]);
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,max(dp[i][0],dp[i][1]));
	}
	return ans;
}

int main() {
	int val;
	vector <int> a;
	while(cin>>val)
	{
		if(val==0)
			break;
		a.push_back(val);
	}
	ZigZag pqr;
	cout<<pqr.longestZigZag(a);
	return 0;
}