/*
	Time Complexity: O(n + m) (Due to traversing both the lists)
 	Space Complexity: O(n + m) (Because n + m number of nodes were required in the merged list)
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

// function to merge the lists
Node* mergeList(Node* head1, Node* head2) { // O(n + m) time, O(n + m) space
	LinkedList* ll = new LinkedList();
    Node* node1 = head1;
    Node* node2 = head2;

    // Iterate through both the lists until reaching the end of the shorter list
    while(node1 != nullptr && node2 != nullptr) {
        if(node1->val <= node2->val) {
            ll->insert(node1->val);
            node1 = node1->next;
        }
        else {
            ll->insert(node2->val);
            node2 = node2->next;
        }
    }

    // Iterate through the rest of the elements of the first list (if it is longer)
    while(node1 != nullptr) {
        ll->insert(node1->val);
        node1 = node1->next;
    }

    // Iterate through the rest of the elements of the second list (if it is longer)
    while(node2 != nullptr) {
        ll->insert(node2->val);
        node2 = node2->next;
    }

    // return the head of the merged list
    return ll->begin();
}

// demonstrating how to use the mergeList function
int main() {
    int n, m, e;
    LinkedList ll1, ll2;

	// number of elements of both lists
    cin >> n >> m;

    // insert the elements of the first list
    while(n--) { // o(n) time, O(n) space
        cin >> e;
        ll1.insert(e); // O(1) time
    }

     // insert the elements of the second list
    while(m--) { // o(m) time, O(m) space
        cin >> e;
        ll2.insert(e); // O(1) time
    }

	// passing the head of the lists to the function
    Node* node = mergeList(ll1.begin(), ll2.begin()); // O(n + m) time, O(n + m) space

	// print the reversed list
    while(node) { // O(n + m) time
        cout << node->val << " ";
        node = node->next;
    }

    return 0;
}
