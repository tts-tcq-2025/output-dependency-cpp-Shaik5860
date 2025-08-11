#include "misaligned.hpp"   // Your main header file
#include <gtest/gtest.h>
#include <vector>
#include <string>

// Global test capture
static std::vector<std::string> capturedLines;

// Fake output function for capturing printColorMap output
void fakeOutputFunc(const std::string& lineContent) {
    capturedLines.push_back(lineContent);
}

// Helper to generate expected output
std::vector<std::string> generateExpectedLines() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<std::string> expected;
    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            expected.push_back(
                std::to_string(index) + " | " + majorColor[i] + " | " + minorColor[j]
            );
            index++;
        }
    }
    return expected;
}

// Test: Check count of entries
TEST(ColorMapTest, CountIsCorrect) {
    capturedLines.clear();
    int result = printColorMap(fakeOutputFunc);
    EXPECT_EQ(result, 25);
}

// Test: Check each mapping line
TEST(ColorMapTest, LinesMatchExpected) {
    capturedLines.clear();
    printColorMap(fakeOutputFunc);
    auto expected = generateExpectedLines();
    EXPECT_EQ(capturedLines, expected);
}

// Test: generateColorMap data is correct
TEST(ColorMapTest, RawDataIsCorrect) {
   capturedLines.clear();
    printColorMap(fakeOutputFunc);
    EXPECT_EQ(capturedLines.size(), 25);
    EXPECT_EQ(std::get<1>(capturedLines[0]), "White"); // First major color
    EXPECT_EQ(std::get<2>(capturedLines[0]), "Blue");  // First minor color
}

