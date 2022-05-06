#include <iostream>
#include <algorithm>
using namespace std;

struct block{
	int L,S; // long, short
};

bool cmp(block a, block b){
	if(a.S!=b.S) return a.S<b.S;
	return a.L<b.L;
}
int main(){
	int L1,L2;
	block blocks[6];
	while(cin>>L1>>L2){
		if(L1<L2){
			blocks[0].S=L1;
			blocks[0].L=L2;
		}else{
			blocks[0].S=L2;
			blocks[0].L=L1;
		}
		
		for( int i=1;i<=5;++i){
			cin>>L1>>L2;
			if(L1<L2){
				blocks[i].S=L1;
				blocks[i].L=L2;
			}else{
				blocks[i].S=L2;
				blocks[i].L=L1;
			}
		}
		sort(blocks, blocks+6, cmp);
		
		bool POSSIBLE = true;
		//�����n�O��⦨�諸��O 
		for( int i=0;i<6;i+=2){
			if(blocks[i].S != blocks[i+1].S) POSSIBLE = false;
			if(blocks[i].L != blocks[i+1].L) POSSIBLE = false;
//			printf("%d %d\n", blocks[i].S, blocks[i].L);
		}
		//�̵u��(����)���e�������n��W�����e���ۦP
		if(blocks[0].L != blocks[4].S) POSSIBLE = false; //S 
		if(blocks[2].L != blocks[4].L) POSSIBLE = false; //L
		
		//�`�N�e4�ӵu��@�w�n�ۦP!!! �_�h�H�Ucase�|�q�L!
		//1 2
		//1 2
		//2 4
		//2 4
		//2 4
		//2 4
		if(blocks[0].S != blocks[2].S) POSSIBLE = false; 
		
		if(POSSIBLE) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
