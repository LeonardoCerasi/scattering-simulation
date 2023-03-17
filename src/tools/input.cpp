#include "tools/input.h"

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

std::vector<std::vector<double>> read_data(const char *path, char type)
{
    // number of lines in input file
    int n = lines(path);

    // number of doubles per row
    int d = 0;
    if (type == 'f')
    {
        d = 12;
    }
    else if (type == 'p')
    {
        d = 10;
    }

    std::ifstream input;
    input.open(path);

    if (!input)
    {
        std::cout << "Error during input file opening" << std::endl;
        return {{-1}};
    }

    // initialize returned vector
    std::vector<std::vector<double>> result;

    for (int i = 0; i < n; i++)
    {
        // initialize support vector
        std::vector<double> support;

        // initialize support double
        double value;

        // frameworks are defined by 12 parameters
        for (int j = 1; j <= d; j++)
        {
            input >> value;
            support.push_back(value);
        }

        result.push_back(support);
    }

    input.close();
    return result;
}
