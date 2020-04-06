#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>

template<class T>
class MutantStack
{
	public:
	class El
	{
	public:
		T	_el;
		El	*_next;
//		El	*_prev;
	};

	class Iterator
	{
		public:
		El		*_el;
		//El<T>		*_prev_el;


		// overloads:

		T& operator * ()
		{
			return (_el->_el);
		};
		Iterator& operator ++ ()
		{
			_el = _el->_next;
			return (*this);
		};

		Iterator& operator ++ (int)
		{
			_el = _el->_next;
			return (*this);
		};

		bool operator == (const Iterator& iter)
		{
			if (_el == iter._el)
				return true;
			return false;
		};
		bool operator != (const Iterator& iter)
		{
			if (_el != iter._el)
				return true;
			return false;
		};
		void operator = (El* el)
		{
			_el = el;
		};


	};


	public:
	MutantStack()
	{
		_stack = nullptr;
		_size = 0;
	//	_container_type = "MutantStack";
		_size_type = "Unsigned int";
	};
	~MutantStack()
	{
		El *next;
		while (_stack)
		{
			next = _stack->_next;
			delete (_stack);
			_stack = next;
		}
	};
	MutantStack(const MutantStack& stack);
	void operator = (const MutantStack& stack);

	void operator = (const T& t);

	T& 				top()
	{
			return (_stack->_el);
	};
	bool			empty()
	{
		if (_size == 0)
			return (true);
		else
			return (false);
	};
	unsigned int	size()
	{
			return (_size);
	};

	void		push(const T& el)
	{
		El	*bstack;

		if (!_stack)
		{
			_stack = new El;
			_stack->_el = el;
			_stack->_next = nullptr;
		}
		else
		{
			bstack = new El;
			bstack->_next = _stack;
			bstack->_el = el;
			_stack = bstack;
		}
		_size += 1;
	};
	void		pop()
	{
		El	*bstack;

		if (!_stack)
			return ;
		bstack = _stack;
		_stack = _stack->_next;
		delete (bstack);
		_size -= 1;
	};
	void		swap(const T& b) {};

	void		print()
	{
		El *bstack = _stack;

		while (bstack)
		{
			std::cout << bstack->_el << std::endl;
			bstack = bstack->_next;
		}
	};

	El* begin()
	{
		return (_stack);
	};

	El* end()
	{
		El* bstack = _stack;
		for (int i = 0; i < _size; i++)
			bstack = bstack->_next;
		return (bstack);
	};

	private:
	El     *_stack;

	unsigned int	_size;

//	std::string _container_type;
	std::string _value_type;
	std::string _size_type;


};

#endif
