#include <iostream>
#include <string>
using namespace std;

//注意測資有空白! 
int cnt[128],mx;
string line;
int main(){
	while(getline(cin,line)){
		for(int i=0;i<128;++i) cnt[i]=0;
		for(int i=0;i<line.size();++i){
			int pos = line[i];
			cnt[pos]++;
			if(cnt[pos]> mx) mx=cnt[pos];
		}
		
		for(int f=1;f<=mx;++f){
			for(int i=127;i>=0;--i){
				if(cnt[i] == f) printf("%d %d\n",i,f);
			}
		}
		cout<<endl;
	}
	return 0;
} 
