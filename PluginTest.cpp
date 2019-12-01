#include "RD8.h"

#include "JuceHeader.h"

typedef  midikraft::BehringerRD8 *(*createFunctionType)();
typedef  void (*deleteFunctionType)(midikraft::BehringerRD8 *);

int main() {

	DynamicLibrary rd8_plugin("RD8");

	if (rd8_plugin.open("midikraft-behringer-rd8.dll")) {
		auto createFn = (createFunctionType)rd8_plugin.getFunction("CreateObjectInstance");

		if (createFn) {
			auto *created = (*createFn)();
			std::cout << created->getName();

			auto deleteFn = (deleteFunctionType)rd8_plugin.getFunction("ReleaseObject");

			if (deleteFn) {
				(*deleteFn)(created);
			}
		}

		rd8_plugin.close();
	}

	return 0;
}

