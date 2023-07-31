#include "unique_ptr.h"

// destructor:
template <typename T>
unique_ptr<T>::~unique_ptr(){
	if(ptr_){
		delete ptr_;
	}
}

// move constructor:
template <typename T>
unique ptr<T>::unique_ptr(unique_ptr<T>&& other) noexcept: ptr(other.ptr_){
	other.ptr_ = nullptr;
}

// move assignment:
template <typename T>
unique_ptr<T>& unique_ptr<T>::operator = (unique_ptr<T>&& other) noexcept{
	if(this!= &other){
		delete ptr;
		ptr_ = other.ptr_;
		other.ptr_ = nullptr;
	}
	return *this;
}

//dereference operator
template <typename T>
T& unique_ptr<T>::operator*() const{
	return *ptr_;
}

//member access operator:

template <typename T>
T* unique_ptr<T>:: operator ->() const{
	return ptr_;
}
template <typename T>
T* unique_ptr<T>::get() const{
	return ptr_;
}
