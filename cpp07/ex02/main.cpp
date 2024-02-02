#include "Array.hpp"

int main(void) {
	std::cout << GREEN << "------ Test 1: empty array ------" << RESET << std::endl;
	std::cout << YELLOW << "Creating empty array" << RESET << std::endl;
	Array<int> empty;
	std::cout << YELLOW << "Accessing empty array" << RESET << std::endl;
	std::cout << "\tSize: " << empty.size() << std::endl;
	try {
		std::cout << YELLOW << "Trying to access index 0: " << RESET << empty[0] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << GREEN << "------ Test 2: array of 5 ints ------" << RESET << std::endl;
	std::cout << YELLOW << "Creating array of 5 ints" << RESET << std::endl;
	Array<int> five(5);
	std::cout << YELLOW << "Accessing five array" << RESET << std::endl;
	std::cout << "\tSize: " << five.size() << std::endl;
	for (int i = 0; i < five.size(); i++)
		five[i] = i;
	for (int i = 0; i < five.size(); i++)
		std::cout << "\tfive[" << i << "]: " << five[i] << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "------ Test 3: array of 5 strings ------" << RESET << std::endl;
	std::cout << YELLOW << "Creating array of 5 strings" << RESET << std::endl;
	Array<std::string> strings(5);
	std::cout << YELLOW << "Accessing strings array" << RESET << std::endl;
	std::cout << "\tSize: " << strings.size() << std::endl;
	strings[0] = "Test";
	strings[1] = "3: ";
	strings[2] = "array";
	strings[3] = "of";
	strings[4] = "strings.";
	for (int i = 0; i < strings.size(); i++)
		std::cout << "\tstrings[" << i << "]: " << strings[i] << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "------ Test 4: copy constructor ------" << RESET << std::endl;
	std::cout << YELLOW << "Creating copy array" << RESET << std::endl;
	Array<std::string> copy(strings);
	std::cout << YELLOW << "Accessing copy array" << RESET << std::endl;
	std::cout << "\tSize: " << copy.size() << std::endl;
	for (int i = 0; i < copy.size(); i++)
		std::cout << "\tcopy[" << i << "]: " << copy[i] << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "------ Test 5: assignment operator ------" << RESET << std::endl;
	std::cout << YELLOW << "Creating assign array" << RESET << std::endl;
	Array<std::string> assign;
	assign = strings;
	std::cout << YELLOW << "Accessing assign array" << RESET << std::endl;
	std::cout << "\tSize: " << assign.size() << std::endl;
	for (int i = 0; i < assign.size(); i++)
		std::cout << "\tassign[" << i << "]: " << assign[i] << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "------ Test 6: OutOfBoundsException ------" << RESET << std::endl;
	std::cout << YELLOW << "Trying to access index 5: " << RESET << std::endl;
	try {
		std::cout << "\t" << strings[5] << std::endl;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}