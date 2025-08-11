#ifndef MISALIGNED_HPP
#define MISALIGNED_HPP

#include <vector>
#include <string>
#include <tuple>



// Print the color map using a provided output function (dependency injection for testability)
int printColorMap(const std::function<void(const std::string&)>& outputFunc);

#endif // COLOR_MAP_H
