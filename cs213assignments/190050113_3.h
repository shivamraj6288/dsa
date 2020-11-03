#include<bits/stdc++.h>

class quad_tree{
	public :
	int size;
	int n;
	int value;
	int *node;
	quad_tree *c1;
	quad_tree *c2;
	quad_tree *c3;
	quad_tree *c4;	

	quad_tree(int p){
		node=new int[2];
		node[0]=0;
		node[1]=1;
		size=pow(2,p);
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
		delete node;
	}

	quad_tree(quad_tree const &Q){
		size=Q.size;
		value=Q.value;
		node[0]=Q.node[0];
		node[1]=Q.node[1];
		if (Q.c1!=NULL){
			*c1=*Q.c1;
			*c2=*Q.c2;
			*c3=*Q.c3;
			*c4=*Q.c4;
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
		size=pow(2,p);
		n=p;
		value=v;
		 c1=NULL;
		 c2=NULL;
		 c3=NULL;
		 c4=NULL;

	}

	void initial(int v, int x, int y){
		value=v;
		node[0]=x;
		node[1]=y;
	}

	void set (int x1, int y1, int x2, int y2, int b){
		if (b==value)
			return;
		if (x1>=node[0] && x2<node[0]+size/2 ){
			if (y1>=node[1] && y2<node[1]+size/2){
				//c1
				c1=new quad_tree(n-1, value, node[0], node[1]);
				if (x1==c1->node[0] && x2==c1->node[0]+c1->size && y1==c1->node[1] && y2==c1->node[1]+c1->size){
					c1->value=b;
				}

				else {
					c1->set(x1,y1,x2,y2,b);
				}



				c2=new quad_tree(n-1,value,node[0]+size/2, node[1]);
				// c2->initial(value,node[0]+size/2, node[1]);
				c3=new quad_tree(n-1,value, node[0], node[1]+size/2);
				// c3->initial(value, node[0], node[1]+size/2);
				c4=new quad_tree(n-1, value, node[0]+size/2, node[1]+size/2);
				// c4->initial(value, node[0]+size/2, node[1]+size/2);
				return;

			}
			else if (y1>=node[1]+size/2){
				//c3
				c3=new quad_tree(n-1,value, node[0], node[1]+size/2);
				if (x1==c3->node[0] && x2==c3->node[0]+c3->size && y1==c3->node[1] && y2==c3->node[1]+c3->size){
					c3->value=b;
				}

				else {
					c3->set(x1,y1,x2,y2,b);
				}


				c2=new quad_tree(n-1,value,node[0]+size/2, node[1]);
				// c2->initial(value,node[0]+size/2, node[1]);
				c1=new quad_tree(n-1, value, node[0], node[1]);
				// c1->initial(value, node[0], node[1]);
				c4=new quad_tree(n-1, value, node[0]+size/2, node[1]+size/2);
				// c4->initial(value, node[0]+size/2, node[1]+size/2);
				return;

			}
		}
		else if (x1>=node[0]+size/2) {
			if (y1>=node[1] && y2<node[1]+size/2){
				//c2
				c2=new quad_tree(n-1,value,node[0]+size/2, node[1]);
				if (x1==c2->node[0] && x2==c2->node[0]+c2->size && y1==c2->node[1] && y2==c2->node[1]+c2->size){
					c2->value=b;
				}

				else {
					c2->set(x1,y1,x2,y2,b);
				}



				c1=new quad_tree(n-1, value, node[0], node[1]);
				// c1->initial(value, node[0], node[1]);
				c3=new quad_tree(n-1,value, node[0], node[1]+size/2);
				// c3->initial(value, node[0], node[1]+size/2);
				c4=new quad_tree(n-1, value, node[0]+size/2, node[1]+size/2);
				// c4->initial(value, node[0]+size/2, node[1]+size/2);
				return;

			}
			else if (y1>=node[1]+size/2){
				//c4
				c4=new quad_tree(n-1, value, node[0]+size/2, node[1]+size/2);
				if (x1==c4->node[0] && x2==c4->node[0]+c4->size && y1==c4->node[1] && y2==c4->node[1]+c4->size){
					c4->value=b;
				}

				else {
					c4->set(x1,y1,x2,y2,b);
				}
				c2=new quad_tree(n-1,value,node[0]+size/2, node[1]);
				// c2->initial(value,node[0]+size/2, node[1]);
				c3=new quad_tree(n-1,value, node[0], node[1]+size/2);
				// c3->initial(value, node[0], node[1]+size/2);
				c1=new quad_tree(n-1, value, node[0], node[1]);
				// c1->initial(value, node[0], node[1]);
				return;

			}
		}
	}

};