#include "Radar.h"
#include "DataProcessor.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <device> <baud_rate>" << std::endl;
        return 1;
    }

    const char* device = argv[1];
    unsigned int baud_rate = static_cast<unsigned int>(std::stoi(argv[2]));

    Radar radar(device, baud_rate);

    if (!radar.initialize()) {
        return 1;
    }

    while (true) {
        auto data = radar.receiveData();
        if (!data.empty()) {
            DataProcessor::processRadarData(data);
        }
        // 可以添加适当的延迟
    }

    return 0;
}
