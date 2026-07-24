# ROS 2 Learning Agenda: From Turtlesim to System Architecture

*Peter Chang*

## 1. Purpose

This document reframes the ROS 2 turtlesim tutorial into a **system-level teaching module**.

Goal:

* Move students from "running demos" → "understanding systems"
* Bridge: MATLAB ↔ ROS 2 ↔ Embedded (STM32)
* Teach layered thinking, not just API usage

---

## 2. Core Insight

Most beginners think turtlesim teaches:

* keyboard control

But it actually teaches:

```text
Human input
↓
Node
↓
Publish message
↓
Topic
↓
Subscriber node
↓
System behavior
```

This is the **ROS 2 communication model**.

---

## 3. Key Concepts

### 3.1 Nodes

* Independent processes
* Communicate through topics/services/actions

### 3.2 Topics

* Message channels
* Decoupled communication

### 3.3 Messages

Example:

* `geometry_msgs/Twist`

```text
Linear velocity
Angular velocity
```

These define the "language" of the robot.

---

## 4. Client Libraries

Two main ROS 2 client libraries:

* rclpy → Python
* rclcpp → C++

They allow you to:

* create nodes
* publish/subscribe
* implement logic

They are:

> The bridge between your code and ROS 2 middleware

---

## 5. What Turtlesim Actually Teaches

### Step 1: Observe system

```bash
ros2 topic list
ros2 node list
ros2 topic echo /turtle1/pose
```

### Step 2: Understand message flow

```text
teleop_key
→ publishes Twist
→ /turtle1/cmd_vel
→ turtlesim subscribes
→ turtle moves
```

### Step 3: Replace input source

Keyboard is NOT special.

Can be replaced by:

* Python node
* MATLAB
* joystick
* AI

---

## 6. Transition to rclpy

Students must move from:

> Using ROS

to:

> Writing ROS nodes

Example:

```python
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class Controller(Node):
    def __init__(self):
        super().__init__('controller')
        self.pub = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
```

---

## 7. System Layer Architecture

```text
Application logic
↓
Python / MATLAB
↓
ROS 2 nodes (rclpy / rclcpp)
↓
DDS middleware
↓
Linux / drivers
↓
STM32 / Arduino
↓
PWM / sensors / motors
```

Key teaching focus:

> message → node → timing → hardware consequence

---

## 8. Modern vs Traditional Engineering

### Traditional (Windows-centric)

* GUI tightly coupled
* C++ / C# / DLL
* direct hardware handling

### Modern (ROS + Python)

* distributed nodes
* message-based communication
* rapid prototyping

BUT:

Low-level still matters:

* RTOS
* HAL
* timing
* memory

---

## 9. Role of Python

Python enables:

* fast integration
* glue logic
* rapid testing

But is NOT the whole system:

```text
Python → C++ → Driver → Firmware → Hardware
```

---

## 10. Teaching Strategy

### Problem

Students can:

* glue code quickly

But lack:

* system understanding
* debugging ability

### Solution

Teach layered system thinking

---

## 11. Core Teaching Pipeline

### Stage 1: Concept (Turtlesim)

```text
teleop_key → Twist → turtlesim
```

---

### Stage 2: Programming (rclpy)

```text
Python node → publish Twist → turtlesim
```

---

### Stage 3: Integration

```text
PS4 / MATLAB
→ rclpy node
→ Twist
→ ROS system
```

---

### Stage 4: Hardware Extension

```text
ROS2 node
→ velocity command
→ STM32
→ PWM
→ motor
```

---

## 12. Example Full Pipeline

```text
Joystick
↓
Python (rclpy)
↓
Twist message
↓
ROS2 network
↓
Motor control node
↓
STM32
↓
Robot movement
```

---

## 13. Key Teaching Philosophy

> Not just “how to use tools”

But:

> “How systems are connected and why they work”

---

## 14. Instructor Role

Modern students:

* strong at using tools
* fast at prototyping

Instructor value:

> Turn quick glue into reliable engineering systems

---

## 15. Final Takeaway

Turtlesim is NOT a toy.

It is:

> The smallest complete example of a distributed robotic system

If understood correctly, it leads directly to:

* ROS2 system design
* MATLAB integration
* embedded deployment

---

## 16. Next Steps

* Implement custom rclpy node
* Replace keyboard input
* Connect MATLAB ROS Toolbox
* Extend to STM32 control

---

End of document
