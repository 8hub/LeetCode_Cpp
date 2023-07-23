#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <utility>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

    //Add connection to existing node
class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<int,Node*> created_node;
        if(node == nullptr){
            return nullptr;
        }
        Node* copy_node = new Node(node->val);
        cloneNode(node, copy_node, created_node);
        return copy_node;
    }

    //method create a copy_node and link it to its neighbors
    void cloneNode(Node *base_node, Node *copy_node, std::unordered_map<int, Node*> &created_node){
        //Node has already been created
        if(created_node.find(base_node->val) != created_node.end()) return;

        copy_node->val = base_node->val;

        //Add created node to map so it can be checked later, not to create the same Node again
        created_node.insert(std::make_pair(copy_node->val, copy_node));

        //Create a neighbors and link the current node to them
        for(auto base_neighbor : base_node->neighbors){
            //Neighbor already exist
            if(created_node.find(base_neighbor->val) != created_node.end()){
                copy_node->neighbors.push_back(created_node.at(base_neighbor->val));
            }
            
            //Neighbor do not exist - have to create one
            else{
                Node *copy_neighbor = new Node(base_neighbor->val);
                copy_node->neighbors.push_back(copy_neighbor);
                cloneNode(base_neighbor, copy_neighbor, created_node);
            }
        }
    }

    //deallocate memory of each node
    void deleteGraph(std::unordered_map<int,Node*> &created_node){
        for(auto node:created_node){
            delete node.second;
        }
    }
};

int main(){
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    n1->neighbors.push_back(n2);
    n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n4);
    n4->neighbors.push_back(n1);
/*
Still when creating a DerivedNode it goes to infinite loop - to change
*/
    Solution sol = Solution();
    Node* cloned = sol.cloneGraph(n1);
    delete n1;
    delete n2;
    delete n3;
    delete n4;

    Node *no_node = new Node();
    Node* cloned2 = sol.cloneGraph(no_node);
    return 0;
}