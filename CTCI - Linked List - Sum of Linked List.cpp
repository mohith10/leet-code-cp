// 1->2->3 1->2 = 2->4->3
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
Node* sumLinkedlist(Node* head1, Node* head2){
    Node* listIterator1 = head1;
    Node* listIterator2 = head2;
    Node* resultantListHead = NULL;
    Node* resultantListTail = NULL;
    int sum = 0, carry = 0; 
    while(listIterator1!=NULL && listIterator2!=NULL){
        sum = listIterator1->data + listIterator2->data + carry;
        carry = sum/10;
        auto res =  insert(resultantListHead,resultantListTail,sum%10);
        resultantListHead = res.first;
 	    resultantListTail = res.second;
 	    listIterator1 = listIterator1->next;
 	    listIterator2 = listIterator2->next;
    }
    while(listIterator1!=NULL){
        sum = listIterator1->data + carry;
        carry = sum/10;
        auto res =  insert(resultantListHead,resultantListTail,sum%10);
        resultantListHead = res.first;
 	    resultantListTail = res.second;
 	    listIterator1 = listIterator1->next;
    }
    while(listIterator2!=NULL){
        sum = listIterator2->data + carry;
        carry = sum/10;
        auto res =  insert(resultantListHead,resultantListTail,sum%10);
        resultantListHead = res.first;
 	    resultantListTail = res.second;
 	    listIterator2 = listIterator2->next;
    }
    if(carry){
        insert(resultantListHead,resultantListTail,carry);
    }
    return resultantListHead;
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
 	Node* headOfSumList = sumLinkedlist(head1, head2);
 	printLinkedlist(headOfSumList);
 	
 	return 0;
 }
