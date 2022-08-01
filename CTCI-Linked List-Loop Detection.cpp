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
pair<bool, int> LoopDetection(Node* head){
    if(head == NULL) return {0, -1};
    Node* slowListIterator = head;
    Node* fastListIterator = head;
    pair<bool, int> result;
    while(fastListIterator!=NULL && fastListIterator->next!=NULL){
        fastListIterator = fastListIterator->next->next;
        slowListIterator = slowListIterator->next;
        if(slowListIterator == fastListIterator){
            result.first = true;
            break;
        }
    }
    if(!result.first){
        result.second = -1;
        return result;
    } 
    slowListIterator = head;
    while(slowListIterator!=fastListIterator){
        slowListIterator = slowListIterator->next;
        fastListIterator = fastListIterator->next;
    }
    result.second = fastListIterator->data;
    return result;
    
    
}
 
 int main() {
 	Node* head1 = NULL;
 	Node* tail1 = NULL;
 	int n;
 	cin>>n;
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
 	tail1->next = head1->next->next->next;
    auto res = LoopDetection(head1);
 	if(res.first){
 	    cout<<"Loop detected "<<res.second;
 	}else{
 	    cout<<"No Loop";
 	}
 	
 	return 0;
 }
