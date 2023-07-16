#include <iostream>
#include <vector>
using namespace std;
class Solution {
private:
    void checkNext(vector<vector<char>> &board, int current_idx, string &word, int x, int y, vector<vector<bool>> &checked, bool &found){
        if (word.length() == current_idx || found == true){
            found = true;
        }
        //Out of border
        else if (y<0 || x<0 || y>=board.size() || x>=board[0].size()) return;
        //char was checked
        else if(checked[y][x] == true) return;
        else if(board[y][x] == word[current_idx]){
            checked[y][x] = true;
            checkNext(board, current_idx+1, word, x-1, y, checked, found);
            checkNext(board, current_idx+1, word, x+1, y, checked, found);
            checkNext(board, current_idx+1, word, x, y-1, checked, found);
            checkNext(board, current_idx+1, word, x, y+1, checked, found);
            checked[y][x] = false;
            return;
        }
        return;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;
        vector<bool> checked_x (board[0].size(), false);
        vector<vector<bool>> checked (board.size(), checked_x);
        checkNext(board, 0, word, 0, 0, checked, found);
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0]) checkNext(board, 0, word, j, i, checked, found);
                if (found) return true;
            }
        }
        return found;
    }
};

int main(){
    Solution sol = Solution();
    vector<vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    cout << sol.exist(board, "ABCCED") << endl;
    cout << sol.exist(board, "SEE") << endl;
    cout << sol.exist(board, "ABCB") << endl;

    return 0;
}