#include <bits/stdc++.h>
using namespace std;
string pfexp;
string inexp;
int steps;
int k;

struct node {
	char value;
	node *left, *right;
};

node* newNode(char v){
	// cout << "new node creation : " << v << endl;
	node* temp = new node;
	// cout << "check 1\n";
	temp->value=v;
	// cout << "check 2 \n";
	temp->left=temp->right=NULL;
	// cout << "node created : "   << temp->value << endl;
	return temp;
}

node* createTree(){
	stack <node *> nt;

	node *t, *t1, *t2;

	for (int i=0; i<pfexp.length(); i++){
		if (pfexp[i]=='e'){
			// cout << "operand : " << i << endl;
			t=newNode(pfexp[i]);
			nt.push(t);
		}

		else {
			// cout << "operation : " << i<< endl;
			t=newNode(pfexp[i]);
			t1=nt.top(); nt.pop();
			t2=nt.top(); nt.pop();

			t->right=t1;
			t->left=t2;
			nt.push(t);
		}
	}

	t=nt.top();
	nt.pop();
	return t;
}
int f1steps(node *root, int time){  //initialize steps to 1 before calling this function
	int time1=time;
	int time2=time;
	// if (root->left->value=='e' && root->right->value=='e'){
	// 	return;
	// }
	if (root->value!=root->left->value && root->left->value!='e'){
		steps++;
		time1++;
	}
	if (root->value!=root->right->value && root->right->value!='e'){
		steps++;
		time2++;
	}
	// if ((root->value!=root->left->value && root->left->value!='e') || (root->value!=root->right->value && root->right->value!='e')){
	// 	time++;
	// }

	if (root->left->value!='e' && root->right->value!='e')
		return max(f1steps(root->left,time1), f1steps(root->right, time2));
	else if(root->left->value=='e' && root->right->value!='e')
		return max(time1,f1steps(root->right, time2));
	else if (root->left->value!='e' && root->right->value=='e')
		return max (f1steps(root->left,time1), time2);
	else 
		return max(time1,time2);

	// return;
}

int f2steps(node *root, int time, int tk){  //initialize steps to 1 before calling this function
	int time1=time;
	int time2=time;
	int tk1=tk;
	int tk2=tk;
	// if (root->left->value=='e' && root->right->value=='e'){
	// 	return;
	// }
	if (root->value!=root->left->value && root->left->value!='e'){
		steps++;
		time1++;
		tk1=1;
	}
	else {
		tk1++;
		if (tk>=k){
			tk1=1;
			steps++;
			time1++;
		}

	}
	if (root->value!=root->right->value && root->right->value!='e'){
		steps++;
		time2++;
		tk2=1;
	}
	else {
		if (root->value==root->left->value && root->left->value!='e')	
			tk2=tk1;

		tk2++;
		if (tk2>=k){
			tk2=1;
			steps++;
			time2++;
		}
		if (root->value==root->left->value && root->left->value!='e')	
			tk1=tk2;
	}
	// if ((root->value!=root->left->value && root->left->value!='e') || (root->value!=root->right->value && root->right->value!='e')){
	// 	time++;
	// }

	if (root->left->value!='e' && root->right->value!='e')
		return max(f2steps(root->left,time1,tk1), f2steps(root->right, time2,tk2));
	else if(root->left->value=='e' && root->right->value!='e')
		return max(time1,f2steps(root->right, time2,tk2));
	else if (root->left->value!='e' && root->right->value=='e')
		return max (f2steps(root->left,time1,tk1), time2);
	else 
		return max(time1,time2);

	// return;
}

int main (){
	cin >> pfexp;
	// cout << pfexp << endl;
	// cout << pftoin(pfexp)<<endl;
	// cout << pfexp[2];
	// inexp=pftoin(pfexp);
	// cout <<f1steps() << endl;
	node *root;
	root = createTree();
	// cout << "root created \n";
	steps=1;
	int time=f1steps(root,1);
	cout << steps << " " << time << endl;
	int T;
	cin >> T;
	for (int t=0; t<T; t++ ){
		cin >> k;
		steps=1;
		int time=f2steps(root,1,1);
		cout << steps << " " << time << endl;
	}

}