#include "linked_list.hpp"
#include <iostream>

linked_list::linked_list(const linked_list& other) { // copy constructor
	head = nullptr;
	length = 0;
    node* current = other.head;
    while (current != nullptr) {
        push_back(current->val);
        current = current->next;
    }
	
}

void linked_list::operator=(const linked_list& other) { // assignment operator overload
	if (this != &other) {
        clear();
        node* current = other.head;
        while (current != nullptr) {
            push_back(current->val);
            current = current->next;
        }
    }
}

linked_list::~linked_list() { // destructor
	clear();
}

int linked_list::get_length() {
	return length;
}

void linked_list::print() {
	node* current = head;
    while (current != nullptr) { // iterate through list
        std::cout << current->val << " "; // print element
        current = current->next; // move to next element
    }
    std::cout << std::endl;
}

void linked_list::clear() {
	while (head != nullptr) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

void linked_list::push_front(int value) {
	node* new_node = new node; // create new node
    // insert new node at beginning
	new_node->val = value; 
	new_node->next = head;
	head = new_node;
	length++;
}

void linked_list::push_back(int value) {
	node* new_node = new node; // create new node
    new_node->val = value;
    new_node->next = nullptr; 

    if (head == nullptr) {
        head = new_node;
    } else {
        // insert new node at end
        node* current = head;
        while (current->next != nullptr) { // iterate until at end of list
            current = current->next;
        }
        current->next = new_node;
    }
    length++;
}

void linked_list::insert(int value, int index) {
	if (index <= length){
    node* new_node = new node; // create new node
    new_node->val = value;

    if (index == 0) {
        new_node->next = head;
        head = new_node;
    } else{
        // insert node at specified index
        node* current = head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
    length++;
	}
}

void linked_list::pop_front() {
	if (head != nullptr) {
        // delete front element
        node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }
}

void linked_list::pop_back() {
	if (head == nullptr) {
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        // delete last element
        node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    length--;
}

void linked_list::remove(int index) {
	if (index == 0) {
        pop_front();
    } else if (index < length){
        // remove element at index
        node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        node* temp = current->next;
        current->next = temp->next;
        delete temp;
        length--;
    }
}

void linked_list::sort_ascending() { // recursive merge sort
	if (head == nullptr || head->next == nullptr) { // recursive base case
        return;
    }
    // Implement merge sort
    head = merge_sort(head);
}

node* linked_list::merge_sort(node* head) { // Helper function to perform merge sort on linked list
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    node* middle = get_middle(head);
    node* second_half = middle->next;
    middle->next = nullptr;

    return merge(merge_sort(head), merge_sort(second_half));
}

node* linked_list::get_middle(node* head) { // Helper function to get the middle node of the linked list
    if (head == nullptr) {
        return head;
    }
    node* slow = head;
    node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* linked_list::merge(node* left, node* right) { // Helper function to merge two sorted linked lists
    if (left == nullptr) {
        return right;
    }
    if (right == nullptr) {
        return left;
    }
    if (left->val < right->val) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

void linked_list::sort_descending() { // recursive selection sort
    if (head == nullptr || head->next == nullptr) { // recursive base case
        return;
    }
    node* max_node = head;
    node* max_prev = nullptr;
    node* current = head;

    // Iterate through the list to find the node with the maximum value.
    while (current->next != nullptr) {
        if (current->next->val > max_node->val) {
            max_prev = current;
            max_node = current->next;
        }
        current = current->next;
    }
    // Remove max_node from its current position.
    if (max_prev != nullptr) {
        max_prev->next = max_node->next;
    } else {
        head = max_node->next;
    }

    max_node->next = nullptr;

    //sort the remaining list
    sort_descending();

    //insert max node at front
    max_node->next = head;
    head = max_node;
}
