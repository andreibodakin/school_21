#ifndef MAP_TREE_HPP
#define MAP_TREE_HPP

#include "utils.hpp"

namespace ft
{
	template <typename KT, typename Compare>
	class MapTree;

	template <typename KT>
	struct Node
	{
		typedef KT value_type;

		value_type data;
		Node *parent;
		Node *left;
		Node *right;

		Node(const value_type &data) : data(data), parent(NULL), left(NULL), right(NULL)
		{
		}

		Node(const value_type &data, Node *parent, Node *left, Node *right) : data(data), parent(parent), left(left), right(right)
		{
		}
	};

	template <typename T>
	class MapTreeIterator
	{
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef const T *const_pointer;
		typedef const T &const_reference;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		typedef Node<value_type> node;

	protected:
		node *ptr_current;

	public:
		MapTreeIterator() : ptr_current(NULL) {}
		MapTreeIterator(node *node) : ptr_current(node) {}
		MapTreeIterator(MapTreeIterator const &src) : ptr_current(src.ptr_current) {}
		virtual ~MapTreeIterator() {}

		MapTreeIterator &operator=(MapTreeIterator const &rhs)
		{
			this->ptr_current = rhs.ptr_current;
			return *this;
		}

		reference operator*()
		{
			return this->ptr_current->data;
		}

		const_reference operator*() const
		{
			return this->ptr_current->data;
		}

		pointer operator->()
		{
			return &this->ptr_current->data;
		}

		const_pointer operator->() const
		{
			return &this->ptr_current->data;
		}

		MapTreeIterator &operator++()
		{
			if (this->ptr_current->right)
			{
				this->ptr_current = this->ptr_current->right;
				while (this->ptr_current->left)
					this->ptr_current = this->ptr_current->left;
			}
			else
			{
				node *prev;
				do
				{
					prev = this->ptr_current;
					this->ptr_current = this->ptr_current->parent;
				} while (this->ptr_current && prev == this->ptr_current->right);
			}

			return *this;
		}

		MapTreeIterator operator++(int)
		{
			MapTreeIterator it = *this;
			operator++();

			return it;
		}

		MapTreeIterator &operator--()
		{
			if (this->ptr_current->left)
			{
				this->ptr_current = this->ptr_current->left;
				while (this->ptr_current && this->ptr_current->right)
					this->ptr_current = this->ptr_current->right;
			}
			else
			{
				node *prev;
				do
				{
					prev = this->ptr_current;
					this->ptr_current = this->ptr_current->parent;
				} while (this->ptr_current && prev == this->ptr_current->left);
			}

			return *this;
		}

		MapTreeIterator operator--(int)
		{
			MapTreeIterator it = *this;
			operator--();

			return it;
		}

		friend bool operator==(const MapTreeIterator<T> &lhs, const MapTreeIterator<T> &rhs)
		{
			return lhs.ptr_current == rhs.ptr_current;
		}

		friend bool operator!=(const MapTreeIterator<T> &lhs, const MapTreeIterator<T> &rhs)
		{
			return lhs.ptr_current != rhs.ptr_current;
		}

		template <typename KT, typename Compare>
		friend class MapTree;
	};

	template <typename T>
	class MapTreeReverseIterator
	{
	public:
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef const T *const_pointer;
		typedef const T &const_reference;
		typedef ptrdiff_t difference_type;
		typedef size_t size_type;

		typedef Node<value_type> node;

	protected:
		node *ptr_current;

	public:
		MapTreeReverseIterator() : ptr_current(NULL) {}
		MapTreeReverseIterator(node *node) : ptr_current(node) {}
		MapTreeReverseIterator(MapTreeReverseIterator const &src) : ptr_current(src.ptr_current) {}
		virtual ~MapTreeReverseIterator() {}

		MapTreeReverseIterator &operator=(MapTreeReverseIterator const &rhs)
		{
			this->ptr_current = rhs.ptr_current;
			return *this;
		}

		reference operator*()
		{
			return this->ptr_current->data;
		}

		const_reference operator*() const
		{
			return this->ptr_current->data;
		}

		pointer operator->()
		{
			return &this->ptr_current->data;
		}

		const_pointer operator->() const
		{
			return &this->ptr_current->data;
		}

