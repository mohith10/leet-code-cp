#include <iostream>
#include<vector>
using namespace std;
struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};
class Trie{
    private: 
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        
        void insert(string word){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                //moves to the reference trie
                node = node->get(word[i]);
            }
            node->setEnd();
        }
        
        bool search(string word){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                node = node->get(word[i]);
            }
            return node->isEnd();
        }
        bool checkIfPrefixExists(string word){
            bool flag = true;
            Node* node = root;
            for(int i=0;i<word.length();i++){
                if(node->containsKey(word[i])){
                    node = node->get(word[i]);
                    if(node->isEnd() == false){
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            return flag;
        }
        
        bool startsWith(string prefix){
            Node* node = root;
            for(int i=0;i<prefix.length();i++){
                if(!node->containsKey(prefix[i])){
                    return false;
                }
                node = node->get(prefix[i]);
            }
            return true;
        }
};
int main() {
	Trie trie;
	vector<string> a;
	a.push_back("n");
	a.push_back("ni");
	a.push_back("nin");
	a.push_back("ninj");
	a.push_back("ninja");
	a.push_back("ninga");
	for(auto &it: a){
	    trie.insert(it);
	}
    string longest = "";
    for(auto &it: a){
        if(trie.checkIfPrefixExists(it)){
            if(it.length() > longest.length()){
                longest = it;
            }
            else if(it.length() == longest.length() && it<longest){
                longest = it;
            }
        }
    }
    cout<<longest<<endl;
    return 0;
}
