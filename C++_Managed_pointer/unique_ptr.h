#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

template <typename T>
class unique_ptr{
	public:
		explicit unique_ptr(T*ptr = nullptr) : ptr_(ptr) {}
		
		//destructor
		~unique_ptr(){
			if(ptr_){
				delete ptr_;
			}
		}
		
		// copy constructori ve atama operatorunu devre disi birak:
		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator = (const unique_ptr&) = delete;
		
		// move const and assignment
		unique_ptr(unique_ptr&& other) noexcept : ptr_(other.ptr_){
			other.ptr_ = nullptr;
		}
		
		unique_ptr& operator = (unique_ptr&& other) noexcept {
			if (this != &other){
				delete ptr_;
				ptr_ = other.ptr;
				other.ptr_=nullptr;
			}
			return *this;
		}
		
		//dereference operator: (isaretcinin isaret ettigi bellek adresindeki degeri elde etmek icin..)
		T& operator*() const{
			return *ptr_;
		}
		
		// member access operator 
		T* operator->() const{
			return ptr_;
		}
		
		// get the raw pointer:
		T* get() const{
			return ptr_;
		}
	
	private:
		T* ptr_;
};

#endif 
