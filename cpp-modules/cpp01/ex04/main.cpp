#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, const char **argv)
{   
    if (argc == 4)
    {
        size_t          size;
        std::ifstream   infile;
        std::ofstream   outfile;
        std::string     replace_file;
        std::string     s1;
        std::string     s2;
        std::string     buffer;

        replace_file = argv[1];
        replace_file.append(".replace");
        s1 = argv[2];
        s2 = argv[3];
        infile.open(argv[1]);
        if (infile)
        {
            infile.seekg(0, std::ios::end);
            size = infile.tellg();
            buffer.resize(size, ' ');
            infile.seekg(0);
            infile.read(&buffer[0], size);
            infile.close();
            for (size_t i = buffer.find(s1); i != std::string::npos; i = buffer.find(s1, i + 1))
            {
                buffer.erase(i, s1.length());
                buffer.insert(i, s2);
            }
        }
        else
        {
            std::cout << "[ERROR]: Can't open file!" << std::endl;
            return (1);   
        }
        outfile.open(replace_file);
        if (outfile)
            outfile << buffer;
        else
        {
            std::cout << "[ERROR]: Can't open file!"  << std::endl;
            return (1);
        }
        outfile.close();
        return (0);
    }
    else
    {
        std::cout << "Invalid number of arguments!" << std::endl;
        return (1);   
    }
    return (1);
}