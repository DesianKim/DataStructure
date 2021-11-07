#pragma once
#include <cstdint>

namespace std_study
{
	template<typename T>
	class node final
	{
	public:
		using Node = node<T>;

		template<typename T> friend class list_iterator;
		template<typename T> friend class list;

	public:
		explicit node(const T& data) noexcept
			: data_(data),
			prev_(nullptr),
			next_(nullptr)
		{
		}

		node(const T& data, Node* prev, Node* next) noexcept
			: data_(data),
			prev_(prev),
			next_(next)
		{
		}

		~node() noexcept
		{
		}

	private:
		Node* prev_;
		Node* next_;
		T data_;

	}; //class node final
} //namespace std_study