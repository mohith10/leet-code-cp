#include <bits/stdc++.h>
 using namespace std;

 struct Node{
     int data;
     Node* next;
 };

 pair<Node*,Node*> insert(Node* head, Node* tail, int value){
     if(head == NULL){
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        head = newNode;
        return {head,head};
     }
     Node* newNode = new Node();
     newNode->data = value;
     newNode->next = NULL;
     tail->next = newNode;
     tail = newNode;
     return {head,tail};
 }

 void printLinkedlist(Node* head){
     Node* listIterator = head;
     while(listIterator!=NULL){
         cout<<listIterator->data<<" ";
         listIterator = listIterator->next;
     }
     cout<<endl;
 }
 /*Question Code*/
Node* ListPartition(Node* head, int x){
    if(head == NULL) return NULL;
    Node* headOfSmallerElementList = NULL;
    Node* tailOfSmallerElementList = NULL;
    Node* headOfLargerElementList = NULL;
    Node* tailOfLargerElementList = NULL;
    
    Node* listIterator = head;
    while(listIterator!=NULL){
        if(listIterator->data < x){
            //cout<<listIterator->data<<" ";
            auto res = insert(headOfSmallerElementList, tailOfSmallerElementList, listIterator->data);
            headOfSmallerElementList = res.first;
            tailOfSmallerElementList = res.second;
            //cout<<headOfSmallerElementList->data<<" "<<tailOfSmallerElementList->data<<endl;
        }else{
            //cout<<listIterator->data<<" ";
            auto res = insert(headOfLargerElementList, tailOfLargerElementList, listIterator->data);
            headOfLargerElementList = res.first;
            tailOfLargerElementList = res.second;
            //cout<<headOfLargerElementList->data<<" "<<tailOfLargerElementList->data<<endl;
        }
        listIterator = listIterator->next;
    }
    if(tailOfSmallerElementList!=NULL && headOfLargerElementList!=NULL){
        tailOfSmallerElementList->next = headOfLargerElementList;
        return headOfSmallerElementList;
    }else{
        if(headOfSmallerElementList == NULL) return headOfLargerElementList;
        else return headOfSmallerElementList;
    }
    
}
 
 int main() {
 	Node* head = NULL;
 	Node* tail = NULL;
 	int n,x;
 	cin>>n>>x;
 	for(int node = 0; node<n; node++){
 	    int nodeValue;
 	    cin>>nodeValue;
 	    if(node == 0){
 	        auto res = insert(head, tail, nodeValue);
 	        head = res.first;
 	        tail = res.second;
 	    }else{
 	       auto res =  insert(head,tail,nodeValue);
 	       tail = res.second;
 	    }
 	}
 	//printLinkedlist(head);
 	Node* headOfMergedList = ListPartition(head,x);
 	printLinkedlist(headOfMergedList);
 	
 	return 0;
 }
