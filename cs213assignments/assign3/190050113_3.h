#include<bits/stdc++.h>
using namespace std;

class quad_tree{
	public :
	int sz;
	int n;
	int value;
	int *node; //stores actual node-ordinate of top leftmost element of matrix
	quad_tree *c1;
	quad_tree *c2;
	quad_tree *c3;
	quad_tree *c4;	

	quad_tree(int p){
		node=new int[2];
		node[0]=0;
		node[1]=0;
		sz=pow(2,p);
		n=p;
		value=0;
		 c1=NULL;
		 c2=NULL;
		 c3=NULL;
		 c4=NULL;	

	}
	~quad_tree(){
		delete c1;
		delete c2;
		delete c3;
		delete c4;
		delete[] node;
	}

	quad_tree(quad_tree const &Q){
		if (this==&Q){
			return;
		}
		sz=Q.sz;
		n=Q.n;
		value=Q.value;
		node=new int[2];
		node[0]=Q.node[0];
		node[1]=Q.node[1];
		if (Q.c1!=NULL){
			c1=new quad_tree(*Q.c1);
			c2=new quad_tree(*Q.c2);
			c3=new quad_tree(*Q.c3);
			c4=new quad_tree(*Q.c4);
		}
		else {
			c1=NULL;
			c2=NULL;
			c3=NULL;
			c4=NULL;
		}
	}
	quad_tree(int p, int v, int x, int y){
		node=new int[2];
		node[0]=x;
		node[1]=y;
		sz=pow(2,p);
		n=p;
		value=v;
		 c1=NULL;
		 c2=NULL;
		 c3=NULL;
		 c4=NULL;

	}

	
	// void set (int x1, int y1, int x2, int y2, int b){
	// 	if (c1==NULL){
	// 		if (b==value)
	// 			return;

	// 	}

	// 	if (x1<node[0] || x2 > node[0]+sz-1 || y1<node[1] || y2 >node[1]+sz-1)
	// 		return;
	// 	if (c1!=NULL){
	// 		if (x1>=node[0] && x2<node[0]+sz/2 ){
	// 		// cout << "entry1\n";

	// 			if (y1>=node[1] && y2<node[1]+sz/2){
	// 				c1->set(x1,y1,x2,y2,b);
					
	// 			}
	// 			else if (y1>=node[1]+sz/2){
					
	// 				c3->set(x1,y1,x2,y2,b);
					
	// 			}
	// 		}
	// 		else if (x1>=node[0]+sz/2) {
	// 			// cout << "entry2\n";
	// 			if (y1>=node[1] && y2<node[1]+sz/2){
	// 				//c2
					
	// 					c2->set(x1,y1,x2,y2,b);
					

	// 			}
	// 			else if (y1>=node[1]+sz/2){
	// 				//c4
					
	// 					c4->set(x1,y1,x2,y2,b);
					

	// 			}
	// 		}

	// 		else {
	// 			// cout << "entry3\n";
	// 			if (y1>=node[1] && y2<node[1]+sz/2){
	// 				//c1 and c3
	// 				c1->set(x1, y1, c1->node[0]+c1->sz-1,y2,b);
	// 				c3->set(c3->node[0],y1,x2,y2,b);
	// 				// cout <<"best case 1\n";

	// 			}
	// 			else if (y1>=node[1]+sz/2){
	// 				//c2 and c4
	// 				// cout <<"best case 2\n";
	// 				c2->set(x1,y1,c2->node[0]+c2->sz-1,y2,b);
	// 				c4->set(c4->node[0],y2,x2,y2,b);
	// 			}
	// 			else {
	// 				//c1, c2, c3 ,c4
	// 				c1->set(x1,y1,c1->node[0]+c1->sz-1,c1->node[1]+c1->sz-1,b);
	// 				c3->set(c3->node[0],y1,x2,c3->node[1]+c3->sz-1,b);
	// 				c2->set(x1,c2->node[1],c2->node[0]+c2->sz-1,y2,b);
	// 				c4->set(c4->node[0],c4->node[1],x2,y2,b);

	// 			}

