#pragma once

#include <random>
#include <string>

void help();
std::string coin(int argc, char* argv[], std::mt19937 gen, bool debug = false);
std::string dice(int argc, char* argv[], std::mt19937 gen, bool debug = false);