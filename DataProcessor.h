#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <vector>

class DataProcessor {
public:
    static void processRadarData(const std::vector<uint8_t>& rawData);
};

#endif // DATAPROCESSOR_H
