#include <iostream>
#include <random>
#include <getopt.h>
#include <string>
#include <ranges>

void help() {
    std::cout << "(coin flip)\nrng --c / rng -c [number] [number]\nRuns a coin flip, by default it is 50-50 but you can add the probability ratio\n(dice roll)\nrng --d [number] [number]\nRuns a dice roll, you can specify the number of faces the die has, you can also specify the amount of dice to roll.\nIf the face number is left blank it will default to 6, if dice count is blank it will default to 1\n";
}

std::string coin(int argc, char* argv[], std::mt19937 gen, bool debug) {
    double probability;
    if (argc == 2 || (argc == 3 && debug)) {
        probability = 0.5;
    } else if (argc == 4) {
        double a = std::stoi(argv[2]);
        double b = std::stoi(argv[3]);
        double probabilityOfHeads = (a / (a + b));
        probability = probabilityOfHeads;
    } else if (argc == 5 && debug) {
        double a = std::stoi(argv[3]);
        double b = std::stoi(argv[4]);
        double probabilityOfHeads = (a / (a + b));
        probability = probabilityOfHeads;
    }
    
    
    
    std::bernoulli_distribution coin(probability);
    bool result = coin(gen);

    if (debug) {
        std::cout << ("probability of heads: " + std::to_string(probability) + "\n");
    }

    if (result) {
        return "Heads";
    } else {
        return "Tails";
    }
}

std::string dice(int argc, char* argv[], std::mt19937 gen, bool debug) {
    std::string result = "";
    int faces = 6;

    // check if faces is specified
    if (argc > 3 && debug) {
        faces = std::stoi(argv[3]);
    } else if (argc > 2 && !debug) {
        faces = std::stoi(argv[2]);
    }
    

    std::uniform_int_distribution<int> dice(1, faces);

    int nums = 1;

    // check if dice count is specified
    if (argc > 4 && debug) {
        nums = std::stoi(argv[4]);
    } else if (argc > 3 && !debug) {
        nums = std::stoi(argv[3]);
    }
    
    for (int i = 0; i < nums; i++) {
        result += (std::to_string(dice(gen)) + " ");
    }

    if (debug) {
        std::cout << ("faces: " + std::to_string(faces) + ", dices: " + std::to_string(nums) + "\n");
    }

    return result;
}

int main(int argc, char* argv[]) {
    static const option long_options[] = {
        {"help", no_argument, nullptr, 'h'},
        {"coin", optional_argument, nullptr, 'c'},
        {"dice", optional_argument, nullptr, 'd'},
        {"show", no_argument, nullptr, 's'},
        {nullptr, 0, nullptr, 0}
    };

    std::random_device rd;
    std::mt19937 gen(rd());

    bool debug = false;

    int opt;
    while ((opt = getopt_long(argc, argv, "hc:d:", long_options, nullptr)) != -1) {
        switch (opt) {
            case 's':
                debug = true;
                break;
            case 'h':
                help();
                break;
            case 'c':
                std::cout << coin(argc, argv, gen, debug);
                std::cout << "\n";
                break;
            case 'd':
                std::cout << dice(argc, argv, gen, debug);
                std::cout << "\n";
                break;
            default:
                break;
        }
    }

    if (argc < 2) {
        help();
    }

    return 0;
}