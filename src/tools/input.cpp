#include "input.h"

int lines(const char *path)
{
    std::ifstream input;
    input.open(path);

    if (!input)
    {
        std::cout << "Error during input file opening" << std::endl;
        return -1;
    }

    std::string line;
    int lines = 0;

    getline(input, line);

    while (!input.eof())
    {
        lines++;
        getline(input, line);
    }

    input.close();

    return lines;
}
