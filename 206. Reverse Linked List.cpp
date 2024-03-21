// QUESTION
// Given the head of a singly linked list, reverse the list, and return the reversed list.

 

// Example 1:


// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Example 2:


// Input: head = [1,2]
// Output: [2,1]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is the range [0, 5000].
// -5000 <= Node.val <= 5000
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution
{
    public:
    
    struct Node* mergeTwoLists(Node *list1,Node *list2) {
        if(list1 == NULL) {
            return list2;
        }

        if(list2 == NULL) {
            return list1;
        }

        struct Node* result;
        if(list1->data < list2->data) {
            result = list1;
            result->next = mergeTwoLists(list1->next, list2);
        } else {
            result = list2;
            result->next = mergeTwoLists(list1, list2->next);
        }

        return result;
    }
    
    struct Node* reverseList(struct Node* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        struct Node* last = reverseList(head->next); //last = future head

        head->next->next = head;
        head->next = NULL;

        return last;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2) {
        struct Node* result = mergeTwoLists(node1, node2);
        
        
        result = reverseList(result);
        
        return result;
        
    }  
};
