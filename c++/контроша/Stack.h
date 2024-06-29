#pragma once
#include <iostream>

#include <iostream>
#include <memory>

template<typename T>
class Stack {
	int len = 0;
	std::shared_ptr<T[]> stack;
public:
	Stack() : stack(nullptr) {}

	void add(T val) {
		this->len++;
		std::shared_ptr<T[]> tmp = std::make_shared<T[]>(this->len);
		tmp[0] = val;
		for (int i = 1; i < this->len; i++) {
			tmp[i] = this->stack[i - 1];
		}
		stack = tmp;
	}

	void show() {
		for (int i = 0; i < this->len; i++) {
			std::cout << this->stack[i] << " ";
		}
		std::cout << std::endl;
	}

	void pop() {
		if (this->len > 0) {
			this->len--;
			std::shared_ptr<T[]> tmp = std::make_shared<T[]>(this->len);
			for (int i = 0; i < this->len; i++) {
				tmp[i] = this->stack[i];
			}
			stack.swap(tmp);
			show();
		}
		else {
			std::cout << "Stack is empty." << std::endl;
		}
	}
};