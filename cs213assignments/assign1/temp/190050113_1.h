#include <bits/stdc++.h>
using namespace std;
#include <vector>

int gcd (int a, int b){
	if (a>b){
		int temp=b;
		b=a;
		a=temp;
	}

	if (a==0)
		return b;
	return gcd(b%a,a);
}

// int indexPos (int c, vector <vector <int>>index){
// 	for (int i=0; i<index.size(); i++){
// 		for (int j=0; j<index[i].size(); j++){
// 			if (index[i][j]=c)
// 				return i;
// 		}
// 	}

// }

bool checkArr(int a[], int b[], int l){
	for (int i=0; i<l; i++){
		if (a[i]!=b[i]){
			return false;
		}
	}

	return true;
}
bool checkPrs(int c, vector<int>pr){
	for (int i=0; i<pr.size(); i++){
		if (pr[i]==c)
			return true;
	}

	return false;
}

class permutation {
	
	

	public:

	int l;
	int *p;



	permutation(int n, int a[]){
		this->l=n;
		this->p=new int [n];

		for (int i=0; i<n; i++){
			this->p[i]=a[i];

		}

	}

	permutation(permutation const &q){
		l=q.size();
		p=new int [l];
		for (int i=0; i<l; i++){
			p[i]=q.to_array()[i];
		} 

	}

	permutation const operator=(permutation const &q){
		l=q.size();
		delete[] p;
		p=new int [l];

		for (int i=0; i<l; i++){
			p[i]=q.to_array()[i];
		}

		permutation rs (l,p);

		return rs;
	}

	int size() const{
		return l;
	}

	int* to_array() const{
		int *arr= new int [l];
		for (int i=0; i<l; i++){
			arr[i]=p[i];
		}

		return arr;
	}

	permutation const operator-() const{
		int r[l];

		for (int i=0; i<l; i++){
			r[p[i]]=i;
		}

		permutation rs (l, r);

		return rs;


	}

	permutation const operator*(permutation const &q) const {
		int r[l];

		for (int i=0; i<l; i++){
			r[i]=p[q.to_array()[i]];
		}

		permutation rs (l,r);
		return rs;
	}

	// permutation const square_root() const{
	// 	 vector<vector<int>> es,os;
 //        vector<bool> b(l,false);
 //        for(int i=0;i<l;i++){
 //            if(!b[i]){
 //                b[i]=true;
 //                int x=p[i];
 //                vector<int> v;
 //                v.push_back(i);
 //                while(x!=i){
 //                    v.push_back(x);
 //                    b[x]=true;
 //                    x=p[x];
 //                }
 //                if(v.size()%2==0) es.push_back(v);
 //                else os.push_back(v);
 //            }
 //        }
 //        int a[l];
 //        for(int j=0;j<l;j++){
 //            a[j]=j;
 //        }
 //        permutation iden = *new permutation(l,a);
 //        vector<vector<int>> esf,osf;
 //        sort(es.begin(), es.end(), [](const vector<int> & a, const vector<int> & b){ return a.size() < b.size(); });
 //        for(int i=0;i<es.size();i+=2){
 //            if(es[i].size()!=es[i+1].size()){
 //                return iden;
 //            }
 //            vector<int> v;
 //            for(int j=0;j<es[i].size();j++){
 //                v.push_back(es[i][j]);
 //                v.push_back(es[i+1][j]);
 //            }
 //            esf.push_back(v);
 //        }
 //        for(int i=0;i<os.size();i++){
 //            vector<int> v;
 //            int k=os[i].size();
 //            for(int j=0;j<k/2;j++){
 //                v.push_back(os[i][j]);
 //                v.push_back(os[i][((k+1)/2)+j]);
 //            }
 //            v.push_back(os[i][k/2]);
 //            osf.push_back(v);
 //        }
 //        int af[l];
 //        for(int i=0;i<esf.size();i++){
 //            for(int j=0;j<esf[i].size();j++){
 //                af[esf[i][j]]=esf[i][(j+1)%esf[i].size()];
 //            }
 //        }
 //        for(int i=0;i<osf.size();i++){
 //            for(int j=0;j<osf[i].size();j++){
 //                af[osf[i][j]]=osf[i][(j+1)%osf[i].size()];
 //            }
 //        }
 //        return *new permutation(l,af);
	// }


