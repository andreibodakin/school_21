#ifndef LIST_HPP
#define LIST_HPP

#include "iterators.hpp"
#include "utils.hpp"

// https://www.cplusplus.com/reference/list/list/

namespace ft
{
	template <typename T, class Alloc = std::allocator<T> >
	class list
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef bidirectional_iterator<T> iterator;
		typedef const_bidirectional_iterator<T> const_iterator;
		typedef reverse_iterator<T> reverse_iterator;
		typedef const_reverse_iterator<T> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;

	private:
		node<value_type> *front_;
		node<value_type> *back_;
		node<value_type> *end_;
		size_type size_;
		allocator_type alloc_;
		std::allocator<node<T> > nodeAlloc_;

	public:
		list() : size_(0)
		{
			end_ = nodeAlloc_.allocate(1);
			nodeAlloc_.construct(end_);
			end_->data = new T();
			end_->previous = end_;
			end_->next = end_;
			front_ = end_;
			back_ = end_;
		}

		explicit list(const Alloc &alloc) : size_(0)
		{
			end_ = nodeAlloc_.allocate(1);
			nodeAlloc_.construct(end_);
			end_->data = new T();
			end_->previous = end_;
			end_->next = end_;
			front_ = end_;
			back_ = end_;
			alloc_ = alloc;
		}

		explicit list(size_type count, const T &value = T(), const Alloc &alloc = Alloc())
		{
			end_ = nodeAlloc_.allocate(1);
			nodeAlloc_.construct(end_);
			end_->data = new T();
			end_->previous = end_;
			end_->next = end_;
			front_ = end_;
			back_ = end_;
			size_ = 0;
			alloc_ = alloc;
			while (count--)
				push_back(value);
		}

