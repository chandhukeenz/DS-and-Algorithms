/*Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.
The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
          Node *iter = head; 
          Node *front = head;
        //create the deep copy of the list by assigning the next position of all original list nodes
        //        1'(copy)
        //      /        \
        // 1 (iter) -> 2(front) -> 3 ...
          while (iter != NULL) {
            front = iter->next;
            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
          }
          iter = head;
        //create the random pointer for the deep copy list
        //move iter by 2 inorder to not enter the deep copy of the list
          while (iter != NULL) {
            if (iter->random != NULL) iter->next->random = iter->random->next;
            iter = iter->next->next;
          }
          iter = head;
          Node *pseudoHead = new Node(0);
          Node *copy = pseudoHead;
        //separate the deep copy list and original list
        //front leads iter by 1 in the original list
        //copy moves in the deep copy list
          while (iter != NULL) {
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy -> next; 
            iter = front;
          }
        return pseudoHead->next;
    }
};