	// 		}
	// 		return;
	// 	}
	// 	c1=new quad_tree(n-1, value, node[0], node[1]);
	// 	c2=new quad_tree(n-1,value,node[0], node[1]+sz/2);
	// 	c3=new quad_tree(n-1,value, node[0]+sz/2, node[1]	);
	// 	c4=new quad_tree(n-1, value, node[0]+sz/2, node[1]+sz/2);
	// 	// cout << "region passed\n";
	// 	if (x1>=node[0] && x2<node[0]+sz/2 ){
	// 		// cout << "entry1\n";

	// 		if (y1>=node[1] && y2<node[1]+sz/2){
	// 			cout << x1 << "," << c1->node[0] << endl;
	// 			if (x1==c1->node[0] && x2==c1->node[0]+c1->sz-1 && y1==c1->node[1] && y2==c1->node[1]+c1->sz-1){
	// 				c1->value=b;
	// 				cout <<"assigned \n";
	// 			}

	// 			else {
	// 				c1->set(x1,y1,x2,y2,b);
	// 			}
	// 			return;

	// 		}
	// 		else if (y1>=node[1]+sz/2){
	// 			cout << x1 << "," << c3->node[0] << endl;
	// 			if (x1==c3->node[0] && x2==c3->node[0]+c3->sz-1 && y1==c3->node[1] && y2==c3->node[1]+c3->sz-1){
	// 				c3->value=b;
	// 				cout << "value assigned2\n";
	// 			}

	// 			else {
	// 				c3->set(x1,y1,x2,y2,b);
	// 			}
	// 			return;

	// 		}
	// 	}
	// 	else if (x1>=node[0]+sz/2) {
	// 		// cout << "entry2\n";
	// 		if (y1>=node[1] && y2<node[1]+sz/2){
	// 			//c2
	// 			if (x1==c2->node[0] && x2==c2->node[0]+c2->sz-1 && y1==c2->node[1] && y2==c2->node[1]+c2->sz-1){
	// 				cout << x1 << "," << c2->node[0] << endl;
	// 				c2->value=b;
	// 				cout << "value assigned3\n";
	// 			}

	// 			else {
	// 				c2->set(x1,y1,x2,y2,b);
	// 			}
	// 			return;

	// 		}
	// 		else if (y1>=node[1]+sz/2){
	// 			//c4
	// 			if (x1==c4->node[0] && x2==c4->node[0]+c4->sz-1 && y1==c4->node[1] && y2==c4->node[1]+c4->sz-1){
	// 				cout << x1 << "," << c4->node[0] << endl;
	// 				c4->value=b;
	// 				cout << "value assigned4\n";
	// 			}

	// 			else {
	// 				c4->set(x1,y1,x2,y2,b);
	// 			}
	// 			return;

	// 		}
	// 	}

	// 	else {
	// 		// cout << "entry3\n";
	// 		if (y1>=node[1] && y2<node[1]+sz/2){
	// 			//c1 and c3
	// 			c1->set(x1, y1, c1->node[0]+c1->sz-1,y2,b);
	// 			c3->set(c3->node[0],y1,x2,y2,b);
	// 			// cout <<"best case 1\n";
	// 			return;

	// 		}
	// 		else if (y1>=node[1]+sz/2){
	// 			//c2 and c4
	// 			// cout <<"best case 2\n";
	// 			c2->set(x1,y1,c2->node[0]+c2->sz-1,y2,b);
	// 			c4->set(c4->node[0],y2,x2,y2,b);
	// 			return;
	// 		}
	// 		else {
	// 			//c1, c2, c3 ,c4
	// 			c1->set(x1,y1,c1->node[0]+c1->sz-1,c1->node[1]+c1->sz-1,b);
	// 			c3->set(c3->node[0],y1,x2,c3->node[1]+c3->sz-1,b);
	// 			c2->set(x1,c2->node[1],c2->node[0]+c2->sz-1,y2,b);
	// 			c4->set(c4->node[0],c4->node[1],x2,y2,b);

	// 		}

