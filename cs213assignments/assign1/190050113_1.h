#include <iostream>
using namespace std;
#include <vector>

int gcd (int a, int b){
	if (a>b){
		temp=b;
		b=a;
		a=temp;
	}

	if (a==0)
		return b;
	return gcd(b%a,a);
}

int indexPos (int c, vector <vector <int>>index){
	for (int i=0; i<index.size(); i++){
		for (int j=0; j<index[i].size(); j++){
			if (index[i][j]=c)
				return i;
		}
	}

}

bool checkPrs(int c, vector<int>pr){
	for (int i=0; i<pr.size(); i++){
		if (pr[i]==c)
			return true;
	}

	return false;
}

class permutation {
	int l;
	int *p;

	

	public:


	permutation(int n, int a[]){
		this->l=n;
		this->p=new int [n];

		for (int i=0; i<n; i++){
			this->p[i]=a[i];

		}

	}

	permutation(permutation const &q){
		l=q.size();

		for (int i=0; i<l; i++){
			p[i]=q.to_array()[i];
		} 

	}

	permutation const operator=(permutation const &q){
		l=q.size();

		for (int i=0; i<l; i++){
			p[i]=q.to_array()[i];
		}
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

	permutation const square_root() const;

	permutation const operator^(long long int k) const{
		int I_arr[l];

		for (int i=0; i<l; i++){
			I_arr[i]=i;
		}

		permutation I(l,I_arr);

		if (k==0)
			return I;

		// vector <int> ringLength;
		vector <vector<int>> ringValue;
		vector <vector<int>> index;

		bool check[l];

		int count=0;

		// while (count < l){
		for (int i=0; i<l; i++){
			if (!check[i]){
				vector <int> tValue;
				tValue.push_back(p[i]);
				vector <int> tIndex;
				tIndex.push_back(i);
				// int tLength=1;
				check[i]=true;
				count++;
				int tl=i;

				while (p[tl]!=i){
					tl=p[tl];
					// if (!check[tl]){
					check[tl]=true;
					count++;
					tValue.push_back(p[tl]);
					tIndex.push_back(tl);
						// tLength++;
					// }
				}

				ringValue.push_back(tValue);
				index.push_back(tIndex);


			}


		}
		// }

		cout << l; //checking purpose

		for (int i=0; i<ringValue.size(); i++){
			int trlength=ringValue[i].size();
			int rem=k%trlength;

			for (int j=0; j<trlength; j++){
				ringValue[i][j]=ringValue[i][(j+rem)%trlength];
			}
		}

		int rs_arr[l];

		for (int i=0; i<ringValue.size(); i++){
			for (int j=0; j<ringValue[i].size(); j++){
				rs_arr[index[i][j]]=ringValue[i][j];
			}
		}


		permutation rs(l, rs_arr);

		return rs;



	}

	bool is_power(permutation const &q) const{

		if (l!=q.size())
			return false;



		vector <vector<int>> ringValue;
		vector <vector<int>> index;

		bool check[l];

		int count=0;

		// while (count < l){
		for (int i=0; i<l; i++){
			if (!check[i]){
				vector <int> tValue;
				tValue.push_back(q[i]);
				vector <int> tIndex;
				tIndex.push_back(i);
				// int tLength=1;
				check[i]=true;
				count++;
				int tl=i;

				while (q[tl]!=i){
					tl=q[tl];
					// if (!check[tl]){
					check[tl]=true;
					count++;
					tValue.push_back(q[tl]);
					tIndex.push_back(tl);
						// tLength++;
					// }
				}

				ringValue.push_back(tValue);
				index.push_back(tIndex);


			}


		}
		// }

		cout << l; //checking purpose

		for (int i=0; i<q.size(); i++){
			if (checkPrs(p.to_array()[i], ringValue[indexPos(i,index)]))
				continue;
			else 
				return false;
		}

		vector <int> rem;

		for (int i=0; i<q.size(); i++){
			
		}


		vector <int> len;
		for (int i=0; i<index.size(); i++){
			len.push_back(index[i].size());
		}

		




	}

	int log (permutation const &q) const;



	~permutation(){
		delete[] p;
	}



};