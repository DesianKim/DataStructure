#pragma once
#include <deque>

namespace std_study
{
	template<typename T, 
		typename Container = std::deque<T>> //std::vector, std::list
	class stack final
	{
	public:
		stack() noexcept
			: container_{}
		{
		}

		~stack() noexcept
		{
		}

	public:
		void push(const T& data) noexcept
		{
			container_.push_back(data);
		}

		const T& top() const noexcept 
		{
			return container_.back();
		}

		T& top() noexcept
		{
			return container_.back();
		}

		void pop() noexcept
		{
			container_.pop_back();
		}

		bool empty() const noexcept
		{
			return container_.empty();
		}

		size_t size() const noexcept
		{
			return container_.size();
		}

	private:
		Container container_;
	}; //class stack final
} //namespace std_study