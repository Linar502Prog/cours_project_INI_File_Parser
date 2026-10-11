#include"Parser.h"


int main() {
	setlocale(LC_ALL, "RUS");
	std::ifstream file("C://Users//USER//Desktop//Парсер.txt");
	try {
		if (!file.is_open()) {
			throw std::runtime_error("Ошибка открытия файла");
		}
	}
	catch (std::runtime_error& err) {
		std::cout << err.what() << std::endl;
	}
	try {
		parser Par(file);
		try {
			auto value = Par.get_value<int>("Section1.var1");
			std::cout << value << std::endl;
			auto value1 = Par.get_value<std::string>("Section4.Mod1e");
			std::cout << value1 << std::endl;
		}
		catch (std::runtime_error& err) {
			std::cout << err.what() << std::endl;
		}
	}
	catch (std::invalid_argument& err) {
		std::cout << err.what() << std::endl;
	}

	return EXIT_SUCCESS;

}