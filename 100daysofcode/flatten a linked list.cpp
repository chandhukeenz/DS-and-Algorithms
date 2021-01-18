/*Flattening a Linked List
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.
Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.

Note: | represents the bottom pointer.

Your Task:
You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter and returns the head of flattened link list.

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)
Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103
*/
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node* mergeTwoLists(Node* a, Node* b) {
    Node *temp = new Node(0);
    Node *res = temp; 
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    return res -> bottom;
}
Node *flatten(Node *root){
        if (root == NULL || root->next == NULL) 
            return root; 
        root->next = flatten(root->next); 
        root = mergeTwoLists(root, root->next); 
        return root; 
}
/*
1.)make a recursive function to call flatten with root->next
2.)this recursive function base case is the last root->next=NULL.and we are calling merge function.
3.)that means, we are sorting and merging from last to first.
4.)merge function compares two consecutive root nodes to sort and merge them.
