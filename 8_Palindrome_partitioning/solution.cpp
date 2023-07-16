#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    bool checkPalindrome(string sub){
        int i = 0;
        int len = sub.length();
        for (int i = 0; i<=(len/2); i++){
            if(sub[i]!=sub[len-1-i]) return false;
        }
        return true;
    }
    void createPalindrome(string s, vector<vector<string>> &answer, vector<string> &curr_sub){
        if(s.length() <=0) {answer.push_back(curr_sub);}
        for(int i = 1; i <= s.length(); i++){
            string part = s.substr(0, i);
            if(checkPalindrome(part)){
                curr_sub.push_back(part);
                createPalindrome(s.substr(i, s.length()-i), answer, curr_sub);
                curr_sub.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        string substr = "";
        int curr_idx = 0;
        vector<vector<string>> answer;
        vector<string> curr_sub;
        createPalindrome(s, answer, curr_sub);
        return answer;
    }
};

int main(){
    Solution s = Solution();
    s.partition("aab");
    s.partition("banaanab");
    s.partition("abcbc");
    return 0;
}