#include<iostream>
#include<deque>
using namespace std;
int main(){
	int n;
	cin>>n;
	deque<int> q;
	int k,x=1;
	char xz,fx;
	for (int i=0;i<n;i++){
		cin>>xz>>fx;
		if (xz=='A'){
			if (fx=='L')
				q.push_front(x++);
			else
				q.push_back(x++);
			}
		else{
			cin>>k;
			if (fx=='L'){
				for (int j=0;j<k;j++)
					q.pop_front();
				}
			else{
				for (int j=0;j<k;j++)
					q.pop_back();
				}
			}
		}
	while (!q.empty()){
		cout<<q.front()<<endl;
		q.pop_front();
		}
	return 0;
}
