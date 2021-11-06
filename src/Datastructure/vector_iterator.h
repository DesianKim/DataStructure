#pragma once

namespace std_study
{
	template<typename T>
	class vector_iterator
	{
	public:
		vector_iterator() noexcept
			: data_pointer_(nullptr)
		{
		}

		explicit vector_iterator(T* data_pointer) noexcept
			: data_pointer_(data_pointer)
		{
		}

		virtual ~vector_iterator() noexcept
		{
		}

	public:
		T& operator*() const noexcept
		{
			return *data_pointer_;
		}

		vector_iterator& operator++() noexcept
		{
			++data_pointer_;
			return (*this);
		}

		vector_iterator& operator--() noexcept
		{
			--data_pointer_;
			return (*this);
		}

		bool operator==(const vector_iterator& itr) const noexcept
		{
			return data_pointer_ == itr.data_pointer_;
		}

		bool operator!=(const vector_iterator& itr) const noexcept
		{
			return data_pointer_ != itr.data_pointer_;
		}

	private:
		T* data_pointer_;
	}; //class vector_iterator
}