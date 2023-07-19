/*
        //====RECIRSIVE SOLUTION IS TO SLOW====
class Solution{
    public:
    int climbStairs(int n){
        int count_combinations {0};
        addCombination(n, count_combinations);
        return count_combinations;
    }

    private:
    void addCombination(int steps_left, int &count_combinations){
        if(steps_left == 0){
            count_combinations++;
            return;
        }
        if(steps_left > 0){
            addCombination(steps_left-1, count_combinations);
        }
        if(steps_left>1){
            addCombination(steps_left-2, count_combinations);
        }
    }
};
*/
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

//Faster solution using memory to save checked nr of possibilities from left nr of stairs
class Solution{
    public:
    int climbStairs(int n){
        unordered_map<int,int> step_nr_to_possibilities;
        return addCombination(n, 0, step_nr_to_possibilities);
    }

    private:
    int addCombination(int &all_steps, int curr_position, unordered_map<int,int> &step_nr_to_possibilities){
        if(step_nr_to_possibilities.find(curr_position) != step_nr_to_possibilities.end()){
            return step_nr_to_possibilities[curr_position];
        }
        if(curr_position == all_steps){
            return 1;
        }
        if(curr_position < all_steps){
            step_nr_to_possibilities[curr_position] = addCombination(all_steps, curr_position+1, step_nr_to_possibilities)
             + addCombination(all_steps, curr_position+2, step_nr_to_possibilities);
        }
        return step_nr_to_possibilities[curr_position];
    }
};


/*
Can be solved using Fibonacci sequence:
Solution from step 'n' are solution from step (n+1) + solution from step (n+2)
because because from step 'n' you can step to step (n+1) or to step (n+2)
using this approach algorithm would be faster and take less memory!
*/
int main(){
    Solution sol = Solution();
    cout << sol.climbStairs(1) << endl;
    cout << sol.climbStairs(2) << endl;
    cout << sol.climbStairs(44) << endl;
    cout << sol.climbStairs(45) << endl;
    return 0;
}