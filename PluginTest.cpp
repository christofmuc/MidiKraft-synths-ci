/*
   Copyright (c) 2019 Christof Ruch. All rights reserved.

   Dual licensed: Distributed under Affero GPL license by default, an MIT license is available for purchase
*/

#include "RD8Plugin.h"

#include "JuceHeader.h"

int main() {

	RD8Plugin rd8_plugin;

	auto created = rd8_plugin.create();
	std::cout << created->getName();
	rd8_plugin.destroy(created);

	return 0;
}

