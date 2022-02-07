#include <iostream>
#include <string.h>
using namespace std;

int T;
int N;
int P;
int h;
bool strike[4000];

int main(){
	cin>>T;
	while(T--){
		cin>>N>>P;
		memset(strike, false, sizeof(strike));
		int count = 0;
		while(P--){
			cin>>h;
			for(int i=h; i<=N; i+=h){
				if(!strike[i] && i%7!=6 && i%7!=0){
					strike[i] = true;
					++count;
				}
			}
		}
		cout<<count<<endl;
	}

	return 0;
}