	permutation const square_root() const{
		int b[1200000],c[1200000],d[1200000],e[1200000],g[1200000],h[1200000];
		int i,j,k,l,n;

		n=l;

		for (int i=1; i<l+1; i++){
			g[i]=p[i-1];
		}

		int I[l];

		for (int i=0; i<l; i++){
			I[i]=i;
		}


		for (i=1;i<=n;i++){
			if (! b[i])
			{
				for (j=i,k=0;! b[j];j=g[j],k++)
					b[j]=1;
				c[i]=k,d[k]++;
			}
		}
		for (i=1;i<=n;i++){
			if ((! (i&1)) && (d[i]&1))
			{
				return (permutation(l,I));				 
			}
		}
		for (i=1;i<=n;i++){
			if (c[i]&1)
			{
				for (j=i,k=1;k<(c[i]+1)/2;j=g[j],k++);
				for (l=i,k=1;k<=c[i];j=g[j],l=g[l],k++)
					h[j]=l;
			}
			else{
				if (! e[c[i]])
					e[c[i]]=i;
				else
				{
					for (j=e[c[i]],l=i,k=1;k<=c[i];j=g[j],l=g[l],k++)
						h[j]=l,h[l]=g[j];
						e[c[i]]=0;
				}
			}

		}

		int rs[l];
		for (int i=0; i<l; i++){
			rs[i]=h[i+1]-1;
		}

		return permutation(l,rs);

	}

	// permutation const operator^(long long int k) const{
		// int I_arr[l];

		// for (int i=0; i<l; i++){
		// 	I_arr[i]=i;
		// }

		// permutation I(l,I_arr);

		// if (k==0)
		// 	return I;

	// 	// vector <int> ringLength;
	// 	vector <vector<int>> ringValue;
	// 	vector <vector<int>> index;

	// 	bool check[l];

	// 	int count=0;

	// 	// while (count < l){
	// 	for (int i=0; i<l; i++){
	// 		if (!check[i]){
	// 			vector <int> tValue;
	// 			tValue.push_back(p[i]);
	// 			vector <int> tIndex;
	// 			tIndex.push_back(i);
	// 			// int tLength=1;
	// 			check[i]=true;
	// 			count++;
	// 			int tl=i;

	// 			while (p[tl]!=i){
	// 				tl=p[tl];
	// 				// if (!check[tl]){
	// 				check[tl]=true;
	// 				count++;
	// 				tValue.push_back(p[tl]);
	// 				tIndex.push_back(tl);
	// 					// tLength++;
	// 				// }
	// 			}

	// 			ringValue.push_back(tValue);
	// 			index.push_back(tIndex);


	// 		}


	// 	}
	// 	// }

	// 	// cout << l; //checking purpose

	// 	for (int i=0; i<ringValue.size(); i++){
	// 		int trlength=ringValue[i].size();
	// 		int rem=k%trlength;

	// 		for (int j=0; j<trlength; j++){
	// 			ringValue[i][j]=ringValue[i][(j+rem)%trlength];
	// 		}
	// 	}

	// 	int rs_arr[l];

	// 	for (int i=0; i<ringValue.size(); i++){
	// 		for (int j=0; j<ringValue[i].size(); j++){
	// 			rs_arr[index[i][j]]=ringValue[i][j];
	// 		}
	// 	}


	// 	permutation rs(l, rs_arr);

	// 	return rs;



	// }

	bool isEqual(permutation b){
		if (l!=b.size())
			return false;
		for (int i=0; i<l; i++){
			if (p[i]!=b.p[i])
				return false;

		}

		return true;
	}

	// permutation const operator^(long long int k) const{
		
	// 	int I_arr[l];

	// 	for (int i=0; i<l; i++){
	// 		I_arr[i]=i;
	// 	}

	// 	permutation I(l,I_arr);

	// 	if (k==0)
	// 		return I;

	// 	// vector <int> ringLength;
	// 	vector <vector<int>> ringValue;
	// 	vector <vector<int>> index;

