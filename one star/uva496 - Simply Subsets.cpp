#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;

string str;
stringstream ss;
int main(){
	while(getline(cin, str)){
		set< string > A, B, s;
		
		ss.str("");
		ss.clear();
		ss << str;
		while(ss>>str){
			A.insert(str);
		}
		
		getline(cin, str);
		ss.str("");
		ss.clear();
		ss << str;
		while(ss>>str){
			if(A.find(str)!=A.end()){
				s.insert(str);
				A.erase(str);
			}
			else B.insert(str);
		}
		
		if(s.empty()) printf("A and B are disjoint\n");
		else if(A.empty() && B.empty()) printf("A equals B\n");
		else if(A.empty() && !B.empty()) printf("A is a proper subset of B\n");
		else if(!A.empty() && B.empty()) printf("B is a proper subset of A\n");
		else if(!A.empty() && !B.empty()) printf("I'm confused!\n");
	}
	return 0;
}
