#include "DataProcessor.h"
#include <iostream>

void DataProcessor::processRadarData(const std::vector<uint8_t>& rawData) {
    // 简单的数据处理逻辑: 此处可以插入目标检测算法
    std::cout << "Processing radar data: ";
    for (const auto& byte : rawData) {
        std::cout << static_cast<int>(byte) << " "; // Print each byte
    }
    std::cout << std::endl;
}
