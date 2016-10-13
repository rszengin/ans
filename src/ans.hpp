/*
 * ans.hpp
 *
 *  Created on: 6 Eki 2016
 *      Author: RSZ
 */

#ifndef ANS_HPP_
#define ANS_HPP_

#include <string>
#include <cstring>

namespace nonstd {

template<typename T>
class Ans {
public:

	T recent;
	bool result;

	Ans() : recent(T {}), result(true) {}
	Ans(const T& rcnt) : recent(rcnt), result(true) {}
	~Ans() {}

	Ans& operator =(const T& rcnt) {
		recent = rcnt;
		result = true;
		return *this;
	}


	/*
	 * Comparison type : Ans<T> @ T
	 * (@ denotes comparison operator)
	 */
	Ans& operator <(const T& rhs) {
		result = result && (recent < rhs);
		recent = rhs;
		return *this;
	}

	Ans& operator <=(const T& rhs) {
		result = result && (recent <= rhs);
		recent = rhs;
		return *this;
	}

	Ans& operator >(const T& rhs) {
		result = result && (recent > rhs);
		recent = rhs;
		return *this;
	}

	Ans& operator >=(const T& rhs) {
		result = result && (recent >= rhs);
		recent = rhs;
		return *this;
	}


	/*
	 * Comparison type : Ans<T> @ Ans<T>
	 * (@ denotes comparison operator)
	 */
	Ans& operator <(Ans<T>&& rhs) {
		result = result && rhs.result && (recent < rhs.recent);
		recent = rhs.recent;
		return *this;
	}

	Ans& operator <=(Ans<T>&& rhs) {
		result = result && rhs.result && (recent <= rhs.recent);
		recent = rhs.recent;
		return *this;
	}

	Ans& operator >(Ans<T>&& rhs) {
		result = result && rhs.result && (recent > rhs.recent);
		recent = rhs.recent;
		return *this;
	}

	Ans& operator >=(Ans<T>&& rhs) {
		result = result && rhs.result && (recent >= rhs.recent);
		recent = rhs.recent;
		return *this;
	}


	/*
	 * Comparison type : T @ Ans<T>
	 * (@ denotes comparison operator)
	 */
	friend Ans<T> operator <(const T& lhs, Ans<T>&& rhs) {
		rhs.result = rhs.result && (lhs < rhs.recent);
		return rhs;
	}

	friend Ans<T> operator <=(const T& lhs, Ans<T>&& rhs) {
		rhs.result = rhs.result && (lhs <= rhs.recent);
		return rhs;
	}

	friend Ans<T> operator >(const T& lhs, Ans<T>&& rhs) {
		rhs.result = rhs.result && (lhs > rhs.recent);
		return rhs;
	}

	friend Ans<T> operator >=(const T& lhs, Ans<T>&& rhs) {
		rhs.result = rhs.result && (lhs >= rhs.recent);
		return rhs;
	}


	/*
	 * Required for finalization
	 */
	operator bool() {
		return result;
	}
};


// Convenience function
template<typename T>
inline Ans<T> ans(T lhs) {
	return Ans<T> {lhs};
}

} /* namespace nonstd */

#endif /* ANS_HPP_ */
