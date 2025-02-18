#include "PulseCompressor.h"
#include <cmath>
#include <iostream>

// 构造函数
PulseCompressor::PulseCompressor(double pulseBandwidth, double pulseDuration, int sampleRate)
    : bandwidth(pulseBandwidth), duration(pulseDuration), fs(sampleRate) {
    generateLFM(); // 生成LFM信号
}

// 生成线性调频脉冲（LFM）信号
void PulseCompressor::generateLFM() {
    int numSamples = static_cast<int>(fs * duration);
    LFMSignal.resize(numSamples);
    double k = bandwidth / duration; // 频率调制率

    for (int n = 0; n < numSamples; ++n) {
        double t = static_cast<double>(n) / fs;
        LFMSignal[n] = std::exp(std::complex<double>(0, M_PI * k * t * t));
    }
}

// 脉冲压缩处理
std::vector<std::complex<double>> PulseCompressor::compress(const std::vector<std::complex<double>>& receivedSignal) {
    int numSamples = receivedSignal.size();
    std::vector<std::complex<double>> compressedSignal(numSamples, 0);

    for (int n = 0; n < numSamples; ++n) {
        for (int m = 0; m < LFMSignal.size(); ++m) {
            if (n - m >= 0) {
                compressedSignal[n] += receivedSignal[n - m] * std::conj(LFMSignal[m]);
            }
        }
    }
    return compressedSignal;
}
