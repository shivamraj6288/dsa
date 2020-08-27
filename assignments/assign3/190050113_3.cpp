#include <iostream>
#include <vector>
using namespace std;






long long int pow (int n, int idx){
	long long int rs=1;

	for (int i=1; i<=idx; i++){
		rs=rs*n;
	}

	return rs;
}

long long int length(int l, int max, int pf){
	if (l==0)
		return 0;
	int p=max+1;
	long long int rs=0;
	for (int i=1; i<=p; i++){
		long long int value= pow(i,(l-(i-1)))-pow ((i-1), (l-(i-1)));
		rs=rs+value;
	}

	int delRs=0;

	for (int i=1; i<=(pf+1); i++){
		long long int value= pow(i,(l-(i-1)))-pow ((i-1), (l-(i-1)));
		delRs=delRs+value;
	}
	// if (pf!=0){
	rs=rs-delRs;
	rs=rs+pow(pf+2, l);
	// }
	return rs;
}

long long int secondLength(int l, int max){
	if (l==0)
		return 0;
	int p=max+1;
	long long int rs=0;
	for (int i=1; i<=p; i++){
		long long int value= pow(i,(l-(i-1)))-pow ((i-1), (l-(i-1)));
		rs=rs+value;
	}

	return rs;
}

// long long int pr(int i, int l){
// 	return (pow())
// }

// long long int fn1(int a[]){
	

	
// 	return rank;

// }

int main (int argc, char *argsv[]){

	int T;
	int n;
	cin >>n >> T;

	long long int pl[n+1][n][n];
	long long int absPl[n];



	for (int pf=0; pf<n; pf++){
		for (int l=0; l<n+1; l++){
			for (int m=0; m<n; m++){
				pl[l][m][pf]=length(l, m, pf); // length co-ordinate is 1 less than the actual length
				// cout << pl[l][m][pf] << " ";	
			}

			// cout << endl;
			
		}
		// cout << endl << "================"<< endl;
	}

	for (int m=0; m<n; m++){
		absPl[m]=secondLength(n, m);
		// cout << absPl[m] << " ";
	}
	// cout << endl;
	

	int absMax=n-1;



	vector <vector <long long int>> result;

	for (int t=0; t<T; t++){
		vector <long long int> temp;

		char op;
		cin >> op;
		if (op=='R'){

			int a[n];

			for (int i=0; i<n; i++){
				cin >> a[i];

			}
			int max=0;

	

			long long int rank=0;

			for (int i=1; i<(n-1); i++){
				if (a[i-1]> max){
					max=a[i-1];
				}
				for (int j=0; j<a[i]; j++){
					int tmax=max;
					if (j>tmax)
						tmax=j;
					rank=rank+pl[(n-i-1)][(absMax-tmax)][tmax];
				}
				// cout << rank << " ";

			}

			for (int i=0; i<a[n-1]; i++){
				rank++;
			}
			// cout << endl;

			
			temp.push_back(rank);
			result.push_back(temp);

		}

		else if (op=='U'){
			long long int r;
			cin >>r;

			// int m=0;

			// int cr=absPl[m];

			// while (cr<r){
			// 	m++;
			// 	cr=absPl[m];
			// }

			// cr=absPl[m-1];

			// int cr=0;

			int a[n]={0};

			// for (int i=n-1; i>=0; i--){
			// 	// a[i]=m;
			// 	// if (m>0)
			// 	// 	m--;

			// 	a[i]=1;
					
			// }



			for (int k=1; k<n; k++){
				for (int l=0; l<=k; l++){
					a[k]=l;

					// for (int test=0; test <n; test++){
					// 	cout << a[test] << " ";

					// }
					// cout << endl;
					
					int max=0;
					long long int rank=0;

					for (int i=1; i<(n-1); i++){
						if (a[i-1]> max){
							max=a[i-1];
						}
						for (int j=0; j<a[i]; j++){
							int tmax=max;
							if (j>tmax)
								tmax=j;
							rank=rank+pl[(n-i-1)][(absMax-tmax)][tmax];
						}
						// cout << rank << " ";

					}

					for (int i=0; i<a[n-1]; i++){
						rank++;
					}
					// cout << endl;

					// cout << rank << " ";

					if (rank>r){
						a[k]--;
						// cout << "AAAAAAA"<< endl;
						// cout << a[k];
						break;
					}
					// if (j==i)
				}
				// cout << endl;

			}



			

			// cout << cr << endl;

			
			// while ()


			vector <long long int> tempArray;

			for (int i=0; i<n; i++){
				tempArray.push_back(a[i]);
			}

			result.push_back(tempArray);


		}
	


	}

	for (int t=0; t<T; t++){
		for (int i=0; i<result[t].size(); i++){
			cout << result[t][i] << " ";
		}
		cout << endl;
	}
}