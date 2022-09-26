///////////////////////////////////////////////////
// WorkShop#2 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Sep 25
///////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include "Timer.h"

namespace sdds {
void Timer::start() {
    m_start_time = Clock::now();
}
long long Timer::stop() {
    m_end_time = Clock::now();
    return std::chrono::duration_cast<NanoSeconds>(m_end_time - m_start_time).count();
}
}  // namespace sdds