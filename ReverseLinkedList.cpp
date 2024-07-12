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
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's pointer
        prev = current;        // Move pointers one position ahead
        current = next;
    }

    return prev;  // New head is the previous node
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
    // Create the head node
    ListNode *head = new ListNode(1);
    ListNode *current = head;

    // Create the rest of the nodes
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
