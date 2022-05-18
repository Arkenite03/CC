//By N Purushotam Kumar; 3330; TE-COMP A T2
//Assignment 3 N Queens Problem using Backtracking.
#include <bits/stdc++.h>
using namespace std;

bool issafe(int x,int y , int** arr , int n){
    for(int i=0;i<x;i++){
        if(arr[i][y]==1){
            return false;
        }
    }
    int row = x;
    int col = y;
    while(row>=0 && col>=0){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col--;
    }
    row=x;
    col=y;
    while(row>=0 && col<n){
        if(arr[row][col]==1){
            return false;
        }
        row--;
        col++;
    }
    return true;
}

bool nqueen(int x,int n,int** arr){
    if(x>=n){
        return true;
    }
    for(int i=0;i<n;i++){
        if(issafe(x,i,arr,n)){
            arr[x][i] = 1;
            if(nqueen(x+1 , n ,arr)){
                return true;
            }
            arr[x][i] = 0;
        }
    }
    return false;
}

int main(){
    int n;cin>>n;

    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            arr[i][j] = 0;
        }
    }
    if(nqueen(0,n,arr)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else{
        cout<<"0";
    }
    return 0;
}