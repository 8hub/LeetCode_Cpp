#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int>current;
        sort(nums.begin(), nums.end());
        dfs(answer, current, 0, nums);
        return answer;
    }
    /*
    Each layer contain more elements - in eg. [1,2,2,3]
    0 layer contain NULL [ ]
                              [ ]
    1-st layer - just one element (every split with different value)
                              [ ]
                             / | \
                            /  |  \
                          [1] [2] [3]
    2-nd layer with two elements (one different element added to layer 1)
                  [1]            [2]       [3]
                 /   \          /   \ 
                /     \        /     \
             [1,2]   [1,3]   [2,2]  [2,3]   
    3rd layer with three elements (again one different element added)
            [1,2]       [1,3]    [2,2]  [2,3]
            /   \                  |
           /     \                 |
       [1,2,2] [1,2,3]          [2,2,3]
    4th layer with four element (one different added)
        [1,2,2]  [1,2,3]        [2,2,3]
           |
           |
       [1,2,2,3]
    */
private:
    void dfs(vector<vector<int>> &result, vector<int>&curr, int start, vector<int>& nums){
        result.push_back(curr);
        for(int i = start; i <nums.size(); i++){
            if(i>start && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            dfs(result, curr, i+1, nums);
            curr.pop_back();
        }
    
    }
};

int main(){
    Solution s = Solution();
    // vector<int> vec{1,2,2,3};
    vector<int> vec{10,1,2,7,6,1,5};
    s.subsetsWithDup(vec);
    
    return 0;
}