#ifndef VirtualMachine
#define VirtualMachine

#include <cstdint>

namespace VM {
	uint8_t Registers[8];
	uint8_t RAM[65536];
}

#endif // VM