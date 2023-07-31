#ifndef UNIQUE_PTR_HPP
#define UNIQUE_PTR_HPP

#include <iostream>

template <typename T>
class unique_ptr{
	public:
		// constructor:
		explicit unique_ptr(T* ptr = nullptr);
		
		//destructor
		~unique_ptr();
		
		// copy constructori ve atama operatorunu devre disi birak:
		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator = (const unique_ptr&) = delete;
		
		// move const and assignment
		unique_ptr(unique_ptr&& other) noexcept;
		
		unique_ptr& operator = (unique_ptr&& other) noexcept ;
		
		//dereference operator: (isaretcinin isaret ettigi bellek adresindeki degeri elde etmek icin..)
		T& operator*() const;
		
		// member access operator 
		T* operator->() const;
		
		// get the raw pointer:
		T* get() const;
	
	private:
		T* ptr_;
};

//#include "unique_ptr.cpp"

#endif // UNIQUE_PTR_HPP
