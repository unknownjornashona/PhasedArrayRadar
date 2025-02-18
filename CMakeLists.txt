cmake_minimum_required(VERSION 3.10)

# 项目名称
project(PhasedArrayRadar VERSION 1.0)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找必要的库（如 pthread）
find_package(Threads REQUIRED)

# 源文件
set(SOURCES
    main.cpp
    Radar.cpp
    DataProcessor.cpp
)

# 创建可执行文件
add_executable(PhasedArrayRadar ${SOURCES})

# 链接线程库
target_link_libraries(PhasedArrayRadar PRIVATE Threads::Threads)

# 如果需要，也可以添加其他库的查找和链接
# find_package(OpenCV REQUIRED)
# target_link_libraries(PhasedArrayRadar PRIVATE OpenCV::Core OpenCV::ImgProc)
