#include <gtest/gtest.h>

#include "../rng.hpp"

TEST(DiceTest, UsesRequestedFaceCountAndNumberOfDice) {
    char program[] = "rng";
    char command[] = "--d";
    char faces[] = "6";
    char count[] = "3";
    char* argv[] = {program, command, faces, count};
    std::mt19937 generator(1234);

    std::string result = dice(4, argv, generator);

    EXPECT_EQ(result, "2 3 4 ");
}

TEST(CoinTest, ReturnsAValidResult) {
    char program[] = "rng";
    char command[] = "--c";
    char* argv[] = {program, command};
    std::mt19937 generator(1234);

    std::string result = coin(2, argv, generator);

    EXPECT_TRUE(result == "Heads" || result == "Tails");
}