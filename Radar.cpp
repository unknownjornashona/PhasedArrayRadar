#include "Radar.h"
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>

Radar::Radar(const char* device, unsigned int baud_rate) : device(device), baud_rate(baud_rate), serial_fd(-1) {}

Radar::~Radar() {
    if (serial_fd >= 0) {
        close(serial_fd);
    }
}

bool Radar::initialize() {
    serial_fd = open(device, O_RDWR | O_NOCTTY);
    if (serial_fd < 0) {
        std::cerr << "Failed to open serial port!" << std::endl;
        return false;
    }

    struct termios options;
    tcgetattr(serial_fd, &options);
    options.c_cflag = baud_rate | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    tcflush(serial_fd, TCIFLUSH);
    tcsetattr(serial_fd, TCSANOW, &options);
    return true;
}

std::vector<uint8_t> Radar::receiveData() {
    std::vector<uint8_t> buffer(256);
    int bytes_read = read(serial_fd, buffer.data(), buffer.size());
    buffer.resize(bytes_read); // Resize to the actual number of bytes read
    return buffer;
}
