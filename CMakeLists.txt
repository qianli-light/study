cmake_minimum_required(VERSION 3.22)

# 交叉编译系统
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# ---------- 项目声明 ----------
set(CMAKE_PROJECT_NAME study)
project(${CMAKE_PROJECT_NAME} C CXX ASM)

message("Build type: " ${CMAKE_BUILD_TYPE})

# 标准与扩展
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# ---------- 优化与分段选项 ----------
# 不在这里硬编码 -O3，避免与构建类型的默认优化冲突（如 Debug 自动加 -O0）
# 只添加分段选项，优化级别由 CMake 按构建类型自动控制
set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS} -ffunction-sections -fdata-sections")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions -fno-rtti")

# ---------- 可执行目标 ----------
add_executable(${CMAKE_PROJECT_NAME}
        Core/Src/main.c
        Core/Src/OLED.c
        Core/Src/MY_OLED.c
        Core/Src/OLED_Data.c
)

# ---------- DSP 头文件路径 ----------
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        Drivers/CMSIS/DSP/Include
        Drivers/CMSIS/Core/Include
)

# ---------- 关键：必须定义 Cortex-M3 核心宏 ----------
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
        ARM_MATH_CM3
)

# ---------- 导入 DSP 预编译库 ----------
add_library(cmsis_dsp STATIC IMPORTED)
set_target_properties(cmsis_dsp PROPERTIES
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/Drivers/CMSIS/Lib/GCC/libarm_cortexM3l_math.a
)

# ---------- 添加 STM32CubeMX 子项目 ----------
add_subdirectory(cmake/stm32cubemx)

# ---------- 链接库 ----------
target_link_libraries(${CMAKE_PROJECT_NAME}
        stm32cubemx
        cmsis_dsp
)

# 去除不存在的 libob（ARM GCC 无此库，安全删除）
list(REMOVE_ITEM CMAKE_C_IMPLICIT_LINK_LIBRARIES ob)