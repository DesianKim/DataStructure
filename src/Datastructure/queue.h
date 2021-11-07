#pragma once
#include <deque>

namespace std_study
{
	template<typename T,
		typename Container = std::deque<T>> //std::list
	class queue final
	{
	public:
		queue() noexcept
			: container_{}
		{
		}

		~queue() noexcept
		{
		}

	public:
		bool empty() const noexcept
		{
			return container_.empty();
		}

		size_t size() const noexcept
		{
			return container_.size();
		}

		void push(const T& data) noexcept
		{
			container_.push_back(data);
		}

		void pop() noexcept
		{
			container_.pop_front();
		}

		T& front() noexcept
		{
			return container_.front();
		}

		const T& front() const noexcept
		{
			return container_.front();
		}

	private:
		Container container_;
	}; //class queue final
} //namespace std_study