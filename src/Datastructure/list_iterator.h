#pragma once
#include "node.h"

namespace std_study
{
	template<typename T>
	class list_iterator
	{
	public:
		using Node = node<T>;

	public:
		explicit list_iterator(Node* n) noexcept
			: node_(n)
		{
		}

		virtual ~list_iterator() noexcept
		{
		}

	public:
		void set_node(Node* node) noexcept
		{
			node_ = node;
		}

		Node* get_node() const noexcept
		{
			return node_;
		}

		T& operator*() const noexcept
		{
			return node_->data_;
		}

		list_iterator& operator++() noexcept
		{
			node_ = node_->next_;
			return (*this);
		}

		list_iterator& operator--() noexcept
		{
			node_ = node_->prev_;
			return (*this);
		}

		bool operator==(const list_iterator& itr) const noexcept
		{
			return node_ == itr.node_;
		}

		bool operator!=(const list_iterator& itr) const noexcept
		{
			return node_ != itr.node_;
		}

	protected:
		Node* node_;
	};
}