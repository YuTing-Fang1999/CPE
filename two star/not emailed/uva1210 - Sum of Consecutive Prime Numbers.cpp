#include <iostream>
#include <vector>
#define maxN 10005
using namespace std;

int main(){
	bool notPrime[maxN]={false};
	vector< int > Prime;
	for(int i=2;i<maxN;++i)
		if(!notPrime[i]){
			Prime.push_back(i);
			for(int j=i*i;j<maxN;j+=i)
				notPrime[j]=true;
		}
//	建表沒有比較快(時間一樣) 
//	int table[maxN]={0};
//	int num;
//	for(int i=0;i<Prime.size();++i){
//		num=Prime[i];
//		table[num]++;
//		for(int j=i+1;j<Prime.size();++j){
//			num+=Prime[j];
//			if(num>=maxN) break;
//			table[num]++;
//		}
//	}
	
	int N;
	while(cin>>N && N) {
//		直接算 
        int cnt = 0;
        for (int i = 0; Prime[i] <= N; i++){
            int sum = 0;
            for (int j = i; sum < N; j++){
                sum += Prime[j];
                if (sum == N) {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << "\n";
//		cout<<table[N]<<endl;
	}
	return 0;
}
