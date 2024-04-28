#include<iostream>
using namespace std;

void insert(long long arr[],int & size,long long x){
	if (size==0){
		size++;
		arr[size]=x;
		return;
		}
	size++;
	int i=size;
	for (;arr[i/2]>x;i=i/2)
		arr[i]=arr[i/2];
	arr[i]=x;
}
		
void shanchu(long long arr[],int & size){
	int parent=1;
	int child=2*parent;
	if (size<=1){
		size=0;
		return;
	}
	arr[1]=arr[size--];
	for (;(arr[parent]>arr[child] && child<=size) || (child+1<=size && arr[parent]>arr[child+1]) ;parent=child,child=2*child){
		if (arr[child]>arr[child+1] && size>=child+1)
			child=child+1;
		if (arr[child]<arr[parent]){
			long long tmp=arr[child]; 
			arr[child]=arr[parent];
			arr[parent]=tmp;
		}
	}
}

long long a[1000005]={};

int main(){
	int size=0;
	int n,op;
	long long x;
	cin>>n;
	while (n--){
		cin>>op;
		switch(op){
			case 1:
				cin>>x;
				insert(a,size,x);
				break;
			case 2:
				cout<<a[1]<<endl;
				break;
			case 3:
				shanchu(a,size);
				break;
		}
	}
	return 0;
}
				
