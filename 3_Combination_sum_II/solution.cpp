#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        dfs(target, current, answer, candidates, 0, 0);
        return answer;
    }

    void dfs(int &target, vector<int>& current, vector<vector<int>> &answer, vector<int> &candidates, int start, int curr_sum){
        if(curr_sum == target){
            answer.push_back(current);
            return;
        }
        // else if(start>0 and candidates[start]==candidates[start-1]) return;
        for(int i = start; i < candidates.size(); i++){
            if(i>start && candidates[i] == candidates[i-1]) continue;
            current.push_back(candidates[i]);
            if (curr_sum+candidates[i] <= target){
                dfs(target, current, answer, candidates, i+1, curr_sum+candidates[i]);
            }
            current.pop_back();
        }
    }
};

int main(){
    Solution solution = Solution();
    vector<int> vec = {10,1,2,7,6,1,5};
    vector<int> vec2 = {1,2,2,3};
    solution.combinationSum2(vec, 8);
    return 0;
}