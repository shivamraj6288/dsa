#include <bits/stdc++.h>
using namespace std;

string solve(string A)
{
	cout << A<< "\n";
    int n = A.length();
    // int minId = n - 1;
    // int sec = n - 1;
    // int min = atoi(A[n - 1]);
    // int smin = min;
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (stoi(A[i]+"")<min){
    //         sec = minId;
    //         minId = i;
    //         smin = min;
    //         min = stoi(A[minId]+"");
    //     }
    // }
    int na[n];
    for (int i=0;i<n; i++){
    	na[i]=atoi(A[i]+"");
    }
    int id=-1;
    for (int i=n-2; i>=0;i--){
    	if (A[i]<=A[i+1]){
    		id=i;
    		break;
    	}
    }
    if (id==-1)
    	return "-1";
    cout << "id found : " << id <<"\n";
    int leastMaxId=(lower_bound(na+id+1,na+n,na[id]))-na;
    cout << "leastMaxId : " << leastMaxId << "\n";
    int t=na[id];
    na[id]=na[leastMaxId];
    na[leastMaxId]=t;

    int origin=id+1;
    int tl=n-id-2;
    for (int i=0;i<tl-1;i++){
    	t=na[origin+i];
    	na[origin+i]=na[tl-1-i+origin];
    	na[tl-1-origin]=t;
    }
    leastMaxId=(lower_bound(na+id+1,na+n-1,na[n-1]))-na;
    while (true){
    	leastMaxId--;
    	if(na[leastMaxId]<=na[n-1]){
    		leastMaxId++;
    		int last=na[n-1];
    		for (int i=n-2;i>=leastMaxId;i--){
    			na[i]=na[i+1];

    		}
    		na[leastMaxId]=last;
    		break;
    	}
    }
    string rs="";
    for (int i=0;i<n; i++){
    	rs=rs+to_string(na[i]);
    }
    return rs;



    
}
int main()
{
    string n;
    cin >> n;
    cout << solve(n) << endl;
}