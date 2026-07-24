
# MATLAB Cell Arrays vs Python Lists

## A Mental Bridge for MATLAB Users Learning Python and ROS 2

> The goal is **not** to compare syntax.
>
> The goal is to build the correct mental model for MATLAB users entering the Python and ROS 2 ecosystem.

---

# MATLAB has several container types

## 1. Character Vector

```matlab
word = 'one';
```

A character vector is simply a sequence of characters.

---

## 2. String Array

```matlab
words = ["one" "two" "three"];
```

MATLAB's modern string type.

---

## 3. Cell Array

```matlab
list = {"one","two","three"};
```

A cell array stores objects of many different types.

```matlab
list(1)      % returns a cell
list{1}      % returns the contents
```

---

# A Common Beginner Mistake

```matlab
number = ['one' 'two' 'three']
```

MATLAB concatenates character vectors into one long character vector:

```text
onetwothree
```

If your goal is a collection of words, use either a string array or a cell array.

---

# Python Comparison

```python
word = "one"
```

```python
words = [
    "one",
    "two",
    "three",
]
```

Python has no separate cell array type.

A Python **list** serves the role that MATLAB users usually associate with a cell array.

---

# The Most Important Mental Model

| MATLAB | Purpose | Python |
|---------|---------|--------|
| `'one'` | Character vector | `"one"` (string) |
| `"one"` | String object | `"one"` (string) |
| `{}` | General-purpose heterogeneous container | `[]` (list) |
| `[]` | Numeric matrix | `numpy.ndarray` |

The last row is the biggest conceptual difference.

---

# Why This Matters

MATLAB:

```matlab
A = [1 2 3]
```

creates a numeric matrix.

Python:

```python
A = [1, 2, 3]
```

creates a list.

The numerical equivalent is

```python
import numpy as np

A = np.array([1, 2, 3])
```

---

# ROS 2 Example

MATLAB

```matlab
topicNames = {
    "/cmd_vel",
    "/odom",
    "/scan"
};
```

Python

```python
topic_names = [
    "/cmd_vel",
    "/odom",
    "/scan",
]
```

These are text labels, so a Python list is the natural structure.

---

# Loop Comparison

MATLAB

```matlab
for k = 1:length(topicNames)
    disp(topicNames{k})
end
```

Python

```python
for topic_name in topic_names:
    print(topic_name)
```

Python programmers usually iterate through the objects themselves rather than integer indices.

---

# Why This Leads Naturally to ROS 2

```python
import os

files = os.listdir(".")
```

`os.listdir()` returns a Python list.

```python
for file in files:
    print(file)
```

The same programming style appears throughout ROS 2.

---

# Final Takeaway

```text
MATLAB

character vector
        ↓
string array
        ↓
cell array
        ↓
numeric matrix

==============================

Python

string
        ↓
list
        ↓
NumPy array
```

## One sentence to remember

> A Python list is conceptually much closer to a MATLAB cell array than to a MATLAB numeric matrix. A NumPy array is the closest equivalent to a MATLAB numeric matrix.
