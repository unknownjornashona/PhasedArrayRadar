#ifndef RADAR_H
#define RADAR_H

#include <vector>
#include <cstdint>

class Radar {
public:
    Radar(const char* device, unsigned int baud_rate);
    ~Radar();

    bool initialize();
    std::vector<uint8_t> receiveData();

private:
    const char* device;
    unsigned int baud_rate;
    int serial_fd; // File descriptor for the serial port
};

#endif // RADAR_H
