#include <iostream>
#include <vector>
#include <map>
using namespace std;



class permutation {

private:
	int n;
	vector<int> p;


public:

	bool isEqual(permutation const &q) {
		int num = this->n;
		if (num == q.n) {
			for (int i = 0; i < num; i++) {
				if (this->p[i] != q.p[i]) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	permutation(int num, int a[]) {
		this->n = num;
		for (int i = 0; i < num; i++) {
			this->p.push_back(a[i]);

			//cout << this->p[i] << " ";
		}
		p.resize(num); //cout << endl;
	}


	int size() const {
		return this->n;
	}
	
	int* to_array() const {
		int *a = new int[this->n];
		for (int i = 0; i < this->n; i++) {
			a[i] = this->p[i];
			//cout << a[i] << " ";
		}
		//cout << endl;
		return a;
	}


	permutation const operator*(permutation const &q) const { int arr[this->n];
		
		for (int i = 0; i < this->n; i++) {
			//cout << temp << " ";
			arr[i] = this->p[q.p[i]];
			//cout << r->p[i] << endl;
			
		}
		permutation r(this->n, arr);
		//cout << endl;
		return r;
	}


	permutation const operator^(long long int i) const {

		int num = this->n;
		int unit[num];
		for (int i = 0; i < num; i++) {
			unit[i] = i;
		}

		permutation identity(num, unit);
		permutation out(num, unit);

		if (i == 0) {
			for (int i = 0; i < num; ++i) {
				cout << out.p[i] << endl;
			}
		} else if(i == 1) {
			for (int i = 0; i < num; ++i) {
				cout << this->p[i] << endl;
			}
			return *this;
		} else {
			int ind = 1;
			out = out * (*this);
			while(!(out.isEqual(identity))) {
				if (ind == i) {
					for (int i = 0; i < num; ++i) {
						cout << out.p[i] << endl;
					}
					return out;
				}

				out = out * (*this);
				ind++;
			}

			int temp = i%ind;
			for (int i = 0; i < temp; ++i) {
				out = out * (*this);
			}

			for (int i = 0; i < num; ++i) {
				cout << out.p[i] << endl;
			}

			return out;
		}

		return out;

	}

};



int main(){

	int a[5]={2,4,1,0,3};
	permutation a_t(5,a)

	a_t.operator^(3);
	 
}