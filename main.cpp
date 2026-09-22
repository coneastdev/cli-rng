#include <getopt.h>
#include <iostream>
#include <random>

#include "rng.hpp"

int main(int argc, char* argv[]) {
    // define commands
    static const option long_options[] = {
        {"help", no_argument, nullptr, 'h'},
        {"coin", optional_argument, nullptr, 'c'},
        {"dice", optional_argument, nullptr, 'd'},
        {"show", no_argument, nullptr, 's'},
        {nullptr, 0, nullptr, 0}
    };

    // seed rng
    std::random_device rd;
    std::mt19937 gen(rd());

    bool debug = false;
    int opt;
    // execute every command
    while ((opt = getopt_long(argc, argv, "hc:d:", long_options, nullptr)) != -1) {
        switch (opt) {
            case 's':
                // will enable debug mode for every subsequent command in the current call
                debug = true;
                break;
            case 'h':
                help();
                break;
            case 'c':
                std::cout << coin(argc, argv, gen, debug) << "\n";
                break;
            case 'd':
                std::cout << dice(argc, argv, gen, debug) << "\n";
                break;
            default:
                break;
        }
    }

    // print program details if no arguments are given
    if (argc < 2) {
        std::cout << "cli-rng\nv.1.2.1\nhttps://github.com/coneastdev/cli-rng\nGPL-3.0\nno warranty is given for this software\n\nuse \"--h\" or \"--help\" for help\n";
    }

    return 0;
}