		template <class InputIterator>
		list(InputIterator first, typename enable_if<std::is_class<InputIterator>::value, InputIterator>::type last, const Alloc &alloc = Alloc())
		{
			end_ = nodeAlloc_.allocate(1);
			nodeAlloc_.construct(end_);
			end_->data = new T();
			end_->previous = end_;
			end_->next = end_;
			front_ = end_;
			back_ = end_;
			size_ = 0;
			alloc_ = alloc;
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		list(const list &other) : size_(0)
		{
			end_ = nodeAlloc_.allocate(1);
			nodeAlloc_.construct(end_);
			end_->data = new T();
			end_->previous = end_;
			end_->next = end_;
			front_ = end_;
			back_ = end_;
			*this = other;
		}

		virtual ~list()
		{
			clear();
			delete (end_->data);
			nodeAlloc_.destroy(end_);
			nodeAlloc_.deallocate(end_, 1);
		}

		list &operator=(const list &other)
		{
			// if (&other == this)
			// 	return (*this);
			// clear();
			// if (other.empty())
			// 	return (*this);
			// insert(this->begin(), other.begin(), other.end());
			// return (*this);

			this->assign(other.begin(), other.end());
			return (*this);
		}

		iterator begin()
		{
			return (iterator(front_));
		}

		const_iterator begin() const
		{
			return (const_iterator(front_));
		}

		iterator end()
		{
			return (iterator(end_));
		}

		const_iterator end() const
		{
			return (const_iterator(end_));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(back_));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_iterator(back_));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(end_));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(end_));
		}

		bool empty() const
		{
			return (size_ == 0);
		}

		size_type size() const
		{
			return (size_);
		}

		// max_size
		size_type max_size() const
		{
			return (nodeAlloc_.max_size());
		}

		reference front()
		{
			return (*front_->data);
		}

		const_reference front() const
		{
			return (*front_->data);
		}

		reference back()
		{
			return (*back_->data);
		}

		const_reference back() const
		{
			return (*back_->data);
		}

		template <class InputIterator>
		void assign(InputIterator first, typename enable_if<std::is_class<InputIterator>::value, InputIterator>::type last)
		{
			clear();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void assign(size_type n, const value_type &val)
		{
			clear();
			while (n--)
				push_back(val);
		}

		void push_front(const value_type &val)
		{
			insert(begin(), val);
		}

		void pop_front()
		{
			node<T> *tmp;

			if (front_ == end_)
				return;
			tmp = front_->next;
			alloc_.destroy(front_->data);
			alloc_.deallocate(front_->data, 1);
			nodeAlloc_.destroy(front_);
			nodeAlloc_.deallocate(front_, 1);
			if (tmp == end_)
			{
				back_ = end_;
				front_ = end_;
			}
			else
			{
				front_ = tmp;
				front_->previous = end_;
			}
			size_--;
		}

		// push_back
		void push_back(const value_type &val)
		{
			iterator it = begin();
			size_type size = size_;

			while (size--)
				it++;
			insert(it, val);
		}

		void pop_back()
		{
			node<T> *tmp;

			if (back_ == end_)
				return;
			tmp = back_->previous;
			alloc_.destroy(back_->data);
			alloc_.deallocate(back_->data, 1);
			nodeAlloc_.destroy(back_);
			nodeAlloc_.deallocate(back_, 1);
			if (tmp == end_)
			{
				back_ = end_;
				front_ = end_;
			}
			else
			{
				back_ = tmp;
				back_->next = end_;
				end_->previous = back_;
			}
			size_--;
		}

		iterator insert(iterator position, const value_type &val)
		{
			node<T> *tmp = nodeAlloc_.allocate(1);

			nodeAlloc_.construct(tmp);
			tmp->data = alloc_.allocate(1);
			alloc_.construct(tmp->data, val);
			tmp->next = position.getNode();
			tmp->previous = position.getNode()->previous;
			tmp->previous->next = tmp;
			tmp->next->previous = tmp;
			if (tmp->previous == end_)
				front_ = tmp;
			if (tmp->next == end_)
				back_ = tmp;
			size_++;
			return (iterator(tmp));
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			while (n--)
				insert(position, val);
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, typename enable_if<std::is_class<InputIterator>::value, InputIterator>::type last)
		{
			for (InputIterator it = first; it != last; it++)
				insert(position, *it);
		}

		iterator erase(iterator position)
		{
			node<T> *it = position.getNode();
			node<T> *next = it->next;
			node<T> *previous = it->previous;

			if (it == end_)
				return (iterator(end_));
			next->previous = previous;
			previous->next = next;
			alloc_.destroy(it->data);
			alloc_.deallocate(it->data, 1);
			nodeAlloc_.destroy(it);
			nodeAlloc_.deallocate(it, 1);
			if (previous == end_)
				front_ = next;
			if (next == end_)
				back_ = previous;
			size_--;
			return (iterator(next));
		}

		iterator erase(iterator first, iterator last)
		{
			if (first == last)
				return (last);
			while (first != last)
				first = erase(first);
			erase(first);
			if (last.getNode() == end_)
				return (iterator(end_));
			last++;
			return (iterator(last.getNode()));
		}

		void swap(list &x)
		{
			if (this != &x)
			{
				my_swap(this->front_, x.front_);
				my_swap(this->back_, x.back_);
				my_swap(this->end_, x.end_);
				my_swap(this->size_, x.size_);
				my_swap(this->alloc_, x.alloc_);
				my_swap(this->nodeAlloc_, x.nodeAlloc_);
			}
		}

		void resize(size_type n, value_type val = value_type())
		{
			while (size_ > n)
			{
				pop_back();
			}
			while (size_ < n)
			{
				push_back(val);
			}
		}

		void clear()
		{
			while (front_ != end_)
			{
				erase(begin());
			}
		}

		void splice(iterator position, list &x)
		{
			splice(position, x, x.begin(), x.end());
		}

		void splice(iterator position, list &x, iterator i)
		{
			iterator next(i);
			splice(position, x, i, ++next);
		}

		void splice(iterator position, list &x, iterator first, iterator last)
		{
			if (first.getNode() == x.end_)
				return;

			node<T> *first_x = first.getNode();
			node<T> *last_x = last.getNode();
			node<T> *pos = position.getNode();

			difference_type diff = difference(first, last);
			x.size_ -= diff;
			size_ += diff;

			if (last.getNode() == x.end_)
				last--;

			first_x->previous->next = first_x->next;
			first_x->next->previous = first_x->previous;

			x.front_ = x.end_->next;
			x.back_ = x.end_->previous;
			pos->previous->next = first_x;
			first_x->previous = pos->previous;
			pos->previous = last_x;
			last_x->next = pos;

			front_ = end_->next;
			back_ = end_->previous;
		}

		void remove(const value_type &val)
		{
			iterator it = begin();
			while (it != end())
			{
				if (*it == val)
					it = erase(it);
				else
					++it;
			}
		}

		template <class Predicate>
		void remove_if(Predicate pred)
		{
			iterator it = begin();
			while (it != end())
			{
				if (pred(*it) == true)
					it = erase(it);
				else
					++it;
			}
		}

		// unique
		void unique()
		{
			iterator check = this->begin();
			iterator end = this->end();
			T *tmp = my_nullptr;

			while (check != end)
			{
				if (tmp && *tmp == *check)
					check = erase(check);
				else
				{
					tmp = &(*check);
					check++;
				}
			}
		}

		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred)
		{
			iterator begin = this->begin();
			iterator current = this->begin();
			iterator end = this->end();

			while (++current != end)
			{
				if (binary_pred(*begin, *current) == true)
				{
					erase(current);
					current = begin;
				}
				else
					begin++;
			}
		}

		// merge
		void merge(list &x)
		{
			iterator begin = this->begin();
			iterator end = this->end();
			iterator beginX = x.begin();
			iterator next;

			while (x.size_)
			{
				if (*beginX < *begin || begin == end)
				{
					next = beginX;
					next++;
					splice(begin, x, beginX);
					beginX = next;
				}
				else
					begin++;
			}
		}

		template <class Compare>
		void merge(list &x, Compare comp)
		{
			if (&x == this)
				return;
			iterator it = begin();
			iterator xit = x.begin();
			while (it != end() && xit != x.end())
			{
				while (it != end() && !comp(*xit, *it))
					++it;
				++xit;
				this->splice(it, x, xit);
			}
			if (xit != x.end())
				this->splice(it, x, xit, x.end());
		}

		void sort()
		{
			iterator begin = this->begin();
			iterator it = this->begin();
			iterator end = this->end();

			while (++it != end)
			{
				if (*it < *begin)
				{
					my_swap(begin.getNode()->data, it.getNode()->data);
					begin = this->begin();
					it = this->begin();
				}
				else
					++begin;
			}
		}

		template <class Compare>
		void sort(Compare comp)
		{
			iterator begin = this->begin();
			iterator it = this->begin();
			iterator end = this->end();

			while (++it != end)
			{
				if (comp(*it, *begin))
				{
					my_swap(begin.getNode()->data, it.getNode()->data);
					begin = this->begin();
					it = this->begin();
				}
				else
					++begin;
				;
			}
		}

		// reverse
		void reverse()
		{
			iterator first = begin();
			iterator last = end();
			while ((first != last) && (first != --last))
				my_swap(*first++, *last);
		}

		friend bool operator==(const ft::list<T, Alloc> &lhs, const ft::list<T, Alloc> &rhs)
		{
			return !(lhs < rhs || lhs > rhs);
		}

		friend bool operator!=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
		{
			return !(lhs == rhs);
		}

		friend bool operator<(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
		{
			if (lhs.size() < rhs.size())
				return (true);
			if (lhs.size() > rhs.size())
				return (false);
			return (lexicographical_compare_less(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		friend bool operator>(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
		{
			return (rhs < lhs);
		}

		friend bool operator<=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
		{
			return !(rhs < lhs);
		}

		friend bool operator>=(const list<T, Alloc> &lhs, const list<T, Alloc> &rhs)
		{
			return !(lhs < rhs);
		}

		friend void swap(list<T, Alloc> &x, list<T, Alloc> &y)
		{
			x.swap(y);
		}
	};
}

#endif