class Solution {
    
public:
    vector<vector<string>>ans;
    bool isValid(vector<string>b, int r, int c){
        for(int i=r;i>=0;i--){
            if(b[i][c]=='Q')
                return false;
        }
        for(int i =r, j= c; i>=0 && j>=0; i--, j--){
            if(b[i][j]=='Q')
                return false;
        }
        for(int i=r, j=c; i>=0 && j<b.size(); i--, j++){
            if(b[i][j]=='Q')
                return false;
        }
        return true;
        
    }
    void rec(vector<string>b, int n, int r){
        if(r == n){
            ans.push_back(b);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(b, r, i)){
                b[r][i] = 'Q';
                rec(b, n, r+1);
                b[r][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>b(n, string(n, '.'));
        rec(b, n, 0);
        return ans;
    }
};
