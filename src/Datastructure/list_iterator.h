#pragma once
#include "node.h"

namespace std_study
{
	template<typename T>
	class list_iterator final
	{
	public:
		using Node = typename node<T>::Node;

		template<typename T> friend class list;
		
	public:
		list_iterator(Node* node) noexcept
			: ptr_(node)
		{
		}

		~list_iterator() noexcept
		{
		}

	public:
		T& operator*() const noexcept
		{
			return ptr_->data_;
		}

		list_iterator& operator++() noexcept
		{
			ptr_ = ptr_->next_;
			return (*this);
		}

		list_iterator& operator--() noexcept
		{
			ptr_ = ptr_->prev_;
			return (*this);
		}

		bool operator==(const list_iterator& it) const noexcept
		{
			return ptr_ == it.ptr_;
		}

		bool operator!=(const list_iterator& it) const noexcept
		{
			return ptr_ != it.ptr_;
		}

	private:
		Node* ptr_;
	}; //class list_iterator final
} //namespace std_study