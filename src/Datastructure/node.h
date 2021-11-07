#pragma once
#include <cstdint>

namespace std_study
{
	template<typename T>
	class node
	{
	public:
		template<typename T> friend class list;
		template<typename T> friend class list_iterator;

	public:
		explicit node(const T& data) noexcept
			: data_(data),
			prev_(nullptr),
			next_(nullptr)
		{
		}

		node(const T& data, node* prev, node* next) noexcept
			: data_(data),
			prev_(prev),
			next_(next)
		{
		}

		virtual ~node()
		{
		}

	private:
		T data_;
		node* prev_;
		node* next_;
	};
}