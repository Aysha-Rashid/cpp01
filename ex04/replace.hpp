#ifndef REPLACE_HPP
#define REPLACE_HPP
#include <string.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
class   text
{
	private:
		std::string in_file;
		std::string out_file;
	public:
	void    open_new_file(std::string);
	void    replace(std::string s1, std::string replace);
};

#endif