		MapTreeReverseIterator &operator++()
		{
			if (this->ptr_current->left)
			{
				this->ptr_current = this->ptr_current->left;
				while (this->ptr_current && this->ptr_current->right)
					this->ptr_current = this->ptr_current->right;
			}
			else
			{
				node *prev;
				do
				{
					prev = this->ptr_current;
					this->ptr_current = this->ptr_current->parent;
				} while (this->ptr_current && prev == this->ptr_current->left);
			}

			return *this;
		}

		MapTreeReverseIterator operator++(int)
		{
			MapTreeReverseIterator it = *this;
			operator++();

			return it;
		}

		MapTreeReverseIterator &operator--()
		{
			if (this->ptr_current->right)
			{
				this->ptr_current = this->ptr_current->right;
				while (this->ptr_current->left)
					this->ptr_current = this->ptr_current->left;
			}
			else
			{
				node *prev;
				do
				{
					prev = this->ptr_current;
					this->ptr_current = this->ptr_current->parent;
				} while (this->ptr_current && prev == this->ptr_current->right);
			}

			return *this;
		}

		MapTreeReverseIterator operator--(int)
		{
			MapTreeReverseIterator it = *this;
			operator--();

			return it;
		}

		friend bool operator==(const MapTreeReverseIterator<T> &lhs, const MapTreeReverseIterator<T> &rhs)
		{
			return lhs.ptr_current == rhs.ptr_current;
		}

		friend bool operator!=(const MapTreeReverseIterator<T> &lhs, const MapTreeReverseIterator<T> &rhs)
		{
			return lhs.ptr_current != rhs.ptr_current;
		}

		template <typename KT, typename Compare>
		friend class MapTree;
	};

	template <typename KT, typename Compare>
	class MapTree
	{
	public:
		typedef KT value_type;
		typedef value_type *pointer;
		typedef const value_type *const_pointer;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;

		typedef Compare value_compare;

		typedef MapTreeIterator<value_type> iterator;
		typedef MapTreeIterator<value_type> const_iterator;
		typedef MapTreeReverseIterator<value_type> reverse_iterator;
		typedef MapTreeReverseIterator<value_type> const_reverse_iterator;

		typedef Node<value_type> node;

	private:
		node *root_;
		node *end_;
		size_type size_;
		value_compare comp_;

	public:
		MapTree(const value_compare &comp = value_compare())
			: root_(NULL), size_(0), comp_(comp)
		{
			this->end_ = new node(value_type());
			this->root_ = this->end_;
		}

		template <class InputIt>
		MapTree(InputIt first, InputIt last, const value_compare &comp = value_compare())
			: root_(NULL), size_(0), comp_(comp)
		{
			this->end_ = new node(value_type());
			this->root_ = this->end_;

			this->insert_unique(first, last);
		}

		MapTree(const MapTree &src)
			: root_(NULL), size_(0), comp_(src.comp())
		{
			this->end_ = new node(value_type());
			this->root_ = this->end_;

			if (src.size())
				this->copy_tree(src);
		}

		~MapTree()
		{
			this->clear();
			delete this->end_;
		}

		MapTree &operator=(const MapTree &rhs)
		{
			if (this != &rhs)
			{
				this->clear();
				if (rhs.size())
					this->insert_unique(rhs.begin(), rhs.end());
			}
			return *this;
		}

		iterator begin()
		{
			node *first = this->root_;

			while (first && first->left)
				first = first->left;

			return iterator(first);
		}

		const_iterator begin() const
		{
			node *first = this->root_;

			while (first && first->left)
				first = first->left;

			return const_iterator(first);
		}

		iterator end()
		{
			return iterator(this->end_);
		}

		const_iterator end() const
		{
			return iterator(this->end_);
		}

		reverse_iterator rbegin()
		{
			node *last = this->end_;

			last = last->parent;
			return reverse_iterator(last);
		}

		const_reverse_iterator rbegin() const
		{
			node *last = this->end_;

			last = last->parent;
			return const_reverse_iterator(last);
		}

		reverse_iterator rend()
		{
			node *first = this->root_;

			while (first && first->left)
				first = first->left;
			first = first->left;
			return reverse_iterator(first);
		}

		const_reverse_iterator rend() const
		{
			node *first = this->root_;

			while (first && first->left)
				first = first->left;
			first = first->left;
			return const_reverse_iterator(first);
		}

		bool empty() const
		{
			return (this->size_ == 0);
		}

		size_type size() const
		{
			return this->size_;
		}

		std::pair<iterator, bool> insert_unique(const value_type &value)
		{
			return this->insert_unique(iterator(this->root_), value);
		}

