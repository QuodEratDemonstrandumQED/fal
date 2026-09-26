#include <vector>
#include <typeinfo>
#include <typeindex>
#include <stdexcept>


class Variable {
	void* Value;
public:
	std::type_index Type;
	template <typename T>
	Variable(T value) {
		T* heap = new T(value);
		Value = (void*)heap;
		Type = typeid(T);
	}
	template <typename T>
	operator T&() const {
		if (typeid(T) == Type) return *(T)Value;
		throw std::invalid_argument("Cast to type not accepted.");
	}
};

int main() {
	std::vector<Variable*> V;
	V.push_back(new Variable(3.0f));
	V.push_back(new Variable(true));
	return 0;
}