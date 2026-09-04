# For array/vector comparison with numpy

#bare-metal / low-level RTOS
#    ↓
# C arrays
# C structs
# fixed buffers
# pointers
# static memory
#         ↓
# embedded C++
#     ↓
# std::array
# classes
# const &
# templates used carefully
# fixed-size ownership
#         ↓
# micro-ROS / rclcpp-facing code
#     ↓
# C++ objects
# messages
# callbacks
# nodes
# publishers/subscribers

## C/c++ language needed info
# myMath.h
#     #include <array>       ← when its declarations need std::array

# myMath.cpp
#     #include "myMath.h"
#     #include <iostream>    ← implementation uses std::cout

# main1.cpp
#     #include "myMath.h"
#     #include <iostream>    ← only if main uses std::cout