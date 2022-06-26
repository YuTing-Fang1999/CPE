#include <iostream> 
#include <vector>
using namespace std;
//找出質因數做排列組合
//12 = 2^2 * 3^1
//ans = (2+1(包含0)) * (1+1(包含0)) 
int main(){
	//pow(1e9, 0.5) = 31622.8
	bool table[31625] = {0};
	vector< int > prime;
	for(int i=2;i<=31623;++i){
		if(!table[i]) prime.push_back(i);
		for(int j=i*i;j<=31623;j+=i){
			table[j] = 1;
		}
	}
	int N,L,U;
	cin>>N;
	while(N--){
		cin>>L>>U;
		int max_cnt = 0;
		int max_num = 0;
		for(int i=L;i<=U;++i){
			int now_num = i;
			int now_cnt = 1;
			for(int j=0;j<prime.size();++j){
				int p = 1;
				while(now_num % prime[j] == 0) //prime[j] 是 now_num的質因數 
				{
					p+=1;
					now_num /= prime[j];
				} 
				now_cnt *= p;
				if(now_num==1) break;
			}
			if(now_cnt > max_cnt) {
				max_cnt = now_cnt;	
				max_num = i;
			}
		}
		printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,max_num,max_cnt);
	}
	return 0;
}
