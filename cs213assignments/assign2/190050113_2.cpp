#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define llu long long unsigned int
char *cl;
map <char, int> id;
int k;
string *fv;

vector <vector<bool>>check;
vector <vector<unsigned long long int>> lv;
vector<vector<unsigned long long int>> mat;

vector <vector<unsigned long long int>> squaremat (vector <vector<unsigned long long int>> a ) {
	// vector <unsigned long long int> temp(k,0);
	vector <vector<unsigned long long int>> mul;
	for (int i=0; i<k; i++){
		vector<unsigned long long int> temp;
		for (int i=0; i<k; i++){
			temp.push_back(0);
		}
		mul.push_back(temp);
	}

    for (int i = 0; i < k; i++) 

    {

        for (int j = 0; j < k; j++) 

        { 

            // mul[i][j] = 0; 

            for (int l = 0; l < k; l++) 

                mul[i][j] += a[i][l]*a[l][j]; 

        } 

    } 

    return mul;

}

vector <vector<unsigned long long int>> multiply (vector <vector<unsigned long long int>> a, vector <vector<unsigned long long int>>b ) {
	// vector <unsigned long long int> temp(k,0);
	vector <vector<unsigned long long int>> mul;
	for (int i=0; i<k; i++){
		vector<unsigned long long int> temp;
		for (int i=0; i<k; i++){
			temp.push_back(0);
		}
		mul.push_back(temp);
	}

    for (int i = 0; i < k; i++) 

    {

        for (int j = 0; j < k; j++) 

        { 

            // mul[i][j] = 0; 

            for (int l = 0; l < k; l++) 

                mul[i][j] += a[i][l]*b[l][j]; 

        } 

    } 

    return mul;

}

vector <vector<unsigned long long int>> power (vector <vector<unsigned long long int>> a, unsigned long long int n){
	if (n==1){
		// cout << "power is 1 : " << n << endl;
		return a;
	}



	if (n%2==0){
		// cout << "power is 2 : " << n << endl;
		return (squaremat(power(a,n/2)));
	}

	// cout << "power is 3 : " << n << endl;
	return (multiply(a, squaremat(power(a,n/2))));
	
}

unsigned long long int f1fast(unsigned long long int n){
	if (n==0){
		return 1;

	}
	// cout << "before\n";
	vector <vector<unsigned long long int>> val=power(mat,n);
	// cout << "after \n";
	unsigned long long int rs=0;
	// cout << "val size : " << val.size() << "," << val[0].size() << endl;
	for (int i=0; i<k; i++){
		// cout << "i value while calculating rs : " << i << endl;
		rs+=val[0][i];
	}	

	return rs;
}



unsigned long long int f1 (unsigned long long int n){
	// unsigned long long int lv[k][n+1];

	if (check[0].size()==0){
		for (int i=0; i<k; i++){
			// lv[i][0]=1;
			// lv[i][1]=fv[i].length();
			vector <unsigned long long int>t0;
			t0.push_back(1);
			// t0.push_back(fv[i].length());
			// vector <unsigned long long int>t1;
			lv.push_back(t0);
			// vector<bool> bt;
			// bt.push_back(true);
			check[i].push_back(true);
		}
	}

	if (check[0].size()==1){
		for (int i=0; i<k; i++){
			lv[i].push_back(fv[i].length());
			check[i].push_back(true);
		}
	}
	if (n==0 || n==1){
		return lv[0][n];
	}

	for (unsigned long long int i=check[0].size(); i<=n; i++){
		for (int j=0; j<k; j++){
			lv[j].push_back(0);
			for (int al=0; al<fv[j].length(); al++){
				lv[j][i]+=lv[id[fv[j][al]]][i-1];
			}
			check[j].push_back(true);


			// cout << lv[j][i] << " ";
		}

		// cout << endl;
	}
	return lv[0][n];
}

char f2helper (unsigned long long int i, unsigned long long int n, char x){
	// cout << "f2helper check : i,n,x " << i << " " << n << " " << x << endl;
	if (n==1){
		// cout << "i, n, x : " <<i <<" " << n<< " "<< x << endl;
		return fv[id[x]][i];
	}
	unsigned long long int vl=0;
	char b;
	for (int j=0; j<fv[id[x]].length();j++){
		vl += lv[id[fv[id[x]][j]]][n-1];
		if (vl>= i+1){
			b=fv[id[x]][j];
			vl -= lv[id[fv[id[x]][j]]][n-1];
			i-=vl;
			break;
		}
	}

	return f2helper(i, n-1, b);
}

