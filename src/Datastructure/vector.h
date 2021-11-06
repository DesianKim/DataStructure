#pragma once
#include <cstdint>
#include <algorithm>
#include "vector_iterator.h"

namespace std_study
{
	template<typename T>
	class vector final
	{
	public:
		using iterator = vector_iterator<T>;

	public:
		vector() noexcept
			: size_(0),
			capacity_(0),
			data_(nullptr)
		{
		}

		~vector() noexcept
		{
			deallocate();
		}

		vector(const size_t size, const T data) noexcept
			: size_(size),
			capacity_(size)
		{
			allocate(data);
		}

	public:
		size_t size() const noexcept
		{
			return size_;
		}

		T& operator[](const uint32_t index) const
		{
			return data_[index];
		}

		iterator begin() const noexcept
		{
			return iterator(&data_[0]);
		}

		iterator end() const noexcept
		{
			return iterator(&data_[size_]);
		}

	private:
		void allocate(const T data) noexcept
		{
			data_ = new T[size_];
			std::fill_n(data_, size_, data);
		}

		void deallocate() noexcept
		{
			size_ = 0;
			capacity_ = 0;
			if (data_ != nullptr)
			{
				delete[] data_;
				data_ = nullptr;
			}
		}

	private:
		size_t size_;
		size_t capacity_;
		T* data_;
	}; //class vector final
}