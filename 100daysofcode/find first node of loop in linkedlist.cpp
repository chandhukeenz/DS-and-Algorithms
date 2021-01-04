/*Find first node of loop in a linked list
Write a function findFirstLoopNode() that checks whether a given Linked List contains a loop. 
If the loop is present then it returns point to the first node of the loop. Else it returns NULL.
input: 1->2->3->4
          |      |
    	  7<- 6<-5
output: 2
*/
#include<iostream>
using namespace std;
struct Node {
    int key;
    struct Node* next;
};
 
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->next = NULL;
    return temp;
}
Node* firstnode(Node* head){
    Node *slow=head,*fast=head;
    while((fast&&fast->next&&fast->next->next)){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;   
    }
    if(slow!=fast) return NULL;
    fast=head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

int main(){
    Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
 
    Node* res = firstnode(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->key;
 
    return 0;
}