char f2 (unsigned long long int n,char x){
	unsigned long long int val=11110;
	// bool bch=true;
	// // cout <<val << endl;
	// if (lv.size()>0){
	// 	// cout << lv[id[x]][check[id[x]].size()-1] << " check 1 complete\n";
	// 	if (lv[id[x]][check[id[x]].size()-1]>n+1){
	// 		for (unsigned long long int i=check[id[x]].size()-1; i>=0; i--){
	// 			if (lv[id[x]][i]<n+1){
	// 				val=i+1;
	// 				bch=false;
	// 				break;
	// 			}
	// 		}
	// 	}
	// }

	// if (bch) {
	// 	for (unsigned long long int i=check[id[x]].size(); true; i++){
	// 		if (f1(i)>=n+1){
	// 			val=i;
	// 			// cout << "check 2 " << val << endl;
	// 			break;
	// 		}
	// 	}
	// }
	// // if (val==11110){
	// 	// return ('s');
	// // }
	// // cout << "req value greater than given i : " << val << endl;

	// return (f2helper(n,val,x));

	for (unsigned long long int i=0; true; i++){
		if (f1(i)>=n+1){
			val=i;
			// cout << "check 2 " << val << endl;
			break;
		}
	}

	return (f2helper(n,val,x));


	

}

void computeLPSArray(char* pat, int M, int* lps); 
  
long long int KMPSearch(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    int lps[M]; 
  
    computeLPSArray(pat, M, lps); 
  
    int i = 0; 
    int j = 0;
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
        	ll rsVal=i-j;
        	j = lps[j - 1];
            return rsVal;
             
        }  
        else if (i < N && pat[j] != txt[i]) { 

            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    }
    return -1;
} 
  
