#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<long long int> v;
vector<int> z;

int fzero(long long int n){
	if(z.size() > n) return z[n];
 	long long int i = v.size();
 	long long int num;
 	if(i<=n){
 		num = v[i-1];
	 	while(i<=n){
	 		num*=i;
	 		v.push_back(num);
	 		//printf("F(%lld)=%lld\n",i,v[i]);
	 		++i;
	 	}
	 }
	 else{
	 	num = v[n];
	 }
 	
 	printf("num=%lld\n",num);
 	int zero = 0;
 	while(num%10 == 0){
 		zero++;
 		num/=10;
	 }
	printf("zero=%lld\n",zero);
	z.push_back(zero);
 	return zero;
 }
 		

int main(){
	v.push_back(1);
	z.push_back(1);
	long long int low, high;
	while(cin>>low>>high){
		if(!low && !high) break;
		set<long long int> mySet;
		for(long long int i=low;i<=high;++i){
			mySet.insert(fzero(i));
		}
		cout<<mySet.size()<<endl;

	}
	return 0;
}
