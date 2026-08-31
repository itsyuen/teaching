# Midterm Design — Integrated Robotics Architecture

## Computer Integrated Control Systems

### Purpose

The midterm should test whether students understand a **complete robotic system architecture**, rather than whether they can memorize isolated ROS 2 commands, Python syntax, or hardware terminology.

The central question is:

> Can the student trace information and commands through an entire robotic system—from high-level software and sensing, through ROS 2 and communication, into MCU/RTOS firmware and low-level motor control, and then trace sensor feedback back upward?

This makes the midterm not only an assessment, but also a **specification for the first half of the course**.

---

## 1. Course-design philosophy: design the questions first

A useful development sequence is:

**Architecture → Midterm Questions → Required Concepts → Lectures → Demonstrations/Labs → Midterm**

The principle is simple:

> **Teach first, then quiz what was taught.**

Designing the question bank early helps identify the concepts that must be explicitly connected in the lecture slides.

A useful alignment check is:

**Question → Concept → Lecture → Demonstration → Lab → Midterm**

If a midterm question has no corresponding lecture or learning activity, either:

- teach the concept clearly before the exam, or
- remove/revise the question.

Likewise, if substantial lecture material never contributes to a later concept, exercise, laboratory, or assessment, reconsider how much class time it deserves.

---

## 2. Central robotics architecture

```text
                    HIGH-LEVEL COMPUTING
                ┌─────────────────────────┐
                │ Planning / Navigation   │
                │ Python / C++            │
                │ ROS 2 Nodes             │
                └────────────┬────────────┘
                             │
                    ROS 2 / DDS messages
                             │
                ┌────────────▼────────────┐
                │ Robot Control Layer     │
                │ trajectory/controller  │
                │ kinematics/transforms  │
                └────────────┬────────────┘
                             │
                    CAN / UART / USB
                    Ethernet / micro-ROS
                             │
                ┌────────────▼────────────┐
                │ MCU + RTOS Firmware     │
                │ tasks / timers / ISR    │
                │ control loop            │
                └────────────┬────────────┘
                             │
                       PWM / GPIO / ADC
                             │
                ┌────────────▼────────────┐
                │ Motor Driver            │
                │ H-bridge / inverter     │
                └────────────┬────────────┘
                             │
                     voltage / current
                             │
                ┌────────────▼────────────┐
                │        MOTOR            │
                └────────────┬────────────┘
                             │
                       mechanical motion
                             │
                      encoder / sensor
                             │
                ┌────────────▼────────────┐
                │ MCU measurement         │
                │ feedback controller     │
                └────────────┬────────────┘
                             │
                    feedback toward ROS 2
```

Students should eventually be able to explain this chain without treating Python, ROS 2, RTOS, CAN, PWM, motors, and sensors as unrelated subjects.

---

## 3. Proposed 100-point midterm structure

| Area | Approx. Questions | Main Understanding Tested |
|---|---:|---|
| Robotics system architecture | 5 | Hardware/software/firmware boundaries |
| Motors, encoders & low-level control | 5 | PWM, current, velocity, position, feedback |
| MCU, firmware & RTOS | 5 | Tasks, timing, interrupts, deterministic control |
| Communication | 5 | UART, CAN, USB, Ethernet, messages and interfaces |
| ROS 2 architecture | 6 | Nodes, topics, messages, services/actions, DDS |
| Python/OOP/data structures | 4 | Objects, classes, lists/dictionaries and data representation |
| Simulation | 4 | URDF, Gazebo, RViz, simulated sensors/controllers |
| Integrated system scenarios | 6 | Complete command and feedback paths |
| **Total** | **40** | **100 points** |

Before selecting the final 40 questions, develop a larger **50–60 question candidate bank**. The candidate questions can then determine the final lecture scope and emphasis.

---

## 4. Questions should test relationships, not trivia

Instead of asking only:

> What does PWM stand for?

ask:

> A ROS 2 navigation node calculates a desired wheel velocity of 8 rad/s. Which sequence best represents how that command could ultimately cause a DC motor to rotate?

