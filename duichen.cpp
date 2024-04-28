#include<iostream>
#include<cmath>
using namespace std;

struct node{
	int l;
	int r;
	int val;
}a[1000002];

bool same(int node1,int node2){    //node1，2是编号
	if (node1 ==-1 && node2 ==-1)
		return 1;
	if (node1 ==-1 || node2==-1)
		return 0;
	if (a[node1].val != a[node2].val) 
		return false;
	return same(a[node1].l,a[node2].r)&&same(a[node1].r,a[node2].l);
}

int cnt(int bianhao){
	if (bianhao==-1)
		return 0;
	else
		return cnt(a[bianhao].l)+cnt(a[bianhao].r)+1;
}

int main(){
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i].val;
	for (int i=1;i<=n;i++)
		cin>>a[i].l>>a[i].r;
	int ans=1;
	for (int i=1;i<=n;i++)
		if (same(i,i))
			ans=max(ans,cnt(i));
	cout<<ans;
	return 0;
}

