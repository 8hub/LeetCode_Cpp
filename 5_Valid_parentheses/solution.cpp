#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> elements;
        unordered_map<char,char> parentheses = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}};
        for(auto &c:s){
            //opening parentheses -> add to stack
            if(parentheses.find(c) != parentheses.end()){
                elements.push(c);
            }
            //close parentheses not matching last open -> return false
            else if(elements.empty() || c != parentheses[elements.top()]){
                return false;
            }
            else elements.pop();
            
        }
        if (elements.size() != 0){
            return false;
        }
        return true;
    }
};

int main(){
    Solution sol = Solution();
    sol.isValid(")");
    return 0;
}