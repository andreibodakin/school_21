#ifndef MAP_HPP
#define MAP_HPP

#include "map_tree.hpp"
#include "utils.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::pair<const Key, T> value_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef Compare key_compare;
		typedef Allocator allocator_type;

		typedef value_type *pointer;
		typedef value_type const *const_pointer;
		typedef value_type &reference;
		typedef value_type const &const_reference;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
		protected:
			key_compare comp;

			value_compare(key_compare comp) : comp(comp) {}

		public:
			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			}

			friend class map;
		};

		typedef typename MapTree<value_type, value_compare>::iterator iterator;
		typedef typename MapTree<value_type, value_compare>::const_iterator const_iterator;
		typedef typename MapTree<value_type, value_compare>::reverse_iterator reverse_iterator;
		typedef typename MapTree<value_type, value_compare>::const_reverse_iterator const_reverse_iterator;

	private:
		MapTree<value_type, value_compare> tree_;
		allocator_type alloc_;

	public:
		explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : 
		tree_(value_compare(comp)),
		alloc_(alloc)
		{
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()) : 
		tree_(first, last, value_compare(comp)),
		alloc_(alloc)
		{
		}

		map(const map &other) : 
		tree_(other.tree_),
		alloc_(other.alloc_)
		{
		}

		virtual ~map()
		{
		}

		map &operator=(const map &other)
		{
			if (this != &other)
			{
				this->tree_ = other.tree_;
				this->alloc_ = other.alloc_;
			}
			return *this;
		}

		iterator begin()
		{
			return this->tree_.begin();
		}

		const_iterator begin() const
		{
			return this->tree_.begin();
		}

		iterator end()
		{
			return this->tree_.end();
		}

		const_iterator end() const
		{
			return this->tree_.end();
		}

		reverse_iterator rbegin()
		{
			return this->tree_.rbegin();
		}

		const_reverse_iterator rbegin() const
		{
			return this->tree_.rbegin();
		}

		reverse_iterator rend()
		{
			return this->tree_.rend();
		}

		const_reverse_iterator rend() const
		{
			return this->tree_.rend();
		}

		bool empty() const
		{
			return this->tree_.empty();
		}

		size_type size() const
		{
			return this->tree_.size();
		}

		size_type max_size() const
		{
			return (std::numeric_limits<size_type>::max() / (2 * (sizeof(MapTree<value_type, value_compare>))));
			// return alloc_.max_size();
		}

		mapped_type &operator[](const key_type &key)
		{
			std::pair<iterator, bool> pair = this->insert(std::make_pair(key, mapped_type()));
			return pair.first->second;
		}

		std::pair<iterator, bool> insert(const value_type &val)
		{
			return this->tree_.insert_unique(val);
		}

		iterator insert(iterator position, const value_type &val)
		{
			return this->tree_.insert_unique(position, val).first;
		}

		template <class InputIt>
		void insert(InputIt first, InputIt last)
		{
			this->tree_.insert_unique(first, last);
		}

		void erase(iterator position)
		{
			this->tree_.erase(position);
		}

		size_type erase(const key_type &key)
		{
			iterator it = this->find(key);
			if (it == this->end())
				return 0;
			this->tree_.erase(it);
			return 1;
		}

		void erase(iterator first, iterator last)
		{
			this->tree_.erase(first, last);
		}

		void swap(map &x)
		{
			my_swap(this->tree_, x.tree_);
			my_swap(this->alloc_, x.alloc_);
		}

		void clear()
		{
			this->tree_.clear();
		}

		key_compare key_comp() const
		{
			return this->tree_.comp().comp;
		}

		value_compare value_comp() const
		{
			return this->tree_.comp();
		}

		iterator find(const key_type &key)
		{
			return this->tree_.find(std::make_pair(key, mapped_type()));
		}

		const_iterator find(const key_type &key) const
		{
			return this->tree_.find(std::make_pair(key, mapped_type()));
		}

		size_type count(const key_type &key) const
		{
			return (this->find(key) == this->end()) ? 0 : 1;
		}

		iterator lower_bound(const key_type &key)
		{
			return this->tree_.lower_bound(std::make_pair(key, mapped_type()));
		}

		const_iterator lower_bound(const key_type &key) const
		{
			return this->tree_.lower_bound(std::make_pair(key, mapped_type()));
		}

		iterator upper_bound(const key_type &key)
		{
			return this->tree_.upper_bound(std::make_pair(key, mapped_type()));
		}

		const_iterator upper_bound(const key_type &key) const
		{
			return this->tree_.upper_bound(std::make_pair(key, mapped_type()));
		}

		std::pair<iterator, iterator> equal_range(const key_type &key)
		{
			return std::make_pair(this->lower_bound(key), this->upper_bound(key));
		}

		std::pair<const_iterator, const_iterator> equal_range(const key_type &key) const
		{
			return std::make_pair(this->lower_bound(key), this->upper_bound(key));
		}
	};

	template <class Key, class T, class Compare>
	bool operator==(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return !(lhs < rhs || lhs > rhs);
	}

	template <class Key, class T, class Compare>
	bool operator!=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class Key, class T, class Compare>
	bool operator<(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		if (lhs.size() < rhs.size())
			return (true);
		if (lhs.size() > rhs.size())
			return (false);
		return lexicographical_compare_less(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class Key, class T, class Compare>
	bool operator<=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class Key, class T, class Compare>
	bool operator>(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return (rhs < lhs);
	}

	template <class Key, class T, class Compare>
	bool operator>=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return !(lhs < rhs);
	}

	template <class Key, class T, class Compare>
	void swap(map<Key, T, Compare> &lhs, map<Key, T, Compare> &rhs)
	{
		lhs.swap(rhs);
	}
}

#endif