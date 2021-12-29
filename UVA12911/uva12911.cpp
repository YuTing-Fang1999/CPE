#include <iostream>
#include <unordered_map>
using namespace std;

int N,T;
int arr[41];
long long Na,Nb;
int i,j; 
//要使用 unordered_map雜湊表(hash table) O(1)，不然會一直TTL 
unordered_map< long long, int > Sa, Sb;
unordered_map< long long, int >::iterator iter;

int main(){
	while(cin>>N>>T){
		Sa.clear(); Sb.clear();
		for(i=0;i<N;++i) cin>>arr[i];
		
		Nb = N/2;
		Na = N-Nb; //Na要比較大，當只有一個數時才不會出錯
		 
		//要使用long long !! 
		long long sum=0;
		for(i=1;i<(1<<Na);++i){
			sum=0;
			for(j=0;j<Na;++j)
				if(i & (1<<j))
					sum+=arr[j];
			Sa[sum]++;
		}
		
		for(i=1;i<(1<<Nb);++i){
			sum=0;
			for(j=0;j<Nb;++j)
				if(i & (1<<j))
					sum+=arr[Na+j];
			Sb[sum]++;
		}
		
		long long count=0;
		for(iter=Sa.begin();iter!=Sa.end();++iter){
			if(Sb.find(T - iter->first)!=Sb.end()){
				count += 1LL * iter->second * Sb[T - iter->first];
			}
		}
		cout<<count + Sa[T] + Sb[T]<<endl;
	}
	return 0;
}

