#include"Parser.h"
parser::parser(std::ifstream& file) {
	std::string in_str, out_str, value_str, znach_str;
	int str_number{ 1 };
	while (std::getline(file, in_str)) {
		if (in_str.size() == 0 || in_str[0] == ';') {
		}
		else if (in_str[0] == '[' && in_str[in_str.size() - 1] == ']') {
			out_str.clear();
			for (size_t i = 0; i < in_str.size() - 1; i++) {
				if (in_str[i] != ' ' && in_str[i] != '\t' && in_str[i] != '[' && in_str[i] != ']') {
					out_str.push_back(in_str[i]);
				}
			}
			value[out_str];
		}

		else {
			if (std::count(in_str.begin(), in_str.end(), '=') == 1) {
				size_t i = 0;
				while (in_str[i] != '=') {
					if (in_str[i] != ' ' && in_str[i] != '\t') {
						value_str.push_back(in_str[i]);
					}
					i++;
				}
				i++;
				while (i < in_str.size() && in_str[i] != ';') {
					if (in_str[i] != ' ') {
						znach_str.push_back(in_str[i]);
					}
					i++;
				}
				value[out_str][value_str] = znach_str;
				value_str.clear();
				znach_str.clear();
			}
			else if (in_str.find_first_not_of(" \t") == std::string::npos) {}
			else {
				throw std::invalid_argument(std::format("некорректный синтаксис в {} строке", str_number));
			}
		}
		str_number += 1;
	}
}

