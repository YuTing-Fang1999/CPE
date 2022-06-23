#include <iostream>
#include <string>
#include <vector>
using namespace std;

string line, word="";
int num=0;
vector< string > Wlist;

void addW(string w){//reverse idx
	Wlist.push_back(w); //num = size - idx
}

string num2W(int num){
	int size = Wlist.size();
	int idx = size-num;
	string w = Wlist[idx];
	for(int i = idx; i<size-1;++i)
		Wlist[i] = Wlist[i+1];
		
	Wlist[size-1] = w;
	return w;
}

int main(){
	while(getline(cin, line) && line!= "0"){
		line+='\n';
		for(int i=0; i<line.size(); ++i){
			if(isalpha(line[i])){
				word+=line[i];
			}
			else if(isdigit(line[i])){
				num = num*10 + (line[i]-'0');
			}
			else{
				if(word!="") addW(word);
				if(num!=0) word = num2W(num);
				printf("%s%c",word.c_str(),line[i]);
				word=""; num=0;
			}
		}
	}
	return 0;
}
