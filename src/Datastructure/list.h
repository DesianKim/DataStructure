#pragma once
#include "node.h"
#include "list_iterator.h"

namespace std_study
{
	template<typename T>
	class list final
	{
	public:
		using Node = node<T>;
		using iterator = list_iterator<T>;

	public:
		list() noexcept
			: size_(0)
		{
			header_ = new Node(0, nullptr, nullptr);
			trailer_ = new Node(0, nullptr, nullptr);

			header_->next_ = trailer_;
			trailer_->prev_ = header_;
		}

		~list() noexcept
		{
			while (empty() == false)
			{
				pop_front();
			}

			delete header_;
			delete trailer_;
		}

	public:
		size_t size() const noexcept
		{
			return size_;
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
			if (empty() == false)
				erase(begin());
		}

		void pop_back() noexcept
		{
			if (empty() == false)
				erase(--end());
		}

		bool empty() const noexcept
		{
			return size_ == 0;
		}


		void insert(const iterator& pos, const T& data) noexcept
		{
			Node* curr_node = pos.get_node();
			Node* new_node = new Node(data, curr_node->prev_, curr_node);
			new_node->prev_->next_ = new_node;
			new_node->next_->prev_ = new_node;
			++size_;
		}

		void erase(const iterator& pos) noexcept
		{
			Node* curr_node = pos.get_node();
			curr_node->prev_->next_ = curr_node->next_;
			curr_node->next_->prev_ = curr_node->prev_;
			delete curr_node;
			--size_;
		}

		iterator begin() const noexcept
		{
			return iterator(header_->next_);
		}

		iterator end() const noexcept
		{
			return iterator(trailer_);
		}

	private:
		size_t size_;
		Node* header_;
		Node* trailer_;
	};
}