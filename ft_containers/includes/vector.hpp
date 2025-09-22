#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterators.hpp"
#include "utils.hpp"

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef random_access_iterator<T> iterator;
		typedef const_random_access_iterator<T> const_iterator;
		typedef reverse_random_access_iterator<T> reverse_iterator;
		typedef const_reverse_random_access_iterator<T> const_reverse_iterator;

	private:
		value_type *ptr_;
		size_type size_;
		size_type capacity_;
		allocator_type Alloc_;

	public:
		explicit vector(const allocator_type &alloc = allocator_type()) : size_(0), capacity_(0)
		{
			Alloc_ = alloc;
			ptr_ = my_nullptr;
		}

		explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
		{
			Alloc_ = alloc;
			if (n > 0)
			{
				size_ = n;
				capacity_ = n;
				ptr_ = Alloc_.allocate(n);
				for (size_type i = 0; i < n; i++)
					ptr_[i] = val;
			}
			else
			{
				capacity_ = 0;
				size_ = 0;
				ptr_ = my_nullptr;
			}
		}

		template <class InputIterator>
		vector(InputIterator first, typename enable_if<std::is_class<InputIterator>::value, InputIterator>::type last, const allocator_type &alloc = allocator_type())
		{
			Alloc_ = alloc;
			size_ = 0;
			capacity_ = 0;
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		vector(const vector &x)
		{
			Alloc_ = x.Alloc_;
			size_ = 0;
			capacity_ = 0;
			*this = x;
		}

		vector &operator=(const vector &other)
		{
			clear();
			if (other.empty())
				return (*this);
			for (const_iterator it = other.begin(); it != other.end(); it++)
				push_back(*it);
			return (*this);
		}

		virtual ~vector()
		{
			if (capacity_ > 0)
				Alloc_.deallocate(ptr_, capacity_);
		}

		iterator begin()
		{
			return (iterator(ptr_));
		}

		const_iterator begin() const
		{
			return (iterator(ptr_));
		}

		iterator end()
		{
			return (iterator(ptr_ + size_));
		}

		const_iterator end() const
		{
			return (iterator(ptr_ + size_));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(ptr_ + size_ - 1));
		}

		const_reverse_iterator rbegin() const
		{
			return (reverse_iterator(ptr_ + size_ - 1));
		}

		reverse_iterator rend()
		{
			return (reverse_iterator(ptr_ - 1));
		}

		const_reverse_iterator rend() const
		{
			return (reverse_iterator(ptr_ - 1));
		}

		size_type size() const
		{
			return (size_);
		}

		size_type max_size() const
		{
			return (Alloc_.max_size());
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (size_ == n)
				return;
			while (size_ != n)
			{
				if (size_ > n)
					pop_back();
				else
					push_back(val);
			}
		}

		size_type capacity() const
		{
			return (capacity_);
		}

		bool empty() const
		{
			return (size_ == 0);
		}

		void reserve(size_type n)
		{
			if (n > max_size())
				throw(std::length_error("Length error"));
			else if (capacity_ >= n)
				return;

			pointer tmp;

			tmp = Alloc_.allocate(n);
			for (size_type i = 0; i < size_; i++)
				Alloc_.construct(tmp + i, *(ptr_ + i));
			if (capacity_)
				Alloc_.deallocate(ptr_, capacity_);
			ptr_ = tmp;
			capacity_ = n;
		}

		reference operator[](size_type i)
		{
			return (ptr_[i]);
		}

		const_reference operator[](size_type i) const
		{
			return (ptr_[i]);
		}

		reference at(size_type n)
		{
			if (n >= size_)
				throw std::out_of_range("Out of range");
			return (ptr_[n]);
		}

		const_reference at(size_type n) const
		{
			if (n >= size_)
				throw std::out_of_range("Out of range");
			return (ptr_[n]);
		}

		reference front()
		{
			return (ptr_[0]);
		}

		const_reference front() const
		{
			return (ptr_[0]);
		}

		reference back()
		{
			return (ptr_[size_ - 1]);
		}

		const_reference back() const
		{
			return (ptr_[size_ - 1]);
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

		void push_back(const value_type &val)
		{
			if (!capacity_)
				reserve(1);
			else if (size_ >= capacity_)
				reserve(size_ * 2);
			Alloc_.construct(&ptr_[size_], val);
			++size_;
		}

		void pop_back()
		{
			Alloc_.destroy(&ptr_[size_]);
			--size_;
		}

		iterator insert(iterator position, const value_type &val)
		{
			insert(position, 1, val);
			size_type pos_len = &(*position) - ptr_;

			return (iterator(ptr_ + pos_len));
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			if (n == 0)
				return;
			if (n > this->max_size())
				throw(std::length_error("Length error: insert"));

			size_type pos_len = &(*position) - ptr_;
			int new_capacity = capacity_;

			if (size_ + n > capacity_)
				new_capacity = (n < capacity_) ? capacity_ * 2 : capacity_ + n;

			pointer tmp = Alloc_.allocate(new_capacity);

			for (size_type i = 0; i < pos_len; i++)
				Alloc_.construct(tmp + i, *(ptr_ + i));
			for (size_type h = 0; h < n; h++)
				Alloc_.construct(tmp + pos_len + h, val);
			for (size_type j = 0; j < size_ - pos_len; j++)
				Alloc_.construct(tmp + pos_len + n + j, *(ptr_ + pos_len + j));

			for (size_type k = 0; k < size_; k++)
				Alloc_.destroy(ptr_ + k);
			Alloc_.deallocate(ptr_, capacity_);

			ptr_ = tmp;
			capacity_ = new_capacity;
			size_ += n;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, typename enable_if<std::is_class<InputIterator>::value, InputIterator>::type last)
		{
			size_type n = difference(first, last);

			if (n == 0)
				return;
			if (n > this->max_size())
				throw(std::length_error("Length error: insert"));

			size_type pos_len = &(*position) - ptr_;
			int new_capacity = capacity_;

			if (size_ + n > capacity_)
				new_capacity = (n < capacity_) ? capacity_ * 2 : capacity_ + n;

			pointer tmp = Alloc_.allocate(new_capacity);

			for (size_type i = 0; i < pos_len; i++)
				Alloc_.construct(tmp + i, *(ptr_ + i));
			for (size_type h = 0; h < n; first++, h++)
				Alloc_.construct(tmp + pos_len + h, *first);
			for (size_type j = 0; j < size_ - pos_len; j++)
				Alloc_.construct(tmp + n + j + pos_len, *(ptr_ + j + pos_len));

			for (size_type k = 0; k < size_; k++)
				Alloc_.destroy(ptr_ + k);
			if (capacity_)
				Alloc_.deallocate(ptr_, capacity_);

			ptr_ = tmp;
			capacity_ = new_capacity;
			size_ += n;
		}

		iterator erase(iterator position)
		{
			return (erase(position, position + 1));
		}

		iterator erase(iterator first, iterator last)
		{
			iterator result(last);

			while (last != end())
			{
				*first = *last;
				++first;
				++last;
			}
			size_ -= difference(first, last);
			return (result);
		}

		void swap(vector &x)
		{
			if (this != &x)
			{
				my_swap(this->ptr_, x.ptr_);
				my_swap(this->size_, x.size_);
				my_swap(this->capacity_, x.capacity_);
				my_swap(this->Alloc_, x.Alloc_);
			}
		}

		void clear()
		{
			if (size_ == 0)
				return;
			Alloc_.deallocate(ptr_, capacity_);
			ptr_ = my_nullptr;
			size_ = 0;
			capacity_ = 0;
		}

		friend bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
		{
			return !(lhs < rhs || lhs > rhs);
		}

		friend bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (!(lhs == rhs));
		}

		friend bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			if (lhs.size() < rhs.size())
				return (true);
			if (lhs.size() > rhs.size())
				return (false);
			return (lexicographical_compare_less(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		}

		friend bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (!(rhs < lhs));
		}

		friend bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (rhs < lhs);
		}

		friend bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (!(lhs < rhs));
		}

		friend void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
		{
			x.swap(y);
		}
	};
}

#endif