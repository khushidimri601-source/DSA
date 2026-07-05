class Solution {
public:
    int n;
    int MOD=1e9+7;
    vector<vector<pair<int,int>>>t;
    int getIntFromChar(char ch){
        return ch!='S'?ch-'0':0;
    }
    bool isValid(int i,int j,vector<string> &board){
        return(i>=0 && j>=0 && j<n && i<n && board[i][j]!='X' );
    }

    pair<int,int>solve(int i,int j,vector<string>& board){
        if(board[i][j]=='E')
         return {0,1};
         if(board[i][j]=='X')
         return {0,0};
         if(t[i][j]!=make_pair(-1,-1))
           return t[i][j];
        int upScore=0;
        int upPath=0;
        int leftScore=0;
        int leftPath=0;
        int diagScore=0;
        int diagPath=0;
        char ch=board[i][j];
        if(isValid(i-1,j,board)){
        auto [score,path]=solve(i-1,j,board);
        upScore=score;
        upPath=path;
        if(upPath>0)
        upScore+=getIntFromChar(ch);
        }
        if(isValid(i,j-1,board)){
        auto [score,path]=solve(i,j-1,board);
        leftScore=score;
        leftPath=path;
        if(leftPath>0)
        leftScore+=getIntFromChar(ch);
        }
        if(isValid(i-1,j-1,board)){
        auto [score,path]=solve(i-1,j-1,board);
        diagScore=score;
        diagPath=path;
        if(diagPath>0)
        diagScore+=getIntFromChar(ch);
        }
        int bestScore,bestPath;
        if(upScore==leftScore && leftScore==diagScore){
            bestScore=upScore;
            bestPath=upPath+leftPath+diagPath;
        }
        else if(upScore==leftScore){
            bestScore=upScore;
            bestPath=upPath+leftPath;
            if(diagScore > bestScore ||
   (diagScore == bestScore && diagPath > bestPath)){
            bestScore=diagScore;
            bestPath=diagPath;}
        }
        else{
            bestScore=upScore;
            bestPath=upPath;
            if(leftScore>bestScore ||(leftScore==bestScore && leftPath>bestPath)){
                bestScore=leftScore;
                bestPath=leftPath;
            }
            if(diagScore>bestScore || diagScore==bestScore && diagPath>bestPath){
                bestScore=diagScore;
                bestPath=diagPath;
            }
        }
             t[i][j] = {bestScore, bestPath % MOD};
            return t[i][j];




    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        n=board.size();
        t.assign(n,vector<pair<int,int>>(n,{-1,-1}));
        pair<int,int> result=solve(n-1,n-1,board);
        return {result.first,result.second};     
    }
};
