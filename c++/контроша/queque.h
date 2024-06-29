#pragma once
#include <iostream>
#include <memory>

template<typename T>
class Queue {
	int len = 0;
	std::unique_ptr<T[]> queue;
public:
	Queue() : queue(nullptr) {}

	void add(T val) {
		this->len++;
		std::unique_ptr<T[]> tmp(new T[this->len]);
		for (int i = 0; i < this->len - 1; i++) {
			tmp[i] = queue[i];
		}
		tmp[this->len - 1] = val;
		queue = std::move(tmp);
	}

	void show() {
		for (int i = 0; i < this->len; i++) {
			std::cout << queue[i] << " ";
		}
		std::cout << std::endl;
	}

	void pop() {
		if (this->len > 0) {
			this->len--;
			std::unique_ptr<T[]> tmp(new T[this->len]);
			for (int i = 1; i < this->len + 1; i++) {
				tmp[i - 1] = this->queue[i];
			}
			queue = std::move(tmp);
			show();
		}
		else {
			std::cout << "Queue is empty." << std::endl;
		}
	}
};