/*
    Given an m x n grid of characters board and a string word, return true if word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cells, 
    where adjacent cells are horizontally or vertically neighboring. 
    The same letter cell may not be used more than once.

    Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
    Output: true
*/

class Solution {
public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}}; // It will help to change direction
    bool find(vector<vector<char>>& board, int i, int j, string &word, int idx, int row, int col){
        if(idx==word.size()) {
            return true;
        }
        if(i>=row || j>=col || i<0 || j<0 || board[i][j]=='$'){
            return false;
        }
        if(board[i][j]!=word[idx]){
            return false;
        }
        char temp = board[i][j];
        board[i][j]='$';

        for(auto &dir : directions){
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(find(board, new_i, new_j, word, idx+1, row, col)) {
                return true;
            }
        }

        board[i][j] = temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        if(row*col<word.size()) return false;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0] && find(board, i, j, word, 0, row, col)){
                    return true;
                }
            }
        }
        return false;

    }
};