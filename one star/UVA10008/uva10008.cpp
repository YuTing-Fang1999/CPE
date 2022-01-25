#include <iostream>
using namespace std;

int N,mx;
char c;
int t[26]={0};

int main(){
	cin>>N;cin.ignore();
	while(N--){
		while((c = getchar())!='\n'){
			c = toupper(c);
			if('A'<=c && c<='Z') {
			    t[c-'A']++;
			    if(t[c-'A']>mx) mx=t[c-'A'];
  			}
		}
	}
	for(int f=mx;f>0;--f){
  		for(int i=0;i<26;++i){
    		if(t[i]==f) printf("%c %d\n",(char)i+'A',f);
  		}
	}
	return 0;
} 