		void copy_nodes(node **destNode, node *srcNode, node *end)
		{
			if (!srcNode)
				return;

			*destNode = new node(srcNode->data);
			if (srcNode->left)
			{
				copy_nodes(&(*destNode)->left, srcNode->left, end);
				(*destNode)->left->parent = *destNode;
			}
			if (srcNode->right)
			{
				if (srcNode->right == end)
				{
					this->end_->parent = *destNode;
					(*destNode)->right = this->end_;
					return;
				}
				copy_nodes(&(*destNode)->right, srcNode->right, end);
				(*destNode)->right->parent = *destNode;
			}
		}

		void copy_tree(const MapTree &src)
		{
			this->root_ = new node(src.root_->data);

			if (src.root_->left)
			{
				this->copy_nodes(&this->root_->left, src.root_->left, src.end_);
				this->root_->left->parent = this->root_;
			}
			if (src.root_->right)
			{
				this->copy_nodes(&this->root_->right, src.root_->right, src.end_);
				this->root_->right->parent = this->root_;
			}

			this->size_ = src.size_;
		}

		std::pair<iterator, bool> insert_unique(iterator position, const value_type &value)
		{
			(void)position;
			typedef std::pair<iterator, bool> pair_res;

			node *newNode = new node(value);

			if (this->root_ == this->end_)
			{
				this->root_ = newNode;
				this->root_->right = this->end_;
				this->end_->parent = this->root_;

				++this->size_;

				return pair_res(iterator(this->root_), true);
			}

			node *currentNode = this->root_;

			while (true)
			{
				if (currentNode == this->end_)
				{
					currentNode = this->end_->parent;
					currentNode->right = newNode;
					newNode->parent = currentNode;
					newNode->right = this->end_;

					this->end_->parent = newNode;
					break;
				}

				bool to_left = this->comp_(value, currentNode->data);

				if (!to_left && !this->comp_(currentNode->data, value))
				{
					delete newNode;
					return pair_res(iterator(currentNode), false);
				}

				if (to_left)
				{
					if (currentNode->left)
						currentNode = currentNode->left;
					else
					{
						newNode->parent = currentNode;
						currentNode->left = newNode;
						break;
					}
				}
				else
				{
					if (currentNode->right)
						currentNode = currentNode->right;
					else
					{
						newNode->parent = currentNode;
						currentNode->right = newNode;
						break;
					}
				}
			}
			++this->size_;

			return pair_res(iterator(newNode), true);
		}

		template <class InputIt>
		void insert_unique(InputIt first, InputIt last)
		{
			while (first != last)
			{
				this->insert_unique(*first);
				++first;
			}
		}

		void erase(iterator position)
		{
			if (position == this->end())
				return;

			node **node_left = &position.ptr_current->left;
			node **node_right = &position.ptr_current->right;
			node *node_parent = position.ptr_current->parent;

			if (!*node_left && !*node_right)
			{
				if (node_parent)
				{
					if (position.ptr_current == position.ptr_current->parent->left)
						position.ptr_current->parent->left = NULL;
					else
						position.ptr_current->parent->right = NULL;
				}

				delete position.ptr_current;
				--this->size_;

				return;
			}

			if (*node_left && !*node_right)
			{
				(*node_left)->parent = node_parent;
				if (node_parent)
				{
					if (position.ptr_current == position.ptr_current->parent->left)
						position.ptr_current->parent->left = *node_left;
					else
						position.ptr_current->parent->right = *node_left;
				}
			}
			else if (*node_left && *node_right == this->end_)
			{
				node *node_max = *node_left;
				while (node_max->right != NULL)
					node_max = node_max->right;

				node_max->right = this->end_;
				this->end_->parent = node_max;

				(*node_left)->parent = node_parent;
				if (node_parent)
				{
					if (position.ptr_current == position.ptr_current->parent->left)
						position.ptr_current->parent->left = *node_left;
					else
						position.ptr_current->parent->right = *node_left;
				}
			}
			else if (!*node_left && *node_right)
			{
				if (!node_parent)
				{
					if (this->size_ == 1)
					{
						this->end_->parent = NULL;
						this->root_ = this->end_;
					}
					else
					{
						this->root_ = this->root_->right;
						this->root_->parent = NULL;
					}
				}
				else
				{
					(*node_right)->parent = node_parent;
					if (node_parent)
					{
						if (position.ptr_current == position.ptr_current->parent->left)
							position.ptr_current->parent->left = *node_right;
						else
							position.ptr_current->parent->right = *node_right;
					}
				}
			}
			else
			{
				node *node_min = *node_right;
				while (node_min->left != NULL)
					node_min = node_min->left;

				if (!node_min->right)
				{
					if (node_min->parent->left == node_min)
						node_min->parent->left = NULL;
					else
						node_min->parent->right = NULL;
				}
				else
				{
					node_min->right->parent = node_min->parent;

					if (node_min->parent->left == node_min)
						node_min->parent->left = node_min->right;
					else
						node_min->parent->right = node_min->right;
				}
				node_min->left = *node_left;
				node_min->right = *node_right;
				node_min->left->parent = node_min;
				node_min->right->parent = node_min;

				if (!node_parent)
				{
					this->root_ = node_min;
					this->root_->parent = NULL;
				}
				else
				{
					if (node_parent)
					{
						if (position.ptr_current == position.ptr_current->parent->left)
							position.ptr_current->parent->left = node_min;
						else
							position.ptr_current->parent->right = node_min;
					}
				}
			}

			delete position.ptr_current;
			--this->size_;
		}

