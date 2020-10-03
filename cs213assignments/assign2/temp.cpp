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
            return (i-j);
            j = lps[j - 1]; 
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
long long int get_substring_position(vector<string> str, int k, char* w) {
	char array[40000];
	// long long int n_array[100];
	int prev=1;
	int curr=str[0].size();
	for(int i=0; i<str[0].size(); i++) {
		array[i] = str[0][i];
	}
	while(curr<20000) {
		int curr_temp = curr;
		for(int i=prev; i<curr; i++) {
			string s = str[int(array[i])-97];
			for(int j=curr_temp; j<curr_temp+s.size(); j++) {
				array[j] = s[j-curr_temp];
			}
			curr_temp+=s.size();
		}
		prev = curr;
		curr = curr_temp;
	}
	// cout<<curr<<endl;
	// for(int i=0; i<100; i++) {
	// 	cout<<array[i]<<" ";
	// }
	array[curr] = '\n';
	return KMPSearch(w, array);
}

char w[101];
cin>>w;
long long int ans = get_substring_position(str, k, w);
if(ans==-1) cout<<ans<<endl;
else {
    cout<<ans<<" ";
    long long int n = 0;
    for(int j=1; j<=1000; j++) {
        // cout<<length_fn(str, k, j, 0)<<endl;
        if(length_fn(str, k, j, 0)>(ans+strlen(w)-1)) {n=j; break;}
    }
    cout<<n<<endl;
}