#include <random>
#include <string>
#include <iostream>
#include "rng.hpp"

// help, shows commands, how to run them and what they do
void help() {
    std::cout << "(show)\nrng --s / rng --s [command]\nDisplays debug information\n\n(coin flip)\nrng --c / rng -c [number] [number]\nRuns a coin flip, by default it is 50-50 but you can add the probability ratio\n\n(dice roll)\nrng --d [number] [number]\nRuns a dice roll, you can specify the number of faces the die has, you can also specify the amount of dice to roll.\nIf the face number is left blank it will default to 6, if dice count is blank it will default to 1\n";
}

// coin, returns heads or tails based on probability and input
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

// dice, returns a string of 1 or more dice rolls based on input
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
