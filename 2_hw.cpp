#include <iostream>
#include "2_hw.h"
using namespace std;
int main() {
	CmdManager cmdManager;
	cmdManager.display_help();
	while (cmdManager.cmdProcess(cin));
	return 0;
}