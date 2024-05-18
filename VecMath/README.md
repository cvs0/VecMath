# VecMath

VecMath is a versatile C++ utility for vector and matrix mathematics. It provides a collection of templated functions to perform common operations on 3D and 4D vectors, as well as 4x4 matrices. This library is ideal for applications in graphics programming, physics simulations, and any other domain requiring efficient and robust vector and matrix math.

## Features

- **Vector Operations (Vec3 & Vec4):**
  - Dot product
  - Cross product (Vec3)
  - Normalization
  - Addition
  - Subtraction
  - Scalar multiplication
  - Component-wise multiplication
  - Projection
  - Reflection
  - Linear interpolation (lerp)
  - Clamping
  - Absolute value
  - Matrix-vector multiplication

- **Matrix Operations (Mat4):**
  - Transpose
  - Identity matrix creation
  - Scaling transformation
  - Translation transformation
  - Matrix-matrix multiplication

## Usage

### Including VecMath

To use VecMath in your project, include the header file:

```cpp
#include "VecMath.h"
```

### Example Usage

Here's an example of how you might use VecMath to perform some basic operations:

```cpp
#include "VecMath.h"
#include <iostream>

int main() {
    Vec3<float> vec1(1.0f, 2.0f, 3.0f);
    Vec3<float> vec2(4.0f, 5.0f, 6.0f);

    // Dot product
    float dotProduct = VecMath::dot(vec1, vec2);
    std::cout << "Dot product: " << dotProduct << std::endl;

    // Cross product
    Vec3<float> crossProduct = VecMath::cross(vec1, vec2);
    std::cout << "Cross product: (" << crossProduct.x << ", " << crossProduct.y << ", " << crossProduct.z << ")" << std::endl;

    // Normalization
    Vec3<float> normalizedVec = VecMath::normalize(vec1);
    std::cout << "Normalized vector: (" << normalizedVec.x << ", " << normalizedVec.y << ", " << normalizedVec.z << ")" << std::endl;

    return 0;
}
```