#include <iostream>
#include <string>
using namespace std;

string preTree, inTree;
int preIdx;

// ���ŦA�ۤv�g�@�� 
// preorder  (root, left subtree, right subtree) �Ĥ@���I��N�L�X 
// inorder   (left subtree, root, right subtree) �ĤG���I��N�L�X  
// postorder (left subtree, right subtree, root) �ĤT���I��N�L�X 
// �p�G���w�@�G���𪺤���-��ǡB�Ϊ̤���-�e�ǳ��i�H�D�o�ߤ@���G����A���O�e��-��ǫh�L�k�D�o 

// ���ǥ� preorder �o�� root
// �A�� inorder ���� (left subtree, root, right subtree)

struct Tree{
	Tree* right;
	Tree* left;
	char val;
	Tree(char v){
		this->left = NULL;
		this->right = NULL;
		this->val = v;
	}
};

Tree* buildTree(int left, int right){
	Tree* root = new Tree(preTree[preIdx++]);
	if(left<right){
		int rootIdx = 0;
		for(int i=left;i<=right;++i){
			if(inTree[i] == root->val){
				rootIdx = i;
				break;
			}
		}
		if(left<rootIdx) root->left = buildTree(left, rootIdx-1);
		if(right>rootIdx) root->right = buildTree(rootIdx+1, right);
	}	
	
	return root;
}

void postoder(Tree *node){
	if(node->left!=NULL) postoder(node->left);
	if(node->right!=NULL) postoder(node->right);
	cout<<node->val;
}

int main(){
	while(cin>>preTree>>inTree){
		preIdx = 0;
		Tree* root = buildTree(0, preTree.size()-1);
		postoder(root);
		printf("\n");
	}
	
	return 0;
}