A. ROS 2 topic → encoder → PWM → Python → motor  
B. ROS 2 node → velocity command → MCU/RTOS control task → PWM/motor controller → driver → motor  
C. ROS 2 node → Gazebo → DDS → encoder → motor  
D. Python dictionary → CAN → RViz → PWM → motor

**Answer: B**

One question can therefore test several connected concepts at once.

---

## 5. Four levels of questions

### Level 1 — Component knowledge

Examples:

- What is an encoder?
- What is PWM?
- What is a ROS 2 node?
- What is an RTOS task?

### Level 2 — Relationships

Example:

> Why should a fast motor-current controller generally not be implemented as an ordinary non-real-time Python ROS 2 loop?

This tests timing, determinism, firmware, and software-layer boundaries.

### Level 3 — Architecture

Example:

> Where should the wheel velocity controller execute, and how should the high-level ROS 2 system provide its reference command?

### Level 4 — Diagnosis

Example:

> ROS 2 reports a velocity command, encoder data is arriving, and PWM is changing, but the wheel does not move. Which part of the architecture should be investigated next?

These diagnostic questions reveal whether students have developed actual **systems thinking**.

---

## 6. RTOS concepts should be connected to control requirements

Example question:

> A motor velocity controller must execute every 1 ms, while ROS 2 diagnostic information only needs updating every 500 ms. What is the best architecture?

A. Put both operations in one Python loop with a 500 ms sleep  
B. Run the motor controller as a periodic real-time task and diagnostics as a lower-priority task  
C. Publish diagnostics from the motor interrupt every 1 ms  
D. Increase every ROS 2 operation to 1 kHz

**Answer: B**

This tests **why an RTOS is useful**, rather than merely asking students to define FreeRTOS terminology.

Important RTOS concepts for the course include:

- periodic tasks
- task priorities
- timers
- interrupts / ISR
- scheduling
- deterministic timing
- fast control loops versus slower communication/diagnostic tasks

---

## 7. Communication should be taught by abstraction layer

Students often treat every form of communication as equivalent. The course should distinguish the layers.

```text
Application / Robotics
    ROS 2 messages
         │
         ▼
Middleware
    DDS / RTPS
         │
         ▼
Operating / Computing System
    Linux / RTOS
         │
         ▼
Communication / Networking
 ┌───────┼────────┬──────────┐
 UART    CAN      LIN     Ethernet
 │        │        │          │
 ▼        ▼        ▼          ▼
Serial   CAN-FD   LIN      Automotive
                           Ethernet
         │
         ▼
Physical interfaces / electronics
```

A useful teaching progression is:

**GPIO/PWM/ADC → UART → I²C/SPI → CAN/CAN-FD → LIN → Ethernet → TCP/UDP → DDS/RTPS → ROS 2 topics/services/actions**

This is **not one literal protocol stack**. It is a teaching progression from low-level electrical/peripheral interfaces toward embedded networking, computer networking, middleware, and robotics software.

Students should understand questions such as:

- At what abstraction level is the communication occurring?
- Is this an electrical interface, embedded bus, network transport, middleware, or application message?
- What information crosses from ROS 2 to the MCU?
- What information comes back from sensors and firmware?

---

## 8. Python and OOP should connect to robotics architecture

Python should not become an isolated syntax examination.

Example:

```python
class Motor:
    def __init__(self, name, velocity=0.0):
        self.name = name
        self.velocity = velocity

left_motor = Motor("left")
```

Question:

> What does `left_motor` represent?

A. A class definition  
B. An instance/object representing a particular motor  
C. A ROS 2 topic  
D. Firmware

**Answer: B**

Then:

```python
motors = {
    "left": left_motor,
    "right": right_motor
}
```

This connects dictionaries and objects to the representation and organization of robotic components and state.

Relevant Python concepts therefore include:

- objects and classes
- attributes
- lists
- dictionaries
- iteration
- NumPy/numerical data
- file/data I/O
- modular software organization

---

## 9. Simulation must connect to the physical robot

Students should understand what is replaced by simulation and what can remain conceptually unchanged.

