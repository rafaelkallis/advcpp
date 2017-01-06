
#ifndef SMART_POINTER_H
#define SMART_POINTER_H	

template<typename T>
class smart_pointer {
public:
	smart_pointer(T * ptr);
	smart_pointer(const smart_pointer &);
	~smart_pointer();

	int counter() const;

	T operator* () const;
	T *operator-> () const;
	smart_pointer &operator= (smart_pointer &smart_ptr);
private:
	T * ptr;
	int * n_references;

	void reference(const smart_pointer &smart_ptr);
	void dereference();
};

template<typename T>
smart_pointer<T>::smart_pointer(T * ptr) : ptr(ptr), n_references(new int(1)) {}

template<typename T>
smart_pointer<T>::smart_pointer(const smart_pointer &copy) { reference(copy); }

template<typename T>
smart_pointer<T>::~smart_pointer() {
	dereference();
}

template<typename T>
int smart_pointer<T>::counter() const {return *n_references;}

template<typename T>
T smart_pointer<T>::operator *() const {return * ptr;}

template<typename T>
T * smart_pointer<T>::operator ->() const {return ptr;}

template<typename T>
smart_pointer<T> &smart_pointer<T>::operator= (smart_pointer &smart_ptr) {
	if (ptr != smart_ptr.ptr){
		dereference();
		reference(smart_ptr);
	}
	return *this;
}

template<typename T>
void smart_pointer<T>::reference(const smart_pointer &smart_ptr) {
	ptr = smart_ptr.ptr;
	n_references = smart_ptr.n_references;
	++(*n_references);
}

template<typename T>
void smart_pointer<T>::dereference() {
	if ((--*n_references) == 0) {
		delete ptr;
	}
}

#endif