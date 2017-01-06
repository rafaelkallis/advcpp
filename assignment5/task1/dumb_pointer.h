
#ifndef DUMB_POINTER_H
#define DUMB_POINTER_H

template<typename T>
class dumb_pointer {
public:
	dumb_pointer(T * ptr);
	dumb_pointer(const dumb_pointer &);
	~dumb_pointer();

	T operator* () const;
	T *operator-> () const;
private:
	T * ptr;
};

template<typename T>
dumb_pointer<T>::dumb_pointer(T * ptr) : ptr(ptr) {}

template<typename T>
dumb_pointer<T>::dumb_pointer(const dumb_pointer &copy) : ptr(copy.ptr) {}

template<typename T>
dumb_pointer<T>::~dumb_pointer() {delete ptr;}

template<typename T>
T dumb_pointer<T>::operator *() const {return * ptr;}

template<typename T>
T * dumb_pointer<T>::operator ->() const {return ptr;}

#endif