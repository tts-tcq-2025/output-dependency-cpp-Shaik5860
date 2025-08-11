// #include <iostream>
// #include <assert.h>

// int printColorMap() {
//     const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
//     const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
//     int i = 0, j = 0;
//     for(i = 0; i < 5; i++) {
//         for(j = 0; j < 5; j++) {
//             std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
//         }
//     }
//     return i * j;
// }

// void testPrintColorMap() {
//     std::cout << "\nPrint color map test\n"; 
//     int result = printColorMap();
//     assert(result == 25);
//     std::cout << "All is well (maybe!)\n";

// }

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert>

// Shared color arrays
const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
const int majorSize = sizeof(majorColor) / sizeof(majorColor[0]);
const int minorSize = sizeof(minorColor) / sizeof(minorColor[0]);

// Function to generate color map as vector of strings
std::vector<std::string> generateColorMap() {
    std::vector<std::string> colorMap;
    int count = 1;
    for(int i = 0; i < majorSize; i++) {
        for(int j = 0; j < minorSize; j++) {
            std::ostringstream line;
            line << count << " | " << majorColor[i] << " | " << minorColor[j];
            colorMap.push_back(line.str());
            count++;
        }
    }
    return colorMap;
}

// Print color map to any output stream
int printColorMap(std::ostream &out) {
    std::vector<std::string> colorMap = generateColorMap();
    for (const auto& line : colorMap) {
        out << line << "\n";
    }
    return static_cast<int>(colorMap.size());
}

// Test function
void testPrintColorMap() {
    std::ostringstream buffer;
    int result = printColorMap(buffer); // Capture output
    std::vector<std::string> expected = generateColorMap();

    assert(result == static_cast<int>(expected.size()));

    std::istringstream actualStream(buffer.str());
    std::string actualLine;
    for (size_t i = 0; i < expected.size(); i++) {
        std::getline(actualStream, actualLine);
        assert(actualLine == expected[i] && "Color mapping mismatch!");
    }

    std::cout << "All color mappings are correct!\n";
}

int main() {
    testPrintColorMap();
    return 0;
}

