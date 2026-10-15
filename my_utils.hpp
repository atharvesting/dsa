#pragma once
#include <vector>
#include <iostream>
#include <typeinfo>


struct ListNodeInt {
	int val;
	ListNodeInt* next;
	ListNodeInt(int val) : val(val), next(nullptr) {}
};

inline ListNodeInt* vector_to_LL(std::vector<int>& nums) {
	if (nums.empty()) return nullptr;
	ListNodeInt* START = nullptr, *q = nullptr;
	START = new ListNodeInt(nums[0]);
	q = START;
	for (int i = 1; i < nums.size(); i++) {
		q->next = new ListNodeInt(nums[i]);
		q = q->next;
	}

	return START;
}

template <typename T>
struct ListNode {
	T val;
	ListNode* next;
	ListNode(T val) : val(val), next(nullptr) {}
};

template <typename Container>
auto container_to_LL(Container& collection) {

	using DataType = typename Container::value_type;
	if (collection.empty()) return (ListNode<DataType>*)nullptr;

	auto it = collection.begin();

	ListNode<DataType>* head = new ListNode<DataType>(*it);
	ListNode<DataType>* current = head;

	for (++it; it != collection.end(); it++) {
		current->next = new ListNode<DataType>(*it);
		current = current->next;
	}

	return head;
}

template <typename Container>
void traverse_container(Container& collection) {
	using DataType = typename Container::value_type;

	if (collection.empty()) return;

	for (auto it = collection.begin(); it != collection.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void traverse_subvector(typename std::vector<T>::iterator start, typename std::vector<T>::iterator end) {
    for (auto i = start; i != end; i++) {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}

template <typename T>
void traverse_LL(ListNode<T>* head) {
	ListNode<T>* current = head;
	while (current != nullptr) {
		std::cout << current->val << " ";
		current = current->next;
	}
	std::cout << std::endl;
}


inline void traverse_LL_Int(ListNodeInt*& START) {
	if (START == nullptr) {
		std::cout << "Linked List Empty!" << std::endl;
		return;
	}
	ListNodeInt* q = START;
	while (q != NULL) {
		std::cout << q->val << " ";
		q = q->next;
	}
	std::cout << std::endl;
}

template <typename T>
void delete_LL(ListNode<T>*& START) {
	if (START == nullptr) return;
	while (START != nullptr) {
		ListNode<T>* q = START;
		START = START->next;
		delete q;
	}
}

