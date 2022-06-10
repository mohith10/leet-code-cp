#include <iostream>
#include<vector>
using namespace std;
struct Node{
    Node* links[26];
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
   
};
class Trie{
    private: 
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        
        int countSubstring(string word){
            int count = 0;
            for(int i=0;i<word.size();i++){
                Node* node = root;
                for(int j=i;j<word.size();j++){
                    if(!node->containsKey(word[j])){
                        count++;
                        node->put(word[j],new Node());
                    }
                    node = node->get(word[j]);
                }
            }
            return count+1;
        }
};
int main() {
	Trie trie;
	string s;
	getline(cin,s);
	cout<<trie.countSubstring(s);
    return 0;
}