void computeLPSArray(char* pat, int M, int* lps) 
{ 
    int len = 0; 
  
    lps[0] = 0;
  
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else
        { 

            if (len != 0) { 
                len = lps[len - 1]; 
            } 
            else
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}

unsigned long long int f3 (string pat){
        string f20k="";
        f20k+=fv[0];
        int last_size=1;
        while(f20k.size()<20000){
            int csize=f20k.size();
            for(int i=last_size;i<csize;i++){
                f20k+=fv[id[f20k[i]]];
            }
            last_size=csize;
        }
        f20k+='\n';
        char cpat[pat.size()+1];
        char ctxt[f20k.size()+1];
        strcpy(cpat,pat.c_str());
        strcpy(ctxt,f20k.c_str());
        long long int  si=KMPSearch(cpat,ctxt);
        if(si == -1 ) return -1;
        else{
            vector<vector<unsigned long long int>> f;
            vector<unsigned long long int > temp(k,1);
            f.push_back(temp);
            while(si+pat.size()-1>=f[f.size()-1][0]){
                vector<unsigned long long int> tem(k);
                for(int j=0;j<k;j++){
                    tem[j]=0;
                    for(int p=0;p<fv[j].size();p++){
                        tem[j]+=f[f.size()-1][fv[j][p]-97];
                    }
                }
                f.push_back(tem);
            }
            int n=f.size()-1;
            return si;
        }
}


int main () {
	cin >> k;
	char tcl[6]={'a','b','c','d','e','f'};
	id['a']=0; id['b']=1; id['c']=2; id['d']=3; id['e']=4; id['f']=5;
	cl=new char[k];

	fv=new string[k];

	vector <bool> bt1;

	for (int i=0; i<k; i++){
		cin >> fv[i];
		cl[i]=tcl[i];
		check.push_back(bt1);
	}


	for (int i=0; i<k; i++){
		vector <unsigned long long int> temp(k,0);
		for (int j=0; j<fv[i].length(); j++){
			switch (fv[i][j]){
				case 'a' :
					temp[0]++;
					break;
				case 'b':
					temp[1]++;
					break;
				case 'c':
					temp[2]++;
					break;
				case 'd':
					temp[3]++;
					break;
				case 'e':
					temp[4]++;
					break;
				case 'f':
					temp[5]++;
					break;

			}

		}
		mat.push_back(temp);

	}

	// cout << "mat size : "<< mat.size() << ","<< mat[0].size() << endl;

	for (int i=0; i<k; i++){
		for (int j=0; j<k; j++){
			// cout << mat[i][j] << " ";
		}
		// cout << endl;
	}

	// cout << "mat is formed" << endl;

	int T;
	cin >> T;

	for (int t=0; t<T; t++){
		int q;
		cin >> q;
		switch (q) {
			// case 0:
			// 	unsigned long long int n;
			// 	cin >> n;
			// 	cout << f1(n)<< endl;
			// break;

			case 0:
				unsigned long long int n;
				cin >> n;
				cout << f1fast(n)<< endl;
				break;

			case 1:
				cin >> n;
				// cout << n << endl;	
				cout <<f2(n,'a')<< endl;
				break;

			// case 2:
			// 	string pat;
			// 	cin>>pat;
   //          string txt="";
   //          txt+=fv[0];
   //          int last_size=1;
   //          while(txt.size()<20000){
   //              int curr_size=txt.size();
   //              for(int i=last_size;i<curr_size;i++){
   //                  txt+=fv[txt[i]-97];
   //              }
   //              last_size=curr_size;
   //          }
   //          txt+='\n';
   //          char cpat[pat.size()+1];
   //          char ctxt[txt.size()+1];
   //          strcpy(cpat,pat.c_str());
   //          strcpy(ctxt,txt.c_str());
   //          ll si=KMPSearch(cpat,ctxt);
   //          if(si == -1 ) cout<<"-1"<< endl;
   //          else{
   //          	cout << "si is noy -1 \n"; 
   //              vector<vector<llu>> f;
   //              vector<llu> temp(k,1);
   //              f.push_back(temp);
   //              while(si+pat.size()-1>=f[f.size()-1][0]){
   //                  vector<llu> tem(k);
   //                  for(int j=0;j<k;j++){
   //                      tem[j]=0;
   //                      for(int p=0;p<fv[j].size();p++){
   //                          tem[j]+=f[f.size()-1][fv[j][p]-97];
   //                      }
   //                  }
   //                  f.push_back(tem);
   //              }
   //              int n=f.size()-1;
   //              cout<<n<<" "<<si<<"\n";
   //          }
			// break ;

				// case 2:
				// 	string pat;
				// 	cin >> pat;
				// 	unsigned long long int nmin;
				// 	long long int si=-1;
				// 	for (int i=0; true; i++){
				// 		if (f1(i)>=pat.length()){
				// 			nmin=i;
				// 			break;
				// 		}
				// 	}

			// 		string txt="";
		 //            txt+=fv[0];
		 //            int last_size=1;
			        
			//             for(int itr=1; itr<=nmin; itr++){
			//                 int curr_size=txt.size();
			//                 for(int i=last_size;i<curr_size;i++){
			//                     txt+=fv[txt[i]-97];
			//                 }
			//                 last_size=curr_size;
			//             }
			//             // txt+='\n';
			//         for(int incr=0; incr<5; incr++){
			//         	int curr_size=txt.size();
		 //                for(int i=last_size;i<curr_size;i++){
		 //                    txt+=fv[txt[i]-97];
		 //                }
		 //                last_size=curr_size;
			//             char cpat[pat.size()+1];
			//             char ctxt[txt.size()+1];
			//             strcpy(cpat,pat.c_str());
			//             strcpy(ctxt,txt.c_str());
			//             si=KMPSearch(cpat,ctxt);

			//             if (si!=-1){
			//             	nmin=nmin+incr;
			//             	break;
			//             }
		 //        	}

		 //        	if (si==-1){
		 //        		cout << -1 << endl;
		 //        	}
		 //        	else {
		 //        	cout << nmin << " " <<si<< endl;		        		
		 //        	}

			// 		break;

			// case 3:
			// 	string pat;cin>>pat;
	  //           string txt="";
	  //           txt+=c[0];
	  //           int last_size=1;
	  //           while(txt.size()<20000){
	  //               int curr_size=txt.size();
	  //               for(int i=last_size;i<curr_size;i++){
	  //                   txt+=c[txt[i]-97];
	  //               }
	  //               last_size=curr_size;
	  //           }
	  //           int i=0,j=0,lpat=pat.size(),ltxt=txt.size();
	  //           while(j!=ltxt){
	  //               if(pat[i]==txt[j]){
	  //                   i++;
	  //                   if(i==lpat) break;
	  //               }
	  //               j++;
	  //           }
	  //           if(j==ltxt) cout<<"-1\n";
	  //           else{
	  //               ll si=j;
	  //               vector<vector<llu>> f;
	  //               vector<llu> temp(k,1);
	  //               f.push_back(temp);
	  //               while(si>=f[f.size()-1][0]){
	  //                   vector<llu> tem(k);
	  //                   for(int j=0;j<k;j++){
	  //                       tem[j]=0;
	  //                       for(int p=0;p<c[j].size();p++){
	  //                           tem[j]+=f[f.size()-1][c[j][p]-97];
	  //                       }
	  //                   }
	  //                   f.push_back(tem);
	  //               }
	  //               int n=f.size()-1;
	  //               cout<<n<<" "<<si+1<<"\n";
	  //           }
			// 	break;

		}
	}

}