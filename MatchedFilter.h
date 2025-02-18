#ifndef MATCHED_FILTER_H
#define MATCHED_FILTER_H

#include <vector>

class MatchedFilter {
public:
    // 构造函数，接受参考信号
    MatchedFilter(const std::vector<double>& reference_signal);
    
    // 执行匹配滤波
    std::vector<double> apply(const std::vector<double>& input_signal);

private:
    std::vector<double> reference_signal; // 参考信号
};

#endif // MATCHED_FILTER_H
