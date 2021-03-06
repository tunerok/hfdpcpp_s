#ifndef	_HFDP_CPP_COMPOUND_ADAPTER_MALLARD_DUCK_HPP_
#define _HFDP_CPP_COMPOUND_ADAPTER_MALLARD_DUCK_HPP_

#include "DuckSimulator.hpp"

namespace HeadFirstDesignPatterns {
namespace Compound {
namespace Adapter {

class MallardDuck : public Quackable {

	public: void quack() const {
		std::cout << "Quack" << std::endl;
	}
};

} // namespace Adapter
} // namespace Compound
} // namespace HeadFirstDesignPatterns

#endif