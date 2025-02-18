#include "MatchedFilter.h"

// 构造函数实现
MatchedFilter::MatchedFilter(const std::vector<double>& reference_signal) 
    : reference_signal(reference_signal) {}

// 执行匹配滤波的实现
std::vector<double> MatchedFilter::apply(const std::vector<double>& input_signal) {
    size_t input_size = input_signal.size();
    size_t ref_size = reference_signal.size();
    std::vector<double> output_signal(input_size + ref_size - 1, 0.0);

    // 进行卷积操作
    for (size_t n = 0; n < input_size + ref_size - 1; ++n) {
        for (size_t k = 0; k < ref_size; ++k) {
            if (n >= k && n - k < input_size) {
                output_signal[n] += input_signal[n - k] * reference_signal[k];
            }
        }
    }

    return output_signal;
}
