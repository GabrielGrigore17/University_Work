#include <memory>
#include <iostream>

struct C {
	int n;
	C(int n_) : n(n_) {}
};

int main() {
	std::shared_ptr<C> shPtr(new C(10));
	{
		std::shared_ptr<C> localPtr(shPtr);
	}
	std::shared_ptr<C> globalPtr = shPtr;
	std::cout << shPtr.use_count() << " ";
	globalPtr.reset();
	std::cout << shPtr.use_count() << std::endl;
	return 0;
}