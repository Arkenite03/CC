#include <bits/stdc++.h>
using namespace std;

bool check(int qn, int c, vector <int> &col){
    
    //qn=row, c=column number of queen to be checked
    //col[i] = row, i =col of current position
    for(int i = 0; i < col.size(); i++){
        if(col[i] == -1)
            continue;            
        if(abs(qn - col[i]) == abs(c-i))
            return false;            
    }        
    return true;        

}
    
void nqueens(int n, int qn, vector <int> &col, vector <vector<string>> &ans, vector <string> &curr){
    
    if(qn == n){           
        ans.push_back(curr);
        return ;
    }
    
    // check if any column is available or not for queen qn(row is already fixed)
    for(int c = 0; c < n; c++){
        if(col[c] != -1)
            continue;
        else if(check(qn, c, col)){    
            col[c] = qn;
            curr[qn][c] = 'Q';
            nqueens(n, qn + 1, col, ans, curr);
            col[c] = -1;
            curr[qn][c] = '.';

        }
        else
            continue;                
    }
}

void solveNQueens(int n) {
    vector <vector<string>> ans;
    vector <int> col(n, -1);        
    vector <string> curr(n, string(n, '.'));
    nqueens(n, 0, col, ans, curr);
    for(auto u : ans){
        for(auto r : u){
            cout << r << "\n";
        }
        cout << "\n" << "\n";
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    solveNQueens(n);
    return 0;
}
