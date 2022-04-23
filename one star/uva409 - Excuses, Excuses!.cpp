#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int countWrod(string sen, string word){
	int n=0;
	stringstream ss(sen);
	string str;
	while(ss>>str){
		if(str == word) ++n;
	}
	return n;
}
void wordToUpper(string &w){
	for(int i=0;i<w.size();++i) w[i] = toupper(w[i]);
}

int K,E,T;
int main(){
	while(cin>>K>>E){
		string words[20], sens[20];
		for(int i=0;i<K;++i) cin>>words[i];
		for(int i=0;i<K;++i) wordToUpper(words[i]);
		getchar(); //del \n
		for(int i=0;i<E;++i) getline(cin,sens[i]);
		
		int maxN = 0;
		vector< int > ans;
		
		for(int i=0;i<E;++i){
			string sen = sens[i];
			for(int j=0;j<sen.size();++j){
				//to upper
				if('a'<=sen[j] && sen[j]<='z') sen[j] = toupper(sen[j]);
				//replace with space
				if(!('A'<=sen[j] && sen[j]<='Z')) sen[j] = ' ';
			}
			
			//count the times
			int n = 0;
			for(int j=0;j<K;++j) n+=countWrod(sen, words[j]);
			
			if(n>maxN){
				ans.clear();
				maxN = n;
				ans.push_back(i);
			}
			else if(n==maxN) ans.push_back(i);
		}
		
		printf("Excuse Set #%d\n",++T);
		for(int i=0;i<ans.size();++i)
			printf("%s\n",sens[ans[i]].c_str());
			
		printf("\n");
	}
	
	return 0;
}
