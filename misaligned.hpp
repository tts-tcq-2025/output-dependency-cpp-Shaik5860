#ifndef MISALIGNED_HPP
#define MISALIGNED_HPP

#include <vector>
#include <string>
#include <tuple>

// Generate the color mapping data
std::vector<std::tuple<int, std::string, std::string>> generateColorMap();

// Format a single color map entry as a string
std::string formatColorMapEntry(int index, const std::string& major, const std::string& minor);

// Print the color map using a provided output function (dependency injection for testability)
int printColorMap(const std::function<void(const std::string&)>& outputFunc);

#endif // COLOR_MAP_H
