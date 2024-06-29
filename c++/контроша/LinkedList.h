#pragma once
#include <iostream>
template <typename T>
class LinkedList {
	struct Node {
		T val;
		std::shared_ptr<Node> next;
		Node(T val) : val(val), next(nullptr) {};
	};
	std::shared_ptr<Node> head = std::make_shared<Node>(nullptr);
public:
	LinkedList() :head(nullptr) {}
	void show() {
		std::shared_ptr <Node> current = this->head;
		while (current != nullptr) {
			std::cout << current->val << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
	void add(T val) {
		std::shared_ptr<Node> newNode = std::make_shared<Node>(val);
		if (this->head == nullptr) {
			this->head = newNode;
		}
		else {
			std::shared_ptr<Node> cur = this->head;
			while (cur->next != nullptr) {
				cur = cur->next;
			}
			cur->next = newNode;
		}
	}
	void remove(T val) {
		std::shared_ptr<Node> cur = this->head;
		std::shared_ptr<Node> curtmp = nullptr;
		while (cur->val != val && cur != nullptr) {
			curtmp = cur;
			cur = cur->next;
			if (cur->val == val) {
				curtmp->next = cur->next;
			}
		}
		if (cur == nullptr) { return; }
		else if (cur->val == val) { this->head = this->head->next; }
		else { curtmp->next = cur->next; }
		show();
	}
};