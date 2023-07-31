
#include "unique_ptr.hpp"

//constructor:
template <typename T>
unique_ptr<T>::unique_ptr(T* ptr) : ptr_(ptr) {}

// destructor:
template <typename T>
unique_ptr<T>::~unique_ptr(){
	if(ptr_){
		delete ptr_;
	}
}

// move constructor:
template <typename T>
unique_ptr<T>::unique_ptr(unique_ptr&& other) noexcept: ptr_(other.ptr_){
	other.ptr_ = nullptr;
}

// move assignment:
template <typename T>
unique_ptr<T>& unique_ptr<T>::operator = (unique_ptr&& other) noexcept{
	if(this!= &other){
		delete ptr_;
		ptr_ = other.ptr_;
		other.ptr_ = nullptr;
	}
	return *this;
}

//dereference operator
template <typename T>
T& unique_ptr<T>::operator*() const {
	return *ptr_;
}

//member access operator:

template <typename T>
T* unique_ptr<T>::operator->() const {
	return ptr_;
}

//get the raw pointer
template <typename T>
T* unique_ptr<T>::get() const {
	return ptr_;
}
