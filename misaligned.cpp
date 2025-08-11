#include <iostream>
#include <assert.h>

std::vector<std::tuple<int, std::string, std::string>> generateColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    std::vector<std::tuple<int, std::string, std::string>> colorMap;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            colorMap.emplace_back(i * 5 + j, majorColor[i], minorColor[i]);
        }
    }
    return colorMap;
}

std::string formatColorMapEntry(int index, const std::string& major, const std::string& minor) {
    return std::to_string(index) + " | " + major + " | " + minor;
}

void printOnConsole(std::string& lineContent){
      std::cout<<lineContent<<std::endl;
}
int printColorMap(const std::function<void(const std::string&)>& outputFunc) {
    auto colorMap = generateColorMap();
    for (const auto& [index, major, minor] : colorMap) {
        outputFunc(formatColorMapEntry(index, major, minor));
    }
    return static_cast<int>(colorMap.size());
}

std::vector<std::tuple<int, std::string, std::string>> generateExpectedLines() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

    std::vector<std::tuple<int, std::string, std::string>> expectedLines;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            expected.push_back(formatColorMapEntry(i * 5 + j, majorColor[i], minorColor[j]));
        }
    }
    return expectedLines;
}
/* TEST Environment */
vector<string&> capturedLines;
void fakeOutputFunc(std::string& lineContent){
    capturedLines.push_back(lineContent);
}
void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    int result = printColorMap(fakeOutputFunc); 
    assert(result == 25);//value based test
    // Content-based test — should FAIL because of the bug
    auto expectedLines = generateExpectedLines();
    assert(capturedLines==expectedLines);
    std::cout << "All is well (maybe!)\n";
}


int main() {
    testPrintColorMap();
    return 0;
}



