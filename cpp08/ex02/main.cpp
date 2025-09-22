#include "mutantstack.hpp"

int		main()
{
    std::cout << std::endl;

    std::cout << "Subject test:" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
    std::cout << std::endl;

	std::stack<int> s(mstack);

	std::cout << "Stack class: " << std::endl;
	while (s.empty() != true)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << std::endl;
	std::cout << "StackMutant class: " << std::endl;
	while (mstack.empty() != true)
	{
		std::cout << mstack.top() << std::endl;
		mstack.pop();
	}
	std::cout << std::endl;

	std::cout << "Copy test:" << std::endl;

	MutantStack<int> myStack;

	myStack.push(0);
	myStack.push(2);
	myStack.push(4);
	myStack.push(8);
	myStack.push(16);
	myStack.push(32);

	it = myStack.begin();
    ite = myStack.end();

	std::cout << "MyStack:\t";

    while(it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
    std::cout << std::endl;

    MutantStack<int> myStackCopy(myStack);

    it = myStackCopy.begin();
    ite = myStackCopy.end();

	std::cout << "MyStackCopy:\t";

    while(it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
    std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Assignation test:" << std::endl;

    MutantStack<int> myStackAssig;
    myStackAssig = myStackCopy;

    it = myStackAssig.begin();
    ite = myStackAssig.end();

	std::cout << "myStackAssig:\t";

    while(it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
    std::cout << std::endl;
    std::cout << std::endl;

	std::cout << "Reverse iterator test:" << std::endl;

	MutantStack<int>::reverse_iterator it_r = myStack.rbegin();
	MutantStack<int>::reverse_iterator ite_r = myStack.rend();

	std::cout << "MyStackReverse:\t";
	while (it_r != ite_r)
	{
		std::cout << *it_r << " ";
		++it_r;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "Const iterator test:" << std::endl;

	MutantStack<int>	mstack_const;

    const int   Const_int1 = 21;
    const int   Const_int2 = 42;

    mstack_const.push(Const_int1);
    mstack_const.push(Const_int2);

    MutantStack<int>::const_iterator it_c = mstack_const.begin();
    MutantStack<int>::const_iterator it_ce = mstack_const.end();

	std::cout << "ConstStack:\t";
	while(it_c != it_ce)
	{
		std::cout << *it_c << " ";
		++it_c;
	}
	std::cout << std::endl;
	std::cout << std::endl;

	return (0);
}
