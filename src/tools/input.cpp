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

double time_accuracy(std::ostream &output)
{
    // input time accuracy's exponent
    int exp;
    std::cout << "\nTime accuracy [s]: 10^-";
    std::cin >> exp;

    // effective time accuracy
    double delta_t = pow(10, -exp);

    // output time accuracy on log file
    output << "\nThe simulation has a time accuracy of " << delta_t << " [s]\n"
           << std::endl;

    return delta_t;
}

double duration(std::ostream &output)
{
    // input duration
    double duration;
    std::cout << "\nThe simulation runs from 0 to: ";
    std::cin >> duration;

    // output duration on log file
    output << "\nThe simulation runs from 0 to " << duration << " [s]\n"
           << std::endl;

    return duration;
}