	// 	bool check[l];

	// 	int count=0;

	// 	// while (count < l){
	// 	for (int i=0; i<l; i++){
	// 		if (!check[i]){
	// 			vector <int> tValue;
	// 			tValue.push_back(p[i]);
	// 			vector <int> tIndex;
	// 			tIndex.push_back(i);
	// 			// int tLength=1;
	// 			check[i]=true;
	// 			count++;
	// 			int tl=i;

	// 			while (p[tl]!=i){
	// 				tl=p[tl];
	// 				// if (!check[tl]){
	// 				check[tl]=true;
	// 				count++;
	// 				tValue.push_back(p[tl]);
	// 				tIndex.push_back(tl);
	// 					// tLength++;
	// 				// }
	// 			}

	// 			ringValue.push_back(tValue);
	// 			index.push_back(tIndex);


	// 		}


	// 	}
	// 	// }

	// 	cout <<endl << count << l <<endl; //checking purpose

	// 	for (int i=0; i<ringValue.size(); i++){
	// 		int trlength=ringValue[i].size();
	// 		int rem=k%trlength;

	// 		for (int j=0; j<trlength; j++){
	// 			ringValue[i][j]=ringValue[i][(j+rem)%trlength];
	// 		}
	// 	}

	// 	int rs_arr[l];

	// 	for (int i=0; i<ringValue.size(); i++){
	// 		for (int j=0; j<ringValue[i].size(); j++){
	// 			rs_arr[index[i][j]]=ringValue[i][j];
	// 		}
	// 	}


	// 	permutation rs(l, rs_arr);

	// 	return rs;




	// }
	int get(){
		if(permutation(l,p).is_identity())
			return 1;
		else{
			permutation rs(permutation(l,p)*permutation(l,p));
			return 1+rs.get();
		}
	}

	permutation operator^(long long int i){
		int b[l];

		if(i==0){
			for(int j=0;j<l;j++)
				b[i]=i;
			return permutation(l,b);
		}
		permutation c=permutation(l,b);
		for(int j=0;j<i%(permutation(l,b).get());j++){
			c=c*permutation(l,p);
		}
		return c;
	}

	bool is_power(permutation const &q) const{

		if (this->log(q)==-1)
			return false;

		return true;
	}

	bool is_identity(){
		for (int i=0; i<l ; i++){
			if (p[i]!=i)
				return false;
		}

		return true;
	}

	int log (permutation const &q) const{

		permutation perm(*this);
        if(perm.is_identity()) return 0;
        int* t=q.p;
        map<int,int> m;
        vector<bool> b(l,false);
        for(int i=0;i<l;i++){
            if(!b[i]){
                b[i]=true;
                int x=t[i];
                vector<int> v,v1,v2;
                v.push_back(i);
                v1.push_back(t[i]);
                v2.push_back(p[i]);
                while(x!=i){
                    v.push_back(x);
                    v1.push_back(t[x]);
                    v2.push_back(p[x]);
                    b[x]=true;
                    x=t[x];
                }
                int j;
                for(j=0;j<v.size();j++){
                    if(v2[j]==v1[0]) break;
                }
                if(j==v.size()) return -1;
                for(int k=1;k<v.size();k++){
                    if(v1[k]!=v2[(k+j)%v.size()]) return -1;
                }
                if(j!=0) j=v.size()-j;
                j++;j=j%v.size();
                if(m.count(v.size())==1){
                    if(m[v.size()]!=j) return -1;
                }
                m.insert(pair<int,int>(v.size(),j));
            }
        }
        map<int, int>::iterator itr;
        long long int x,r;
        bool i=true;
        for(itr=m.begin();itr!=m.end();itr++){
            if(i){
                i=false;
                x=itr->first,r=itr->second;
            }
            else{
                long long int x1=itr->first,r1=itr->second;
                long long int l=(x*x1)/gcd(x,x1);
                while(r<l){
                    if(r%x1==r1) break;
                    r+=x;
                }
                if(r>=l) return -1;
                x=l;
            }
        }
        int max=(1e9)+7;
        return r%max;

	}



	~permutation(){
		delete[] p;
	}



};