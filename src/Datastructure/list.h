#pragma once
#include "node.h"
#include "list_iterator.h"

namespace std_study
{
	template<typename T>
	class list final
	{
	private:
		using Node = typename node<T>::Node;
	public:
		using iterator = list_iterator<T>;

	public:
		list() noexcept
			: size_(0)
		{
			header_ = new Node(T{});
		}

		~list() noexcept
		{
			if (empty() == false)
				pop_front();

			delete header_;
		}

	public:
		size_t size() const noexcept
		{
			return size_;
		}

		bool empty() const noexcept
		{
			return size_ == 0;
		}

		void push_front(const T& data) noexcept
		{
			insert(begin(), data);
		}

		void push_back(const T& data) noexcept
		{
			insert(end(), data);
		}

		void pop_front() noexcept
		{
			erase(begin());
		}

		void pop_back() noexcept
		{
			erase(--end());
		}

		iterator insert(const iterator& pos, const T& data) noexcept
		{
			Node* curr_node = pos.ptr_;
			Node* new_node = nullptr;

			if (empty() == true)
				new_node = new Node(data, header_, header_);
			else
				new_node = new Node(data, curr_node->prev_, curr_node);

			new_node->prev_->next_ = new_node;
			new_node->next_->prev_ = new_node;
			++size_;

			return iterator(new_node);
		}

		iterator erase(const iterator& pos) noexcept
		{
			if (empty() == false)
			{
				Node* curr_node = pos.ptr_;
				Node* next_node = curr_node->next_;
				curr_node->prev_->next_ = curr_node->next_;
				curr_node->next_->prev_ = curr_node->prev_;
				delete curr_node;
				--size_;

				return iterator(next_node);
			}
			else
				return end();
		}

		iterator begin() const noexcept
		{
			return iterator(header_->next_);
		}

		iterator end() const noexcept
		{
			return iterator(header_);
		}

	private:
		size_t size_;
		Node* header_;
	}; //class list final
} //namespace std_study