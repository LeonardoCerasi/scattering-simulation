#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <vector>

/**
 * @brief This function returns the number of lines in a file
 *
 * @param path Path of the file
 * @return (int) Number of lines
 */
int lines(const char *path);

/**
 * @brief This function reads an input file of space-separated doubles and uploads them into a vector of vectors of doubles, one vector for each line of the file
 *
 * @param path Path of the input file
 * @param type f: Framework / p: Particle
 * @return (std::vector<std::vector<double>>) Vector of rows of doubles
 */
std::vector<std::vector<double>> read_data(const char *path, char type);

/**
 * @brief This function asks to input the order of accuracy of the simulation and outputs it on an output Ostream object
 *
 * @param output Ostream object
 * @return (double) Accuracy [s]
 */
double time_accuracy(std::ostream &output);

/**
 * @brief This function asks to input the duration of the simulation and outputs it on an output Ostream object
 *
 * @param output Ostream object
 * @return (double) Duration [s]
 */
double duration(std::ostream &output);