	// 	}
	// }
	void set(int x1,int y1,int x2,int y2,int b){
		if(x1==this->node[0] && x2==this->node[0]+this->sz-1 && y1==this->node[1] && y2==this->node[1]+this->sz-1){
			if(c1!=NULL){
				delete this->c1;
				delete this->c2;
				delete this->c3;
				delete this->c4;
			}
			this->value=b;
			return;
		}
		if(this->c1==NULL){
			if(this->value==b) return;
			else{
				int mid=this->sz/2;
				if(x1==this->node[0] && x2==this->node[0]+mid-1 && y1==this->node[1] && y2==this->node[1]+mid-1){
					this->c1=new quad_tree(this->n-1,b,this->node[0],this->node[1]);
					this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
					this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
					this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
					return;
				}
				if(x1==this->node[0]+mid && x2==this->node[0]+2*mid-1 && y1==this->node[1] && y2==this->node[1]+mid-1){
					this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
					this->c2=new quad_tree(this->n-1,b,this->node[0]+mid,this->node[1]);
					this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
					this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
					return;
				}
				if(x1==this->node[0] && x2==this->node[0]+mid-1 && y1==this->node[1]+mid && y2==this->node[1]+2*mid-1){
					this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
					this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
					this->c3=new quad_tree(this->n-1,b,this->node[0],this->node[1]+mid);
					this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
					return;
				}
				if(x1==this->node[0]+mid && x2==this->node[0]+2*mid-1 && y1==this->node[1]+mid && y2==this->node[1]+2*mid-1){
					this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
					this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
					this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
					this->c4=new quad_tree(this->n-1,b,this->node[0]+mid,this->node[1]+mid);
					return;
				}
				if(x2<=this->node[0]+mid-1){
					if(y2<=this->node[1]+mid-1){
						this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
						this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
						this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
						this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
						this->c1->set(x1,y1,x2,y2,b);
						return;
					}
					if(y1>=this->node[1]+mid){
						this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
						this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
						this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
						this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
						this->c3->set(x1,y1,x2,y2,b);
						return;
					}
					if(y1<this->node[1]+mid && y2>this->node[1]+mid-1){
						this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
						this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
						this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
						this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
						this->c3->set(x1,this->node[1]+mid,x2,y2,b);
						this->c1->set(x1,y1,x2,this->node[1]+mid-1,b);
						return;
					}
				}
				if(x1>=this->node[0]+mid){
					if(y2<=this->node[1]+mid-1){
						this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
						this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
						this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
						this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
						this->c2->set(x1,y1,x2,y2,b);
						return;
					}
					if(y1>=this->node[1]+mid){
						this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
						this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
						this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
						this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
						this->c4->set(x1,y1,x2,y2,b);
						return;
					}
					if(y1<this->node[1]+mid && y2>this->node[1]+mid-1){
						this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
						this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
						this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
						this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
						this->c4->set(x1,this->node[1]+mid,x2,y2,b);
						this->c2->set(x1,y1,x2,this->node[1]+mid-1,b);
						return;
					}
				}
				if(x1<this->node[0]+mid && x2>this->node[0]+mid-1){
					if(y2<=this->node[1]+mid-1){
						this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
						this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
						this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
						this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
						this->c2->set(this->node[0]+mid,y1,x2,y2,b);
						this->c1->set(x1,y1,this->node[0]+mid-1,y2,b);
						return;
					}
					if(y1>=this->node[1]+mid){
						this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
						this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
						this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
						this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
						this->c4->set(this->node[0]+mid,y1,x2,y2,b);
						this->c3->set(x1,y1,this->node[0]+mid-1,y2,b);
						return;
					}
					if(y1<this->node[1]+mid && y2>this->node[1]+mid-1){
						this->c1=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]);
						this->c2=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]);
						this->c3=new quad_tree(this->n-1,this->value,this->node[0],this->node[1]+mid);
						this->c4=new quad_tree(this->n-1,this->value,this->node[0]+mid,this->node[1]+mid);
						this->c4->set(this->node[0]+mid,this->node[1]+mid,x2,y2,b);
						this->c2->set(this->node[0]+mid,y1,x2,this->node[1]+mid-1,b);
						this->c3->set(x1,this->node[1]+mid,this->node[0]+mid-1,y2,b);
						this->c1->set(x1,y1,this->node[0]+mid-1,this->node[1]+mid-1,b);
						return;
					}
				}
			}
		}
		if(this->c1!=NULL){
			int mid=this->sz/2;
			if(x1==this->node[0] && x2==this->node[0]+mid-1 && y1==this->node[1] && y2==this->node[1]+mid-1){
				this->c1=new quad_tree(this->n-1,b,this->node[0],this->node[1]);
				return;
			}
			if(x1==this->node[0]+mid && x2==this->node[0]+2*mid-1 && y1==this->node[1] && y2==this->node[1]+mid-1){
				this->c2=new quad_tree(this->n-1,b,this->node[0]+mid,this->node[1]);
				return;
			}
			if(x1==this->node[0] && x2==this->node[0]+mid-1 && y1==this->node[1]+mid && y2==this->node[1]+2*mid-1){
				this->c3=new quad_tree(this->n-1,b,this->node[0],this->node[1]+mid);
				return;
			}
			if(x1==this->node[0]+mid && x2==this->node[0]+2*mid-1 && y1==this->node[1]+mid && y2==this->node[1]+2*mid-1){
				this->c4=new quad_tree(this->n-1,b,this->node[0]+mid,this->node[1]+mid);
				return;
			}
			if(x2<=this->node[0]+mid-1){
				if(y2<=this->node[1]+mid-1){
					this->c1->set(x1,y1,x2,y2,b);
					return;
				}
				if(y1>=this->node[1]+mid){
					this->c3->set(x1,y1,x2,y2,b);
					return;
				}
				if(y1<this->node[1]+mid && y2>this->node[1]+mid-1){
					this->c3->set(x1,this->node[1]+mid,x2,y2,b);
					this->c1->set(x1,y1,x2,this->node[1]+mid-1,b);
					return;
				}
			}
			if(x1>=this->node[0]+mid){
				if(y2<=this->node[1]+mid-1){
					this->c2->set(x1,y1,x2,y2,b);
					return;
				}
				if(y1>=this->node[1]+mid){
					this->c4->set(x1,y1,x2,y2,b);
					return;
				}
				if(y1<this->node[1]+mid && y2>this->node[1]+mid-1){
					this->c4->set(x1,this->node[1]+mid,x2,y2,b);
					this->c2->set(x1,y1,x2,this->node[1]+mid-1,b);
					return;
				}
			}
			if(x1<this->node[0]+mid && x2>this->node[0]+mid-1){
				if(y2<=this->node[1]+mid-1){
					this->c2->set(this->node[0]+mid,y1,x2,y2,b);
					this->c1->set(x1,y1,this->node[0]+mid-1,y2,b);
					return;
				}
				if(y1>=this->node[1]+mid){
					this->c4->set(this->node[0]+mid,y1,x2,y2,b);
					this->c3->set(x1,y1,this->node[0]+mid-1,y2,b);
					return;
				}
				if(y1<this->node[1]+mid && y2>this->node[1]+mid-1){
					this->c4->set(this->node[0]+mid,this->node[1]+mid,x2,y2,b);
					this->c2->set(this->node[0]+mid,y1,x2,this->node[1]+mid-1,b);
					this->c3->set(x1,this->node[1]+mid,this->node[0]+mid-1,y2,b);
					this->c1->set(x1,y1,this->node[0]+mid-1,this->node[1]+mid-1,b);
					return;
				}
			}
		}
	}
	

	int get (int x1, int y1){
		if (c1==NULL){
			return value;
		}
		else {
			if (x1>=c1->node[0] && x1<c1->node[0]+c1->sz && y1>=c1->node[1] && y1<c1->node[1]+c1->sz){
				return c1->get(x1,y1);
			}
			else if (x1>=c2->node[0] && x1<c2->node[0]+c2->sz && y1>=c2->node[1] && y1<c2->node[1]+c2->sz){
				return c2->get(x1,y1);
			}
			else if (x1>=c3->node[0] && x1<c3->node[0]+c3->sz && y1>=c3->node[1] && y1<c3->node[1]+c3->sz){
				return c3->get(x1,y1);

			}
			else {
				return c4->get(x1,y1);
			}
		}
	}

	int size(){
		return n;
	}

	// void deleteChild(){
	// 	if (this->c1!=NULL){

	// 	}
	// }

	void changeValue(int i){
		if (c1==NULL){
			this->value=i;
		}
		else {
			this->c1->changeValue(i);
			this->c2->changeValue(i);
			this->c3->changeValue(i);
			this->c4->changeValue(i);
		}
	}



	void overlap(quad_tree const &Q){
		if (Q.c1==NULL){
			if (Q.value==0){
				cout << "Q.value is 0 \n";
				return;
			}
			if (Q.value==1){
				cout << "entry Q.value is 1 \n";
				delete this->c1;
				delete this->c2;
				delete this->c3;
				delete this->c4;
				this->value=1;
				cout << "Q.value is 1 \n";
				return;
				// this->changeValue(1);
			}
		}

		else {
			cout << "child play \n";
			this->c1->overlap(*Q.c1);
			this->c2->overlap(*Q.c2);
			this->c3->overlap(*Q.c3);
			this->c4->overlap(*Q.c4);
			return;
		}


	}
	void intersect(quad_tree &Q){
		if (Q.c1==NULL){
			if (Q.value==0){
				delete this->c1;
				delete this->c2;
				delete this->c3;
				delete this->c4;
				this->value=0;
				return;
			}
				

				// this->changeValue(0);
			else 
				return;
		}
		else {
			this->c1->intersect(*Q.c1);
			this->c2->intersect(*Q.c2);
			this->c3->intersect(*Q.c3);
			this->c4->intersect(*Q.c4);
			return;
		}

	}

	int neg(int i){
		if (i==0)
			return 1;
		return 0;
	}



	void complement(){
		// value=neg(value);
		if (c1!=NULL){
			c1->complement();
			c2->complement();
			c3->complement();
			c4->complement();
		}
		else {
			value=neg(value);
		}
	}
	void expand(int k){
		if (c1==NULL){
			n=n+k;
			sz=pow(2,n);

		}
		else {
			n=n+k; 
			sz=pow(2,n);
			c1->expand(k);
			c2->expand(k);
			c3->expand(k);
			c4->expand(k);
		}

	}

	void contract(int k,int m){
		if (m==0){
			if (c1==NULL){
				n=n-k;
				sz=pow(2,n);

			}
			else {
				if (this->mode()>=0)
					value=1;
				else 
					value=0;
				delete this->c1;
				delete this->c2;
				delete this->c3;
				delete this->c4;
				this->n=this->n-k;
				this->sz=pow(2,this->n);


			}
		}
		else {
			this->n=this->n-k;
			sz=pow(2,n);
			c1->contract(k,m-1);
			c2->contract(k,m-1);
			c3->contract(k,m-1);
			c4->contract(k,m-1);

		}
	}
	int mode(){
		if (c1==NULL){
			if (value==1)
				return 1*sz;
			else 
				return -1*sz;

		}
		else {
			return (c1->mode()+c2->mode()+c3->mode()+c4->mode());
		}
	}

	void repair(int x, int y){
		node[0]=x;
		node[1]=y;
		if (c1!=NULL){
			c1->repair(0,0);
			c2->repair(0,sz/2);
			c3->repair(sz/2,0);
			c4->repair(sz/2,sz/2);
		}
	}

	void resize(int m){

		if (m>=n){
			int k=m-n;
			this->expand(k);
			this->repair(0,0);
			
		}

		else {
			int k=n-m;
			this->contract(k,m);			
			this->repair(0,0);
		}

	}

	void extract(int x1, int y1, int m){
		if (c1==NULL){
			
			n=m;
			sz=pow(2,m);
			
		}

		// else if (c1->node[0]<=x1 && x1+pow(2,m)-1<c1->node[0]+c1->size && node[1]<=y1 && y1+pow(2,m)-1<c1->node[1]+c1.size){
		// 	value=c1->value;
		// 	n=c1->n;
		// 	sz=sz->n;
		// 	c1=c1->c1;
		// 	c2=c1->c2;
		// 	c3=c1->c3;
		// 	c4=c1->c4;

		// }

	}

};