#include <iostream>
#include <string>
#include <set>
using namespace std;

int N;
int i,j;
char act;
int main(){
	while(cin>>N && N){
		char c_array[2505];
		bool game[55][55] = {false};
		set<string> pattern;
		int idx = 0;
		bool done = false;
		
		for(int move=1;move<=2*N;move++){
			cin>>i>>j>>act;
			
			if(!done){
				
				if(act == '+')      game[i][j] = 1;
				else if(act == '-') game[i][j] = 0;
				
				idx=0;
				for(int u=1;u<=N;++u)
					for(int v=1;v<=N;++v)
						sprintf(&c_array[idx++], "%d", game[u][v]);
				sprintf(&c_array[idx], "%c", '\0');
				
				//if same pattern
				string str(c_array);
				if(pattern.find(str)!=pattern.end()) {
					done = true;
					printf("Player %d wins on move %d\n",move%2+1,move);
				}
				pattern.insert(str);
				
				//rotate 90
				idx=0;
				for(int u=N;u>=1;--u)
					for(int v=1;v<=N;++v)
						sprintf(&c_array[idx++], "%d", game[u][v]);
				sprintf(&c_array[idx], "%c", '\0');
				
				string str2(c_array);
				pattern.insert(str2);
				
				//rotate 180
				idx=0;
				for(int u=N;u>=1;--u)
					for(int v=N;v>=1;--v)
						sprintf(&c_array[idx++], "%d", game[u][v]);
				sprintf(&c_array[idx], "%c", '\0');
				
				string str3(c_array);
				pattern.insert(str3);
				
				//rotate 270
				idx=0;
				for(int u=1;u<=N;++u)
					for(int v=N;v>=1;--v)
						sprintf(&c_array[idx++], "%d", game[u][v]);
				sprintf(&c_array[idx], "%c", '\0');
				
				string str4(c_array);
				pattern.insert(str4);
			}
		}
		if(!done) printf("Draw\n");
	}
	return 0;
}
