#include "DopplerProcessing.h"

// 构造函数
DopplerProcessing::DopplerProcessing(double frequency, double speed_of_sound) 
    : frequency(frequency), speed_of_sound(speed_of_sound) {}

// 计算多普勒频移
double DopplerProcessing::calculateDopplerShift(double relative_speed) {
    return frequency * (speed_of_sound / (speed_of_sound - relative_speed));
}

// 判断目标的分类
const char* DopplerProcessing::classifyTarget(double speed) {
    if (speed < 20) {
        return "低速目标";
    } else if (speed < 100) {
        return "中速目标";
    } else {
        return "高速目标";
    }
}
