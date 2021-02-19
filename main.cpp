#include <iostream>
#include <random>
#include <string>
#include <algorithm>

void sim()
{
	int iteration = 0;
	float numCorrect = 0;
	float numWrong = 0;
	float numIterations = 100000;

	while (iteration < numIterations) {
		std::random_device rd; // obtain a random number from hardware
		std::mt19937 gen(rd()); // seed the generator
		std::uniform_int_distribution<> distr(1, 3); // define the range

		int doorNum = distr(gen);
		int guessNum = distr(gen);

		int revealNum = 1;
		bool gotReveal = false;
		while (gotReveal == false)
		{
			if (revealNum != guessNum && revealNum != doorNum) {
				//std::cout << "Reveal: " << revealNum << std::endl;
				gotReveal = true;
			}
			else {
				revealNum += 1;
			}
		}

		int switchNum = 1;
		bool gotSwitch = false;
		while (gotSwitch == false)
		{
			if (switchNum != guessNum && switchNum != revealNum) {
				//std::cout << "Switch: " << switchNum << std::endl;
				gotSwitch = true;
			}
			else {
				switchNum += 1;
			}
		}

		if (switchNum == doorNum) {
			numCorrect += 1;
		}
		else {
			numWrong += 1;
		}

		//std::cout << "Door: " << doorNum << " - Switched to: " << switchNum << " - Original Guess: " << guessNum << std::endl;
		iteration += 1;
	}
	std::cout << "Correct: " << numCorrect << " - Wrong: " << numWrong << std::endl;
	float percentage = (numCorrect/ numIterations)*100;
	std::cout << "Percentage: " << percentage << "%" << std::endl;
}

int main() {
	std::cout << "Type #run to run the simulation and #quit to exit the program." << std::endl;
	std::string commmand;
	while (true)
	{
		std::cout << ">> ";
		getline(std::cin, commmand);
		std::transform(commmand.begin(), commmand.end(), commmand.begin(), [](unsigned char c) { return std::tolower(c); });
		if (commmand == "#quit") {
			std::cout << std::endl;
			std::cout << "<<====== Closing program... ======>>" << std::endl;
			break;
		}
		else if (commmand == "#run")
		{
			std::cout << "<<====== Simulating... ======>>" << std::endl;
			sim();
		}
	}

	return 0;
}