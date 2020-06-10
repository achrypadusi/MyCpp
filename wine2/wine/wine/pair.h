#ifndef PAIR_
#define PAIR_

#include <iostream>
#include <string>
template <class T1, class T2>
class Pair
{
private:
	T1 a;
	T2 b;
public:
	T1& first();
	T2& second();
	T1 first() const { return a; }
	T2 second() const { return b; }
	Pair(const T1& aval, const T2& bval) : a(aval), b(bval) { }
	Pair() {}
	void setT1(T1);
	void setT2(T2);
};

template<class T1, class T2>
T1& Pair<T1, T2>::first()
{
	return a;
}
template<class T1, class T2>
T2& Pair<T1, T2>::second()
{
	return b;
}
template<class T1, class T2>
void Pair<T1, T2>::setT1(T1 obj)
{
	a = obj;
}
template<class T1, class T2>
void Pair<T1, T2>::setT2(T2 obj)
{
	b = obj;
}

#endif // !PAIR_