#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;

    ListNode() {
        val = 0;
        next = NULL;
    }

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* current = head;
    ListNode* next = NULL;

    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;        // Move pointers 
        current = next;
    }

    return prev; 
}

void PrintLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    
    ListNode *head = new ListNode(1);
    ListNode *current = head;

   
    for (int i = 2; i <= 10; ++i) {
        current->next = new ListNode(i);
        current = current->next;
    }

    cout << "Original list: ";
    PrintLinkedList(head);

    // Reverse the linked list
    ListNode *reversedHead = reverseList(head);

    cout << "Reversed list: ";
    PrintLinkedList(reversedHead);

    return 0;
}
