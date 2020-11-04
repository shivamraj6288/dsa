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

		else {
			if (y1>=node[1] && y2<node[1]+size/2){
				//c1 and c3
				c1=new quad_tree(n-1, value, node[0], node[1]);
				c2=new quad_tree(n-1,value,node[0]+size/2, node[1]);

				c1->set(x1, y1, c1->node[0]+c1->size,y2,b);
				c3->set(c3->node[0],y1,x2,y2,b);

				c3=new quad_tree(n-1,value, node[0], node[1]+size/2);
				c4=new quad_tree(n-1, value, node[0]+size/2, node[1]+size/2);
				return;

			}
			else if (y1>=node[1]+size/2){
				//c2 and c4
				c3=new quad_tree(n-1,value, node[0], node[1]+size/2);
				c4=new quad_tree(n-1, value, node[0]+size/2, node[1]+size/2);

				c2->set(x1,y1,c2->node[0]+c2->size,y2,b);
				c4->set(c4->node[0],y2,x2,y2,b);
				c1=new quad_tree(n-1, value, node[0], node[1]);
				c2=new quad_tree(n-1,value,node[0]+size/2, node[1]);
				return;
			}
			else {
				//c1, c2, c3 ,c4
				c1=new quad_tree(n-1, value, node[0], node[1]);
				c2=new quad_tree(n-1,value,node[0]+size/2, node[1]);
				c3=new quad_tree(n-1,value, node[0], node[1]+size/2);
				c4=new quad_tree(n-1, value, node[0]+size/2, node[1]+size/2);

				c1->set(x1,y1,c1->node[0]+c1->size,c1->node[1]+c1->size,b);
				c3->set(c3->node[0],y1,c3->node[0]+c3->size,c3->node[1]+c3->size,b);
				c2->set(x1,c2->node[1],c2->node[0]+c2->size,y2,b);
				c4->set(c4->node[0],c4->node[1],x2,y2,b);

			}

		}
	}

	int get (int x1, int y1){
		if (c1==NULL){
			return value;
		}
		else {
			if (x1>=c1->node[0] && x1<c1->node[0]+c1->size && y1>=c1->node[1] && y1<c1->node[1]+c1->size){
				return c1->get(x1,y1);
			}
			else if (x1>=c2->node[0] && x1<c2->node[0]+c2->size && y1>=c2->node[1] && y1<c2->node[1]+c2->size){
				return c2->get(x1,y1);
			}
			else if (x1>=c3->node[0] && x1<c3->node[0]+c3->size && y1>=c3->node[1] && y1<c3->node[1]+c3->size){
				return c3->get(x1,y1);

			}
			else {
				return c4->get(x1,y1);
			}
		}
	}

	int size (){
		return n;
	}

	void changeValue(int i){
		if (c1==NULL){
			value=i;
		}
		else {
			c1->changeValue();
			c2->changeValue();
			c3->changeValue();
			c4->changeValue();
		}
	}



	void overlap(quad_tree const &Q){
		if (Q.c1==NULL){
			if (Q.value==0)
				return;
			if (Q.value==1){
				changeValue(1);
			}
		}

		else {
			c1->overlap(Q.c1);
			c2->overlap(Q.c2);
			c3->overlap(Q.c3);
			c4->overlap(Q.c4);
		}


	}
	void intersect(quad_tree &Q){
		if (Q.c1==NULL){
			if (Q1.value==0)
				changeValue(0);
			else 
				return;
		}
		else {
			c1->intersect(Q.c1);
			c2->intersect(Q.c2);
			c3->intersect(Q.c3);
			c4->intersect(Q.c4);
		}

	}

	int neg(int i){
		if i==0
			return 1;
		if i==1
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

	void resize(int m){

	}

	void extract(int x1, int y1, int m){
		
	}

};