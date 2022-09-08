#include "MutantStack.hpp"
#include <list>
#include <iostream>

int main(void) {
	MutantStack<int>	mstack;
	std::list<int>		lst;

	std::cout << "STACK REGULAR OPERATIONS" << std::endl;
	std::cout << "Mutant Stack" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "First out: " << mstack.top() << " (should be 17)" << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << " (should be 1)" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	std::cout << std::endl << "vs List" << std::endl;
	lst.push_front(5);
	lst.push_front(17);
	std::cout << "First out: " << lst.front() << " (should be 17)" << std::endl;
	lst.pop_front();
	std::cout << "Size: " << lst.size() << " (should be 1)" << std::endl;
	lst.push_front(3);
	lst.push_front(5);
	lst.push_front(737);
	lst.push_front(0);

	std::cout << std::endl << "ITERATORS - BEGIN, IN/DECREMENT AND DEREFERENCE" << std::endl;
	std::cout << "Mutant Stack" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	++it;
	std::cout << *it << " ";
	it++;
	std::cout << *it << " ";
	--it;
	std::cout << *it << " ";
	it--;
	std::cout << *it << std::endl;
	std::cout << std::endl << "vs List" << std::endl;
	std::list<int>::iterator lit = lst.begin();
	++lit;
	std::cout << *lit << " ";
	lit++;
	std::cout << *lit << " ";
	--lit;
	std::cout << *lit << " ";
	lit--;
	std::cout << *lit << std::endl;

	std::cout << std::endl << "ITERATORS - COPYING AND COMPARING" << std::endl;
	MutantStack<int>::iterator it2(it);
	MutantStack<int>::iterator it3;

	it3 = it;
	if (it == it2 && it == it3)
		std::cout << "All good!" << std::endl;
	else
		std::cout <<"Something went wrong..." << std::endl;
	
	std::cout << std::endl << "ITERATORS - END AND LOOPS" << std::endl;
	std::cout << "Mutant Stack" << std::endl;
	/*MutantStack<int>::iterator ite = mstack.end();
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;*/
	std::cout << std::endl << "vs List" << std::endl;
	std::list<int>::iterator lite = lst.end();
	while (lit != lite) {
		std::cout << *lit << " ";
		++lit;
	}
	std::cout << std::endl;

	std::cout << std::endl << "CREATING A STACK FROM A MUTANT STACK" << std::endl;
	std::stack<int> s(mstack);
	std::cout << "If I'm being printed, everything went fine" << std::endl << std::endl;
	return 0;
}