#ifndef PULSE_COMPRESSOR_H
#define PULSE_COMPRESSOR_H

#include <vector>
#include <complex>

class PulseCompressor {
public:
    // 构造函数
    PulseCompressor(double pulseBandwidth, double pulseDuration, int sampleRate);

    // 脉冲压缩处理
    std::vector<std::complex<double>> compress(const std::vector<std::complex<double>>& receivedSignal);

private:
    // 生成线性调频脉冲（LFM）信号
    void generateLFM();

    double bandwidth; // 脉冲带宽
    double duration;  // 脉冲持续时间
    int fs;          // 样本率
    std::vector<std::complex<double>> LFMSignal; // LFM信号
};

#endif // PULSE_COMPRESSOR_H
