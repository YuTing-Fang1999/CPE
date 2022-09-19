#include <iostream>
#define maxN 1299710
using namespace std;

int main(){
	bool table[maxN] = {0};
	int prime[100000];
	int cur = 0;
	for(int i=2;i<maxN;++i){
		if(table[i]==0){
			prime[cur++]=i;
			for(int j=i+i;j<maxN;j+=i){
				table[j]=1;
			}
		}
	}
	
	int k;
	while(cin>>k && k) {
		if(table[k]==0) cout<<0<<endl;
		else{
			int left=0,right=100000;
			int mid = (left+right)/2;;
			while(left<=right){
				if(prime[mid]<k) left = mid+1;
				else if(prime[mid]>k) right = mid-1;
				mid = (left+right)/2;
//				printf("L %d, R %d\n",left,right);
			}
//			cout<<mid<<endl;
			cout<<prime[mid+1]-prime[mid]<<endl;
		}
	}
	return 0;
}