```text
REAL ROBOT                           SIMULATED ROBOT

Motor                               simulated joint
Encoder                             simulated encoder
IMU                                 simulated IMU
Motor driver                        dynamics model
MCU / controller         <-->       controller model
        \                            /
         \                          /
          ROS 2 topics / messages
                    │
              ROS 2 Nodes
                    │
             RViz / Gazebo
```

Example question:

> A ROS 2 Python node publishes `/cmd_vel`. The system changes from a Gazebo robot to a physical mobile robot. Which component should ideally require the least conceptual change?

A. Physical motor  
B. Encoder hardware  
C. High-level ROS 2 navigation node  
D. Motor-driver electronics

**Answer: C**

Students should also distinguish:

- **RViz:** visualization of robot state, sensor information, coordinate frames, etc.
- **Gazebo:** simulation of the robot/environment and physical interactions.
- **URDF:** robot description/model structure.
- **ROS 2:** communication and software architecture that can connect either simulated or physical components.

---

## 10. Integrated final scenario

The strongest final portion of the midterm can use one common robot architecture.

```text
Laptop / SBC
┌───────────────────────────────┐
│ ROS 2                         │
│                               │
│ Camera → perception node      │
│              ↓                │
│       navigation node         │
│              ↓                │
│          /cmd_vel             │
└──────────────┬────────────────┘
               │ communication
               ▼
┌───────────────────────────────┐
│ STM32 / MCU                   │
│ FreeRTOS                      │
│                               │
│ communication task            │
│        ↓                      │
│ velocity control task         │
│   ↑              ↓            │
│ encoder          PWM          │
└───┬──────────────┬────────────┘
    │              │
 Encoder       Motor Driver
                    │
                   Motor
                    │
                   Wheel
```

Several questions can reference this architecture:

1. Which layer should close the fast wheel-velocity loop?
2. If `/cmd_vel` stops arriving, where should a safety timeout be handled?
3. Where does encoder information originate?
4. Which communication mechanism is internal to ROS 2?
5. If the physical robot is replaced by Gazebo, which hardware components are being modeled?
6. If wheel speed is correct but calculated travel distance is wrong, which parameters should be investigated first?

The final question can connect encoder counts, gearing, wheel radius, odometry, units, and feedback.

---

## 11. The central command-and-feedback chain

By the midterm, students should be able to reason through:

**ROS 2 node → topic/message → communication → MCU → RTOS control task → PWM → motor driver → motor → mechanical motion → encoder/sensor → MCU → feedback communication → ROS 2 → state estimation/high-level control**

This chain can serve as the main learning objective for the first half of the course.

---

## 12. Reference books discussed

### Embedded architecture

**Elecia White — _Making Embedded Systems_, 2nd Edition**

Useful for developing systems-level understanding of embedded architecture, including hardware/software boundaries, peripherals, timing, interrupts, state machines, communication, debugging, and resource constraints.

### Automotive communication/network architecture

Useful complementary references include books covering:

- CAN / CAN-FD
- LIN
- FlexRay
- Automotive Ethernet
- in-vehicle network architecture

Two references discussed were:

- **Walter Zimmermann & Ralf Schmidgall — _Automotive Internetworking_** — useful for the broader in-vehicle networking perspective.
- **Kirsten Matheus & Thomas Königseder — _Automotive Ethernet_** — useful for modern automotive Ethernet architecture.

These references can complement White's embedded-system perspective by providing the vehicle-network side of the course.

---

## 13. Next development step

Before producing the final lecture slides:

1. Develop approximately **50–60 candidate multiple-choice questions**.
2. Tag each question by concept and abstraction layer.
3. Identify the prerequisite knowledge needed to answer each question.
4. Select approximately **40 questions** for the midterm.
5. Use the resulting concept map to design Weeks 1–8 lectures and laboratories.
6. Verify that every assessed concept was explicitly taught and practiced.

The result should be a course in which MATLAB/Python, ROS 2, RTOS, embedded communication, motors, sensing, control, and simulation are presented not as separate technologies, but as **layers of one integrated robotic control system**.
