//
//  main.cpp
//  MatrixChainMultiplication
//
//  Created by Manu Shah on 06/03/16.
//  Copyright © 2016 Manu. All rights reserved.
//

#include <iostream>
#include <climits>
using namespace std;

int getMinMultiplications (int * P, int n) {
    
    int M[n][n];
    
    for (int i = 1;i<n;i++){
        M[i][i] = 0;
    }
    
    //chain length
    for (int l=2; l <= n;l++) {
        for (int i = 1; i <= n - l +  1; i++) {
            int j = l+i-1;
            
            M[i][j] = INT_MAX;
            for (int k = i; k <= j-1; k++) {
                
                int thiscost = M[i][k] + M[k+1][j] + P[i-1]*P[k]*P[j];
                
                if (thiscost < M[i][j]) {
                    M[i][j] = thiscost;
                }
            }
        }
    }
    
    for (int i = 0;i<n;i++) {
        for (int j = 0;j<n; j++) {
            cout<<M[i][j]<<"\t";
        }
        cout<<"\n";
    }
    
    return M[1][n-1];
}

int main(int argc, const char * argv[]) {
    
    int n;
    cin>>n;
    
    int * P =  new int [n];
    
    for (int i = 0; i < n; i++) {
        cin>>P[i];
    }
    
    int m = getMinMultiplications (P, n);
    
    cout<<m;
    
    return 0;
}