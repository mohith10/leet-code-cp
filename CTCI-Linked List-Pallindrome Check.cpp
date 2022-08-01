#include <bits/stdc++.h>
 using namespace std;
/*
I have used recursive way in this problem. Iterative way is to reach the middle point and reverse the list from there. In another iteration check from middle point and ehad if the value is same
*/
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
pair<bool, Node*> PallindromeCheck(Node* head, Node* tail){
    if(tail==NULL){
        return {true, head};
    }
    auto res = PallindromeCheck(head, tail->next);
    return {res.first & (res.second->data == tail->data), head->next};
}
 
 int main() {
 	Node* head = NULL;
 	Node* tail = NULL;
 	int n;
 	cin>>n;
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
 	auto res = PallindromeCheck(head, head);
 	if(res.first){
 	    cout<<"Linked List is a Pallindrome";
 	}else{
 	    cout<<"Not a Pallindrome";
 	}
 	
 	return 0;
 }
