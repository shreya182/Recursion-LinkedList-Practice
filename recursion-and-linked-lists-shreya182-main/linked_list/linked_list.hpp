#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "node.hpp"

class linked_list {
private:
	int length = 0;			// the number of nodes contained in the list.
	node* head = nullptr;	// a pointer to the first node in the list.
public:
	// Empty default constructor
	linked_list() = default;

	// Copy constructor
	linked_list(const linked_list& other);

	// Assignment operator overload
	void operator=(const linked_list& other);

	// Destructor
	~linked_list();

	/*********************************************************************
	 ** Function: get_length()
	 ** Description: Returns length of list.
	 ** Returns (int): Length of list (# of nodes).
	 ********************************************************************/
	int get_length();

	/*********************************************************************
	 ** Function: print()
	 ** Description: Prints all values in the list.
	 ********************************************************************/
	void print();

	/*********************************************************************
	 ** Function: clear()
	 ** Description: Removes all nodes from list (and deletes them from the
	 ** 	heap).
	 ** Post-Conditions: length = 0, head = nullptr.
	 ********************************************************************/
	void clear();

	/*********************************************************************
	 ** Function: push_front()
	 ** Description: Inserts a new value at the front (beginning) of the list
	 		in a new node.
	 ** Parameters: int - value being added to list.
	 ********************************************************************/
	void push_front(int value);

	/*********************************************************************
	 ** Function: push_back()
	 ** Description: Insert a new value at the back (end) of the list in a
	 		new node.
	 ** Parameters: int - value being added to list.
	 ********************************************************************/
	void push_back(int value);

	/*********************************************************************
	 ** Function: insert()
	 ** Description: insert a new value at a specified index.
	 ** Parameters: int value - value being added to list.
	                int index - index of where element is being added.
	 ** Post-Conditions: given value inserted at given index in a new node, and
	 		all subsequent elements shifted over to make room for it. Length
			should be one greater than before.
	 ********************************************************************/
	void insert(int value, int index);

	/*********************************************************************
	 ** Function: pop_front()
	 ** Description: Remove node at the front (beginning) of the list.
	 ** Post-Conditions: Node at the front of the list is removed from the
	 		list and deleted from the heap
	 ********************************************************************/
	void pop_front();

	/*********************************************************************
	 ** Function: pop_back()
	 ** Description: Remove node at the back (end) of the list.
	 ** Post-Conditions: Node at the back of the list is removed from the
	 		list and deleted from the heap
	 ********************************************************************/
	void pop_back();

	/*********************************************************************
	 ** Function: remove()
	 ** Description: Remove node at the given index.
	 ** Parameters: int - index of where node is being removed.
	 ** Post-Conditions: Node at given index is removed. Subsequent nodes
	 		are shifted over to accommodate. Length of list should be one
			less than before.
	 ********************************************************************/
	void remove(int index);

	/*********************************************************************
	 ** Function: sort_ascending()
	 ** Description: Sorts list in ascending order.
	 ** Post-Conditions: List's nodes are rearranged to be sorted in
	 		ascending order of their respective values.
	 ********************************************************************/
	void sort_ascending();

	/*********************************************************************
	 ** Function: sort_descending()
	 ** Description: Sorts list in descending order.
	 ** Post-Conditions: List's nodes are rearranged to be sorted in
	 		descending order of their respective values.
	 ********************************************************************/
	void sort_descending();
	/*********************************************************************
	 ** Function: merge_sort()
	 ** Description: Helper function to perform merge sort on linked list
	 ********************************************************************/
	node* merge_sort(node* head);
	/*********************************************************************
	 ** Function: get_middle()
	 ** Description: Helper function to get the middle node of the linked list
	 ********************************************************************/
	node* get_middle(node* head);
	/*********************************************************************
	 ** Function: merge()
	 ** Description: Helper function to merge two sorted linked lists
	 ********************************************************************/
	node* merge(node* left, node* right);
};

#endif
