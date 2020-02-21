// Linked List

#include <iostream>
using namespace std;

class Node {
public:
	typedef Node* NodeP;
	int data;
	Node *next;
	Node() {
		data = 0;
		next= NULL;
	}
	Node(int x) {
		data = x;
		next = NULL;
	}
	void add_tail(NodeP& head, int num) {
		if(head == NULL) {
			head = new Node(num);
		}
		else {
			NodeP temp = head;
			while(temp->next != NULL) {		// this loop will stop at the last node
				temp = temp->next;
			}
		temp->next = new Node(num);		// 
		}
	}
	void add_head(NodeP& head, int num) {
		//make copy of the head
		NodeP temp = head;
		//create new node and assign to head
		head = new Node(num);
		//take care of the address field of new node
		head->next = temp;
	}
	void del(NodeP& head, int target) {
		if(head == NULL) {
			return;	//first case when list is empty
		}
		if(head && head->data == target) {
			NodeP temp = head;
			head = head->next;
			delete temp;
		}
		NodeP prev = NULL;
		NodeP curr = head;
		while(curr != NULL && curr->data != target) {
			prev = curr;
			curr = curr->next;
		}	//after this loop, either you go over the entire list and found nothing or curr = target
		if(curr == NULL) {  // third case, target not found
			return;
		}
		// fourth case, find a non-head node target
		// delete the node deleted at current
		prev->next = curr->next;
		delete curr;
	}
};
