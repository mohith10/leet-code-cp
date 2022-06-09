#include <iostream>
#include<vector>
using namespace std;
struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    void reducePrefix(){
        cntPrefix--;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
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
                node->increasePrefix();
            }
            node->increaseEnd();
        }
        
        int countWordEqualTo(string word){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    return false;
                }
                node = node->get(word[i]);
            }
            return node->getEnd();
        }
        
        int countWordsStartingWith(string prefix){
            Node* node = root;
            for(int i=0;i<prefix.length();i++){
                if(!node->containsKey(prefix[i])){
                    return 0;
                }
                node = node->get(prefix[i]);
            }
            return node->getPrefix();
        }
        void erase(string word){
            Node* node = root;
            for (int i=0;i<word.size();i++){
                if(node->containsKey(word[i])){
                    node = node->get(word[i]);
                    node->reducePrefix();
                }
                else{
                    return;
                }
            }
            node->deleteEnd();
        }
};
int main() {
	Trie trie;
	trie.insert("apple");
	trie.insert("apple");
	trie.insert("apple");
    cout<<trie.countWordEqualTo("apple")<<endl;
    cout<<trie.countWordsStartingWith("app")<<endl;
    trie.erase("apple");
    cout<<trie.countWordEqualTo("apple")<<endl;
    return 0;
}
