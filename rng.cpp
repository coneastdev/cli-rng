#include <iostream>
#include <random>
#include <getopt.h>
#include <string>
#include <ranges>

void help() {
    std::cout << "coin flip\nrng --c / rng -c [number] [number]\nRuns a coin flip, by default it is 50-50 but you can add the probability ratio\n\ndice roll\nrng --d [number] [number]\nRuns a dice roll, you need to specify the number of faces the die has, you can also specify the amount of dice to roll\n";
}

std::string coin(int argc, char* argv[], std::mt19937 gen) {
    double probability;
    if (argc == 2) {
        probability = 0.5;
    } else if (argc == 4) {
        double a = std::stoi(argv[2]);
        double b = std::stoi(argv[3]);
        double probabilityOfHeads = (a / (a + b));
        probability = probabilityOfHeads;
    }
    
    
    std::bernoulli_distribution coin(probability);
    bool result = coin(gen);

    if (result) {
        return "Heads";
    } else {
        return "Tails";
    }
}

std::string dice(int argc, char* argv[], std::mt19937 gen) {
    std::string result = "";
    int faces = 6;

    if (argc > 2) {
        faces = std::stoi(argv[2]);
    }

    std::uniform_int_distribution<int> dice(1, faces);

    int nums = 1;

    

    if (argc > 3) {
        nums = std::stoi(argv[3]);
    }

    for (int i = 0; i < nums; i++) {
        result += (std::to_string(dice(gen)) + " ");
    }

    return result;
}

int main(int argc, char* argv[]) {
    static const option long_options[] = {
        {"help", no_argument, nullptr, 'h'},
        {"coin", optional_argument, nullptr, 'c'},
        {"dice", optional_argument, nullptr, 'd'},
        {nullptr, 0, nullptr, 0}
    };

    std::random_device rd;
    std::mt19937 gen(rd());

    int opt;
    while ((opt = getopt_long(argc, argv, "hc:d:", long_options, nullptr)) != -1) {
        switch (opt) {
            case 'h':
                help();
                break;
            case 'c':
                std::cout << coin(argc, argv, gen);
                break;
            case 'd':
                std::cout << dice(argc, argv, gen);
                break;
            default:
                break;
        }
    }

    std::cout << "\n";

    return 0;
}