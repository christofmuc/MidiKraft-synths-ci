#include "RD8.h"

#include <windows.h>

typedef  midikraft::BehringerRD8 *(*createFunctionType)();

int main() {

	HMODULE myDLL = ::LoadLibrary("midikraft-behringer-rd8.dll");

	if (myDLL) {
		auto createFn = (createFunctionType) ::GetProcAddress(myDLL, "CreateObjectInstance");

		if (createFn) {
			auto *created = (*createFn)();
			std::cout << created->getName();
		}

		::FreeLibrary(myDLL);
	}

	return 0;
}

