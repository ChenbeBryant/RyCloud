#include "include/vector_ry.hpp"

namespace ry_stl{

//����
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


//����
template <typename T, typename Alloc>
vector_ry <T,Alloc>::~vector_ry(){
	for(size_type i = 0; i < size_ ; ++i){
		allocator_.destory(data+i);
	}
	allocator_.deallocate(data_, capacity_);
	}	


//����ʵ��
template <typename T, typename Alloc>
bool vector_ry <T, Alloc>::empty() const noexcept {
    return size_ == 0;
}


}