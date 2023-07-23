#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void checkArea(vector<vector<int>> &grid, int y, int x, int &count_area){
        if(x<0 || y<0 || y>=grid.size() || x>=grid[0].size()){
            return;
        }
        if (grid[y][x] == 1){
            grid[y][x] = 0;
            count_area++;
            checkArea(grid, y-1, x, count_area);    //check UP
            checkArea(grid, y+1, x, count_area);    //check DOWN
            checkArea(grid, y, x-1, count_area);    //check LEFT
            checkArea(grid, y, x+1, count_area);    //check RIGHT
        }
        else return;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int current_area = 0;
                    checkArea(grid, i, j, current_area);
                    max_area = max(current_area, max_area);
                }
            }
        }
        return max_area;
    }
};

int main(){
    Solution s = Solution();
    vector<vector<int>> vec1 = {
        {1,1,1,1,0},
        {1,1,0,1,0},
        {1,1,0,0,0},
        {0,0,0,0,0}
    };
    vector<vector<int>> vec2 = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,1},
        {0,0,0,0,1}
    };
    cout << s.maxAreaOfIsland(vec1) << endl;     //1
    cout << s.maxAreaOfIsland(vec2) << endl;     //3
    return 0;
}