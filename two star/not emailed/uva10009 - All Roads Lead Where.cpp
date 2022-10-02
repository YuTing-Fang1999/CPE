#include <iostream>
#include <vector>
#include <string>
using namespace std;
// ���@�ӵ���i�������u��M�@�ӵ���i-1�������۾F
// => �u�n�O��i-1�O�֧Y�i
// Rome�۷�󵥯�0 
// ��X�@�P�����A���W����root�A���U���N�O�̵u���| 
// �Ĥ@�Ӧr���@�w�O�j�g�A����ӫ����W�٤��|�H�ۦP�r���}�Y 
// =>�̦h26�� 
int main(){
	
	int T, M, N;
	string city1, city2;
	int c1, c2, t1, t2, root;
	cin>>T;
	while(T--){
		while(cin>>M>>N){ //M=���X���D���AN=�߰ݭӼ�
			vector< int > top(26,-1);
			while(M--){
				cin>>city1>>city2;
				c1=city1[0]-'A';
				c2=city2[0]-'A';
				top[c2]=c1; // top of city2 is city1
			}
			
			while(N--){
				//find root
				cin>>city1>>city2;
				c1=city1[0]-'A';
				c2=city2[0]-'A';
				t1=c1;
				t2=c2;
				root='R'-'A'; //�`�N��lroot�n�g�� 
				vector< int > road;
				while(t2>=0){
//					printf("t2=%c\n", t2+'A');
					road.push_back(t2);
					t1=c1;
					while(t1>=0){
//						printf("t1=%c\n", t1+'A');
						if(t1==t2) {
							root=t1;
//							printf("root=%c\n", root+'A');
							break;
						}
						t1=top[t1];
					}
					if(t2==root)break;
					t2=top[t2];
				}
				
				// print road
				t1=c1;
				while(t1!=root){
					printf("%c", t1+'A');
					t1=top[t1];
				}
				for(int i=road.size()-1;i>=0;--i){
					printf("%c", road[i]+'A');
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	
	return 0;
}
