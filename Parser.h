#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<algorithm>
#include <type_traits>
#include<format>
class parser {
	std::map<std::string, std::map<std::string, std::string>> value;
public:
	parser(std::ifstream& file);
	template <typename T>
	T get_value(std::string key) {
		std::string key_section, key_value;
		size_t i{ 0 };
		while (key[i] != '.') {
			if (key[i] != ' ') {
				key_section.push_back(key[i]);
			}
			i++;

		}
		i++;
		while (i < key.size()) {
			if (key[i] != ' ') {
				key_value.push_back(key[i]);
			}
			i++;
		}
		if (value.find(key_section) == value.end()) {
			throw std::runtime_error("файл некорректный");
		}
		else if (value[key_section].find(key_value) == value[key_section].end()) {
			std::cout << "Такой переменной нет. Возможно вы имели ввиду: " << std::endl;
			for (auto it = value[key_section].begin(); it != value[key_section].end();it++) {
				std::cout << it->first;
				if (std::next(it) != value[key_section].end()) {
					std::cout << ", ";
				}
				else {
					std::cout << "." << std::endl;;
				}
			}
			throw std::runtime_error("файл некорректный");
		}
		else {
			if constexpr (std::is_same_v<T, std::string>) {
				return value[key_section][key_value];
			}
			else if constexpr (std::is_same_v<T, int>) {
				return std::stoi(value[key_section][key_value]);
			}
			else {
				return std::stod(value[key_section][key_value]);

			}
		}
	}
};