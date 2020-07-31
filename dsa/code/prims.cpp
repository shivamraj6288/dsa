#include <bits/stdc++.h>
using namespace std;
#define max INT32_MAX



int main (int argc, char *argsv[]){

    int n;
    cin >> n;
//    cout << max << endl;
    int data[n+1][n+1];
    for (int i=0; i<=n; i++){
        for (int j=0; j<=n; j++){
            data[i][j]=max;
        }
    }

//    cout << data[4][5]<< endl;
    int edges;
    cin >> edges;
    for (int i=1; i<=edges; i++){
        int v1, v2, w;
        cin>> v1>> v2>> w;
        data[v1][v2]=w;
        data[v2][v1]=w;
    }

    int near[n+1]={max};
    int s_edge[2][n-1];

    int min=max;
    int m1=1, m2=2;
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            if (data[i][j]<min){
                m1=i;
                m2=j;
                min=data[i][j];
            }
        }
    }
    s_edge[0][0]=m1;
    s_edge[1][0]=m2;

//    cout << m1<<","<<m2 << endl;
    for (int i=1; i<=n; i++){
        if (i==m1 || i==m2){
            near[i]=0;
        }
        else if (data[i][m1]<=data[i][m2]){
//            cout << data[i][m1] << ","<< data[i][m2] << endl;
            near[i]=m1;
        }
        else {
            near[i]=m2;
        }

    }
//    cout << endl;
//    for (int i=0; i<=n; i++){
//        cout << near[i]<< ",";
//    }
//    cout << endl;
//    cout << endl;

    int current;

    for (int i=1; i<=(n-2); i++){
        int cmin = max ;
        for (int j=1; j<=n; j++){
            if (data[j][near[j]]<cmin){
                current=j;
                cmin=data[j][near[j]];
            }
        }

        s_edge[0][i]=near[current];
        s_edge[1][i]=current;
        near[current]=0;


        for (int k=1; k<=n; k++){
            if (near[k]!=0){
                if (data[k][near[k]]>data[k][current]){
                    near[k]=current;
                }
            }
        }



    }

    int sum=0;
//    cout << s_edge[0][0] << ",";
    cout << endl;
    for (int l=0; l<(n-1); l++){
        sum+=data[s_edge[0][l]][s_edge[1][l]];
        cout << s_edge[0][l] << "," << s_edge[1][l]<< endl;
    }

    cout << "Minimum length of spanning tree = " << sum << endl;

}