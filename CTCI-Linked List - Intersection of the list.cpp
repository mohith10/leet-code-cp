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
pair<bool, int> ListIntersection(Node* head1,Node* head2){
    Node* listIterator1 = head1;
    Node* listIterator2 = head2;
    pair<bool, int> res;
    int lenList1 = 0, lenList2 = 0;
    while(listIterator1->next!=NULL){
        lenList1++;
        listIterator1 = listIterator1->next;
    }
    while(listIterator2->next!=NULL){
        lenList2++;
        listIterator2 = listIterator2->next;
    }
    
    if(listIterator1 != listIterator2) {
        return {false, -1};
    }
    
    listIterator1 = head1;
    listIterator2 = head2;
    if(lenList1 > lenList2){
        for(int steps = 0; steps < lenList1 - lenList2; steps++){
            listIterator1 = listIterator1->next;
        }
    }else{
        for(int steps = 0; steps < lenList2 - lenList1; steps++){
            listIterator2 = listIterator2->next;
        }
    }
    while(listIterator1!=listIterator2){
        listIterator1 = listIterator1->next;
        listIterator2 = listIterator2->next;
    }
    return {true, listIterator1->data};
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
 	
    auto res = ListIntersection(head1, head2);
 	if(res.first){
 	    cout<<"It interesects at "<<res.second;
 	}else{
 	    cout<<"Lists doesnt intersect";
 	}
 	
 	return 0;
 }
