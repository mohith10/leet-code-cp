// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
private:
        Node* root;
public:
    Trie(){
        root = new Node();
    }
public:
    void insert(int number){
        Node* node = root;
        for(int i=31;i>=0;i--){
            if(!node->containsKey((number>>i)&1)){
                node->put((number>>i)&1, new Node());
            }
            node = node->get((number>>i)&1);
        }
    }
public:    
    int maxXOR(int number){
        Node* node = root;
        int maxRes = 0;
        for(int i=31;i>=0;i--){
            int bit = ((number>>i)&1);
            if(node->containsKey(1-bit)){
                maxRes = maxRes | (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return maxRes;
    }
};
int main() {
    Trie trie;
    vector<int> arr1,arr2;
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);
    arr2.push_back(7);
    arr2.push_back(8);
    for(auto &it: arr1){
        trie.insert(it);
    }
    int res = 0;
    for(auto &it: arr2){
        res = max(res,trie.maxXOR(it));
    }
    cout<<res;
    return 0;
}
