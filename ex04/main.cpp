
#include "replace.hpp"

void    text::replace(std::string s1, std::string replace)
{
	std::string line;
	size_t pos;
	std::ifstream inFile(this->in_file);
	std::ofstream outFile(this->out_file);
	if (!outFile.is_open())
		(std::cerr << "Error opening output file!" << std::endl, exit(0));
	while (std::getline(inFile, line))
	{
		while ((pos = line.find(s1)) != std::string::npos)
		//string::npos(string::pos is a static member with its value 
		// as the highest possible for the size_t data type).
			line.replace(pos, s1.length(), replace); 
		outFile << line << std::endl;
	}
	outFile.close();
	inFile.close(); 
}
void    text::open_new_file(std::string str)
{
	this->in_file = str;
	std::ifstream file(this->in_file);
	if (!file.is_open())
		(std::cout << "Failed to open the file." << std::endl, exit(0));
	file.close();
	this->out_file = this->in_file + ".replace";
	std::ofstream new_file(this->out_file);
	if (!new_file.is_open())
		(std::cout << "Failed to open new file." << std::endl, exit(0));
	std::cout << "Opened a new file: " << this->out_file << std::endl;
	new_file.close();
}
int main(int argc, char **argv)
{
	if (argc != 4)
		(std::cout << "not right number of input" << std::endl, exit(0));
	text file;
	if (argv[1])
		file.open_new_file(argv[1]);
	file.replace(argv[2], argv[3]);
}
