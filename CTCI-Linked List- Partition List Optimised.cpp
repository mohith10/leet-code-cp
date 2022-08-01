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
    Node* headOfResultantElementList = NULL;
    Node* tailOfResultantElementList = NULL;
    
    
    Node* listIterator = head;
    while(listIterator!=NULL){
        Node* newNode = new Node();
        newNode->data = listIterator->data;
        newNode->next = NULL;
        if(headOfResultantElementList == NULL){
            headOfResultantElementList = newNode;
            tailOfResultantElementList = newNode;
            listIterator = listIterator->next;
            continue;
        }
        if(listIterator->data < x){
           newNode->next = headOfResultantElementList;
           headOfResultantElementList = newNode;
        }else{
           tailOfResultantElementList->next = newNode;
           tailOfResultantElementList = newNode;
        }
        listIterator = listIterator->next;
    }
    
    return headOfResultantElementList;
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
