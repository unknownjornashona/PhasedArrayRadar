#ifndef DOPPLER_PROCESSING_H
#define DOPPLER_PROCESSING_H

class DopplerProcessing {
public:
    DopplerProcessing(double frequency, double speed_of_sound);
    
    // 计算多普勒频移
    double calculateDopplerShift(double relative_speed);
    
    // 判断目标的分类
    const char* classifyTarget(double speed);
    
private:
    double frequency;        // 信号频率
    double speed_of_sound;   // 声速
};

#endif // DOPPLER_PROCESSING_H