		void erase(iterator first, iterator last)
		{
			while (first != last)
			{
				iterator tmp = first;
				tmp++;
				this->erase(first);
				first = tmp;
			}
		}

		void clear()
		{
			this->erase(this->begin(), this->end());

			this->end_->parent = NULL;
			this->root_ = this->end_;

			this->size_ = 0;
		}

		value_compare comp() const
		{
			return this->comp_;
		}

		iterator find(const value_type &value)
		{
			node *resultNode = this->root_;

			while (resultNode && resultNode != this->end_)
			{
				bool to_left = this->comp_(resultNode->data, value);
				if (!to_left && !this->comp_(value, resultNode->data))
					return iterator(resultNode);

				if (to_left)
					resultNode = resultNode->right;
				else
					resultNode = resultNode->left;
			}

			return this->end();
		}

		const_iterator find(const value_type &value) const
		{
			node *resultNode = this->root_;

			while (resultNode && resultNode != this->end_)
			{
				bool to_left = this->comp_(resultNode->data, value);
				if (!to_left && !this->comp_(value, resultNode->data))
					return const_iterator(resultNode);

				if (to_left)
					resultNode = resultNode->right;
				else
					resultNode = resultNode->left;
			}

			return this->end();
		}

		iterator lower_bound(const value_type &value)
		{
			iterator it = this->begin();
			iterator itEnd = this->end();

			while (it != itEnd)
			{
				if (!this->comp_(*it, value))
					return it;
				++it;
			}

			return itEnd;
		}

		const_iterator lower_bound(const value_type &value) const
		{
			const_iterator it = this->begin();
			const_iterator itEnd = this->end();

			while (it != itEnd)
			{
				if (!this->comp_(*it, value))
					return it;
				++it;
			}

			return itEnd;
		}

		iterator upper_bound(const value_type &value)
		{
			iterator it = this->begin();
			iterator itEnd = this->end();

			while (it != itEnd)
			{
				if (this->comp_(value, *it))
					return it;
				++it;
			}

			return itEnd;
		}

		const_iterator upper_bound(const value_type &value) const
		{
			const_iterator it = this->begin();
			const_iterator itEnd = this->end();

			while (it != itEnd)
			{
				if (this->comp_(value, *it))
					return it;
				++it;
			}

			return itEnd;
		}

		friend bool operator==(const MapTree &lhs, const MapTree &rhs)
		{
			return !(lhs < rhs || lhs > rhs);
		}

		friend bool operator!=(const MapTree &lhs, const MapTree &rhs)
		{
			return !(lhs == rhs);
		}

		friend bool operator<(const MapTree &lhs, const MapTree &rhs)
		{
			if (lhs.size() < rhs.size())
				return (true);
			if (lhs.size() > rhs.size())
				return (false);
			return lexicographical_compare_less(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}

		friend bool operator<=(const MapTree &lhs, const MapTree &rhs)
		{
			return !(rhs < lhs);
		}

		friend bool operator>(const MapTree &lhs, const MapTree &rhs)
		{
			return rhs < lhs;
		}

		friend bool operator>=(const MapTree &lhs, const MapTree &rhs)
		{
			return !(lhs < rhs);
		}
	};

	template <typename KT>
	Node<KT> *tree_increment(Node<KT> *node);
}

#endif