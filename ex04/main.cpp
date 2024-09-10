#include "replace.hpp"

void text::replace(std::string s1, std::string replace)
{
    std::string line;
    size_t pos;
    std::ifstream inFile(this->in_file.c_str());  // Convert std::string to const char*
    std::ofstream outFile(this->out_file.c_str());  // Convert std::string to const char*

    if (!inFile.is_open())
    {
        std::cerr << "Error opening input file!" << std::endl;
        exit(1);
    }
    
    if (!outFile.is_open())
    {
        std::cerr << "Error opening output file!" << std::endl;
        exit(1);
    }

    while (std::getline(inFile, line))
    {
        while ((pos = line.find(s1)) != std::string::npos)
        {
            line.replace(pos, s1.length(), replace);
        }
        outFile << line << '\n';  // Better to use '\n' instead of std::endl
    }

    outFile.close();
    inFile.close();
}

void text::open_new_file(std::string str)
{
    this->in_file = str;
    std::ifstream file(this->in_file.c_str());  // Convert std::string to const char*
    
    if (!file.is_open())
    {
        std::cerr << "Failed to open input file." << std::endl;
        exit(1);
    }
    file.close();

    this->out_file = this->in_file + ".replace";
    std::ofstream new_file(this->out_file.c_str());  // Convert std::string to const char*
    
    if (!new_file.is_open())
    {
        std::cerr << "Failed to open new file." << std::endl;
        exit(1);
    }
    
    std::cout << "Opened a new file: " << this->out_file << std::endl;
    new_file.close();
}


int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Incorrect number of input arguments" << std::endl;
        return 1;  // Use return instead of exit in main
    }

    text file;
    file.open_new_file(argv[1]);
    file.replace(argv[2], argv[3]);

    return 0;
}
