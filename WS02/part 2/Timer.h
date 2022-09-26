///////////////////////////////////////////////////
// WorkShop#2 :  Part2
// Full Name  :  Xiaoyue Zhao
// Student ID :  124899212
// Email      :  xzhao109@myseneca.ca
// Section    :  ZEE
// Date       :  Sep 25
///////////////////////////////////////////////////

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>
#include <iostream>

namespace sdds {
class Timer {
    using Clock = std::chrono::steady_clock;
    using NanoSeconds = std::chrono::nanoseconds;

    std::chrono::time_point<Clock> m_start_time;
    std::chrono::time_point<Clock> m_end_time;

   public:
    void start();
    long long stop();
};
}  // namespace sdds

#endif