#include <iostream>
using namespace std ;
#include<vector>
#include <algorithm>

int n;
// vector <int> a;
int *a;
// vector <int> id;

// int head(vector <int> v){
// 	return v[0];
// }

// vector <int> tail(vector <int> v){
// 	vector <int> t;
// 	if (v.size()==1)
// 		return t;
// 	return (v.erase(v.begin()));
// }
// vector <int> push(vector <int> v, int n){
// 	return(v.insert(v.begin(),n));
// }


// vector <int> merge (vector <int>v1, vector <int> v2){
// 	if (v1.size()==0)
// 		return v2;
// 	if (v2.size()==0)
// 		return v1;
// 	if (a[head(v1)<=a[head(v2)]])
// 		return push(merge(tail(v1),v2), head(v1));
// 	else 
// 		return push(merge(v1,tail(v2)),head(v2));
// }

// vector <int> odd(vector<int> v){
// 	if (v.size()==0)
// 		return v;
// 	else 
// 		return push(even(tail(v)),head(v));
// }

// vector <int> even(vector<int> v){
// 	if (v.size()==0)
// 		return v;
// 	else 
// 		return(odd(tail(v)));
// }

// vector<int> msort(vector <int> v){
// 	if (v.size()<=1)
// 		return v ;
// 	return merge(msort(odd(index)), msort(even(index)));
// }
long long int f(int s, int e){
    if(e<=s) return 0;
    if(e==s+1){
        if(a[s]<=a[e]) return 1;
        return 0;
    }
    int maximumVal=e,minimumVal=s;
    for(int i=s+1;i<=e;i++){
        if(a[minimumVal]>a[i]) minimumVal=i;
    }
    for(int i=e-1;i>=s;i--){
        if(a[maximumVal]<a[i]) maximumVal=i;
    }
    if(minimumVal<maximumVal){
        long long int b=0;
        int cmin=a[minimumVal];
        for(int i=minimumVal+1;i<=maximumVal;i++){
            if(a[i]>=cmin){
                cmin=a[i];
                b++;
            }
        }
        cmin=a[maximumVal];
        for(int i=maximumVal-1;i>minimumVal;i--){
            if(a[i]<=cmin){
                cmin=a[i];
                b++;
            }
        }
        return b+f(s,minimumVal-1)+f(minimumVal+1,maximumVal-1)+f(maximumVal+1,e);
    }
    long long int b=0;
    int cmin=a[minimumVal];
    for(int i=minimumVal+1;i<=e;i++){
        if(a[i]>=cmin){
            cmin=a[i];
            b++;
        }
    }
    cmin=a[maximumVal];
    for(int i=maximumVal-1;i>=s;i--){
        if(a[i]<=cmin){
            cmin=a[i];
            b++;
        }
    }
    return b+f(s,maximumVal-1)+f(maximumVal+1,minimumVal-1)+f(minimumVal+1,e);
}


int main (){
	cin>> n;
	a=new int [n];
	// for (int i=0; i<n; i++){
	// 	id[i]=i;
	// }

	for (int i=0; i<n; i++){
		cin >> a[i];
	}

	int *v=new int [n];
	v[0]=-1;

	long long int ns[n];
	ns[0]=1;

	for (int i=1; i<n; i++){
		int j=i-1;
		while (j>=0 && a[j]<a[i])
			j=v[j];

		v[i]=j;
		ns[i]=i-j;
	}
	delete[] v;
	v=new int[n];

	v[n-1]=n;

	for (int i=n-2; i>=0; i--){
		int j=i+1;
		while (j<n && a[j]<a[i])
			j=v[j];
		v[i]=j;
		ns[i]+=(j-i-1)*ns[i];
	}

	for (int i=0; i<n; i++){
		cout << ns[i] << " ";
	}

	cout << endl;
	///===========================================
	// cout<<"\n";
    // bool b=true;
    // for(int i=1;i<n;i++){
    //     if(a[i]!=a[i-1]){
    //         b=false;
    //         break;
    //     }
    // }
    // if(b){
    //     long long int l=n;
    //     cout<<(l*(l+1))/2<<"\n";
    // }
    // else cout<<f(0,n-1)+n<<"\n";

	long long int val=0;

	vector <int> maxIndex;
	int minIndex=0;
	int minVal=a[0];

	vector <int> maxVal;

	long long int s[n];
	s[0]=1;
	// maxIndex.push_back(0);
	// maxVal.push_back(a[0]);

	for (int i=1; i<n; i++){

		if (a[i]<a[i-1]){
			s[i]=1;
			maxIndex.push_back(i-1);
			maxVal.push_back(s[i-1]);
			// cout << "maxVal Size increased, new size : " << maxVal.size() << " at i = "<< i << endl;
			// break;
		}

		if (a[i]==a[i-1]){
			s[i]=s[i-1]+1;
			// break;
		}

		if (a[i]>a[i-1]){
			if (maxVal.size()==0){
				// cout << "maxVal size = 0 at i = " << i << endl;
				s[i]=s[i-1]+1;
			}
			else{
				// cout << "maxVal size not equal to 0 at i = " << i << endl;
				if (a[maxIndex[maxVal.size()-1]]>a[i]){
					// cout << "aa11 entered at i = " << i << endl;
					// cout << maxVal[maxVal.size()-1] << " " << a[i] <<endl;
					s[i]=s[i-1]+1;
					// continue;
				}
				else {

					// cout << "entered hgvdgvsuh" << endl;
					for (int j=maxVal.size()-1; j>=0; j--){
						if (maxIndex[j]>minIndex){
							// cout << i << " maxIndex > minIndex " ;
							if (maxVal[j]>a[i]){
								s[i]=maxVal[j]+1;
							}
							// cout << s[i] << endl;
							// break;
						}

						else {
							if (j==maxVal.size()-1){
								s[i]=s[i-1]+1;
								// cout << "initial termination  " <<j<< endl;
							}

							// else
							// 	s[i]=maxVal[j+1]+1;
						}
					}
				}
			}

		}
		if (a[i]<minVal){
			minVal=a[i];
			minIndex=i;
		}
	}

	for (int i=0; i<n; i++){
		// cout << s[i] << " " ;
		val+=s[i];
	}
	// cout << endl;
	cout << val;




}