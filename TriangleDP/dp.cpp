//
// Created by steph on 3/27/2020.
//

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 101
int D[MAX][MAX];
int n; int *maxSum;

int main() {
    int i, j;
    cin>>n;
    for (i=1; i<=n; i++)
        for (j=1; j<=i; j++)
            cin>>D[i][j];
    maxSum = D[n];
    for (i=n-1; i>=1; --i)
        for (j=1; j<=i; ++j)
            maxSum[j] = max(maxSum[j],maxSum[j+1]) + D[i][j];
    cout<<maxSum[1]<<endl;
}