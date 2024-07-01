#include "../include/vector_ry.hpp"

namespace ry_stl{

//构造
template <typename T, typename Alloc>
vector_ry <T,Alloc>::vector_ry()
	:data_(nullptr),size_(0),capacity_(0){}


template <typename T, typename Alloc>
vector_ry <T,Alloc>::vector_ry(size_type n)
	:size_(n),capacity_(n){
		data_ = allocator_.allocate(capacity_);
    	for (size_type i = 0; i < size_; ++i) {
       		allocator_.construct(data_ + i);
		}
	}


//析构
template <typename T, typename Alloc>
vector_ry <T,Alloc>::~vector_ry(){
	for(size_type i = 0; i < size_ ; ++i){
		allocator_.destroy(data_+i);
	}
	allocator_.deallocate(data_, capacity_);
	}	


//容量相关
template <typename T, typename Alloc>
typename vector_ry<T, Alloc>::size_type vector_ry <T, Alloc>::size() const noexcept {
	return size_;
}

template <typename T, typename Alloc>
typename vector_ry<T, Alloc>::size_type vector_ry <T, Alloc>::capacity() const noexcept {
	return capacity_;
}

template <typename T, typename Alloc>
bool vector_ry <T, Alloc>::empty() const noexcept {
    return size_ == 0;
}

//分配
template<typename T, typename Alloc>
void vector_ry<T, Alloc>::reallocate(size_type new_cap) {
    pointer new_data = allocator_.allocate(new_cap);
    for (size_type i = 0; i < size_; ++i) {
        allocator_.construct(new_data + i, std::move(data_[i]));
        allocator_.destroy(data_ + i);
    }
    allocator_.deallocate(data_, capacity_);
    data_ = new_data;
    capacity_ = new_cap;
}

template<typename T, typename Alloc>
void vector_ry<T, Alloc>::reserve(size_type new_cap) {
    if (new_cap > capacity_) {
        reallocate(new_cap);
    }
}

//操作符
template<typename T, typename Alloc>
typename vector_ry<T, Alloc>::reference vector_ry<T, Alloc>::operator[](size_type pos) {
    return data_[pos];
}

template<typename T, typename Alloc>
typename vector_ry<T, Alloc>::const_reference vector_ry<T, Alloc>::operator[](size_type pos) const {
    return data_[pos];
}

template<typename T, typename Alloc>
typename vector_ry<T, Alloc>::iterator vector_ry<T, Alloc>::begin() noexcept {
    return size_ > 0 ? data_ : nullptr;
}

template<typename T, typename Alloc>
typename vector_ry<T, Alloc>::const_iterator vector_ry<T, Alloc>::begin() const noexcept {
    return size_ > 0 ? data_ : nullptr;
}

template<typename T, typename Alloc>
typename vector_ry<T, Alloc>::iterator vector_ry<T, Alloc>::end() noexcept {
    return size_ > 0 ? data_ + size_ : nullptr;
}

template<typename T, typename Alloc>
typename vector_ry<T, Alloc>::const_iterator vector_ry<T, Alloc>::end() const noexcept {
    return size_ > 0 ? data_ + size_ : nullptr;
}

//修改器
template<typename T, typename Alloc>
void vector_ry<T, Alloc>::push_back(const value_type& val) {
    if (size_ == capacity_) {
        reserve(capacity_ == 0 ? 1 : capacity_ * 2);
    }
    allocator_.construct(data_ + size_, val);
    ++size_;
}

template<typename T, typename Alloc>
void vector_ry<T, Alloc>::pop_back(){
	if (size_ > 0){
		allocator_.destroy(data_ + size_ - 1);
		--size_;
	}
}

}