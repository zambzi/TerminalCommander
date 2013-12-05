//============================================================================
// Name        : TerminalCommander.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "stdafx.h"
#include "TCApp.h"

int main() {
	static TCApp tcApp(1280,800,32);

	return tcApp.run();
}

