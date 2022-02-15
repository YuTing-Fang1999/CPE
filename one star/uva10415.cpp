#include <iostream>
#include <string>
#include <string.h>
#include <map>
using namespace std;

map< char, string > note;
int T;
string str;
int finger[12];

int main(){
	note['c'] = "0111001111";
	note['d'] = "0111001110";
	note['e'] = "0111001100";
	note['f'] = "0111001000";
	note['g'] = "0111000000";
	note['a'] = "0110000000";
	note['b'] = "0100000000";
	note['C'] = "0010000000";
	note['D'] = "1111001110";
	note['E'] = "1111001100";
	note['F'] = "1111001000";
	note['G'] = "1111000000";
	note['A'] = "1110000000";
	note['B'] = "1100000000";
	
	cin>>T; getchar();
	while(T--){
		memset(finger, 0, sizeof(finger));
		getline(cin, str);
		//the song maybe empty!!!
		if(str.size())
			for(int j=0;j<10;++j){
				finger[j] += note[str[0]][j]-'0';
			}
		
		for(int i=1;i<str.size();++i){
			for(int j=0;j<10;++j){
				finger[j] += max(0, note[str[i]][j]-note[str[i-1]][j]);
			}
		}
		
		cout<<finger[0];
		for(int j=1;j<10;++j){
			cout<<" "<<finger[j];
		}
		cout<<endl;
	}
	return 0;
}
