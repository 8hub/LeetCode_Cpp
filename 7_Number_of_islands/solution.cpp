#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void destroyIsland(vector<vector<char>> &grid, int y, int x){
        if(x<0 || y<0 || y>=grid.size() || x>=grid[0].size()){
            return;
        }
        if (grid[y][x] == '1'){
            grid[y][x] = '0';
            destroyIsland(grid, y-1, x);    //check UP
            destroyIsland(grid, y+1, x);    //check DOWN
            destroyIsland(grid, y, x-1);    //check LEFT
            destroyIsland(grid, y, x+1);    //check RIGHT
        }
        else return;
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    destroyIsland(grid, i, j);
                    counter++;
                }
            }
        }
        return counter;
    }
};

int main(){
    Solution s = Solution();
    vector<vector<char>> vec1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    vector<vector<char>> vec2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','1'},
        {'0','0','0','0','1'}
    };
    cout << s.numIslands(vec1) << endl;     //1
    cout << s.numIslands(vec2) << endl;     //3
    return 0;
}