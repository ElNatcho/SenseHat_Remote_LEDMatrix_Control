#include"CProgram.hpp"

int main() {
	CProgram *program = new CProgram();

	while (program->isRunning()) {
		program->run();
	}

	return 0;
}