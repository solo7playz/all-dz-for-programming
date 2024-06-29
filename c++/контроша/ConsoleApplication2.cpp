#include "LinkedList.h"
#include "Stack.h"
#include "queque.h"

int main(){
	//linked list
	std::shared_ptr<LinkedList <int>> ll = std::make_shared<LinkedList<int>>();
	ll->add(1);
	ll->add(0);
	ll->add(1);
	ll->show();
	ll->remove(1);
	//stack
	std::shared_ptr<Stack<int>> st = std::make_shared<Stack<int>>();
	st->add(5);
	st->add(7);
	st->add(4);
	st->show();
	st->pop();
	//queque
	std::unique_ptr<Queue<int>> qu = std::make_unique<Queue<int>>();
	qu->add(145);
	qu->add(242);
	qu->add(17);
	qu->add(888);
	qu->show();
	qu->pop();
}