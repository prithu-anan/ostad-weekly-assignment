/*
	Time Complexity: O(n) (Due to traversing the entire list)
 	Space Complexity: O(1) (Because no additional space was required to perform the reversal)
*/

#include <bits/stdc++.h>
using namespace std;

// node of the list
struct Node {
    int val;
    Node* next;
    Node(int v = 0, Node* n = nullptr) {
        val = v;
        next = n;
    }
};

// data structure of the list
class LinkedList {
    Node* head, *curr;
    public:
    LinkedList() { 
        head = nullptr;
        curr = nullptr;
     }

    ~LinkedList() { // O(n) time
        while(head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int v) { // O(1) time
        if(!head){
            head = new Node(v);
            curr = head;
        }
        else {
            Node* temp = new Node(v);
            curr->next = temp;
            curr = temp;
        }
    }

    Node* begin() { return head; } // O(1) time
};

// function to reverse the list
Node* revList(Node* head) {
	Node* curr = head;
	Node* prev = nullptr;
	Node* next;

	while(curr) { // O(n) time
		next = curr->next; // temporarily store the next node
		curr->next = prev; // point the next pointer to the previous node (reverse)
		prev = curr; // move the previous pointer forward
		curr = next; // move the current pointer forward
	}

	return prev;
}

// demonstrating how to use the revList function
int main() {
    int n, m;
    LinkedList ll;

	// number of elements
    cin >> n;

	// insert the elements
    while(n--) { // o(n) time, O(n) space
        cin >> m;
        ll.insert(m); // O(1) time
    }

	// passing the head of the list to the function
    Node* node = revList(ll.begin()); // O(n) time, O(1) space

	// print the reversed list
    while(node) { // O(n) time
        cout << node->val << " ";
        node = node->next;
    }

    return 0;
}
