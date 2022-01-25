#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Text{
	char c;
	int n;
	Text(char c,int n){
		this->c=c;
		this->n=n;
	}
};
int N;
char c;
int t[26]={0};
vector< Text > texts;

bool cmp(Text a,Text b){
	return a.n>b.n;
}

int main(){
	cin>>N;cin.ignore();
	while(N--){
		while((c = getchar())!='\n'){
			c = toupper(c);
			if('A'<=c && c<='Z') t[c-'A']++;
		}
	}
	for(int i=0;i<26;++i){
		if(t[i]!=0){
			Text text((char)'A'+i,t[i]);
			texts.push_back(text);
		}
	}
	sort(texts.begin(),texts.end(),cmp);
	for(int i=0;i<texts.size();++i){
		printf("%c %d\n",texts[i].c,texts[i].n);
	}
	return 0;
} 
