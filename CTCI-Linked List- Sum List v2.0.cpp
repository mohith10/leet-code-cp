/*
Left the part that two list should be of same size, else pad 0 to end of shorter list. 9->9 + 9->9 = 1->9->8
*/
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
pair<Node*, int> sumLinkedlistRecursive(Node* head1, Node* head2){
    if(head1 == NULL && head2 == NULL){
        return {NULL,0};
    }
    auto res = sumLinkedlistRecursive(head1->next, head2->next);
    Node* newNode = new Node();
    int carry = res.second;
    int sum = head1->data + head2->data + carry;
    newNode->data = sum%10;
    carry = sum/10;
    newNode->next = res.first;
    return {newNode,carry};
}
 
 int main() {
 	Node* head1 = NULL;
 	Node* tail1 = NULL;
 	Node* head2 = NULL;
 	Node* tail2 = NULL;
 	int n,m;
 	cin>>n>>m;
 	for(int node = 0; node<n; node++){
 	    int nodeValue;
 	    cin>>nodeValue;
 	    if(node == 0){
 	        auto res = insert(head1, tail1, nodeValue);
 	        head1 = res.first;
 	        tail1 = res.second;
 	    }else{
 	       auto res =  insert(head1,tail1,nodeValue);
 	       tail1 = res.second;
 	    }
 	}
 	 for(int node = 0; node<m; node++){
 	    int nodeValue;
 	    cin>>nodeValue;
 	    if(node == 0){
 	        auto res = insert(head2, tail2, nodeValue);
 	        head2 = res.first;
 	        tail2 = res.second;
 	    }else{
 	       auto res =  insert(head2,tail2,nodeValue);
 	       tail2 = res.second;
 	    }
 	}
 	//printLinkedlist(head);
 	auto res = sumLinkedlistRecursive(head1, head2);
 	if(res.second){
 	    Node* newNode = new Node();
 	    newNode->data = 1;
 	    newNode->next = res.first;
 	    res.first = newNode;
 	}
 	printLinkedlist(res.first);
 	
 	return 0;
 }
