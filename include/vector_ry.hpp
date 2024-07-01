#ifndef VECTOR_RY_HPP
#define VECTOR_RY_HPP

#include <memory> // for std::allocator

namespace ry_stl{

template <typename T,typename Alloc = std::allocator<T>>
class vector_ry{
	//类型定义
public:
	using value_type = T;
	using allocator_type = Alloc;
	using size_type = std::size_t;
	using difference_type = std::ptrdiff_t;
	using reference = value_type&;
	using const_reference = const value_type&;
	using pointer = typename std::allocator_traits<allocator_type>::pointer;
	

	//构造函数
	vector_ry();
	explicit vector_ry(size_type n);

	//析构函数
	~vector_ry();

	//容量相关函数
	size_type size() const noexcept;
	size_type capacity() const noexcept;
	bool empty() const noexcept;
	void reserve(size_type new_cap);
	
	// 元素访问函数
    reference operator[](size_type pos);
    const_reference operator[](size_type pos) const;

    // 修改器函数
    void push_back(const value_type& val);
    void pop_back();

private:
    allocator_type allocator_;
    pointer data_;
    size_type size_;
    size_type capacity_;

    void reallocate(size_type new_cap);
};
}


#endif //VECTOR_RY_HPP