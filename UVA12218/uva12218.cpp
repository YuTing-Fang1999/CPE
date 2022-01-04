#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

int T;
const int N = 1e7;
bool isPrime[N];
string str;
set<int> ans;

int main(){
	//construct table
	memset(isPrime,true,sizeof(isPrime));
	isPrime[0]=isPrime[1]=false;
	for(int i=2;i<sqrt((float)N);++i){
		if(isPrime[i]){
			for(int j=i*i;j<N;j+=i){
				isPrime[j] = false;
			}
		}
	}

	cin>>T;
	while(T--){
		cin>>str; sort(str.begin(),str.end());
		ans.clear();
		
		for(int i=1;i<(1<<str.size());++i){
			string tmp;
			for(int j=0;j<str.size();++j){
				if(i & (1<<j)){
					tmp+=str[j];
				}
			}
			do{
				int num = stoi(tmp);
				if(isPrime[num]) ans.insert(num);
			}while(next_permutation(tmp.begin(),tmp.end()));
		}
		cout<<ans.size()<<endl;
	}
	return 0;
}
