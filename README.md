# Spinoza - Math & Physics Simulation Library

Spinoza is a **C++ library** designed for high-performance mathematical and physics simulations. It provides a set of tools for vector operations, numerical differentiation, and integration. The library is built using **pure C++** and does not rely on any external dependencies beyond the C++ Standard Library.

## 🔥 Features

- ✅ N-dimensional vector operations
- ✅ Scalar and vector field simulation
- ✅ Numerical differentiation using Euler's method
- ✅ Numerical integration using Euler's method
- ✅ Expandable framework for custom simulations

## 🚀 Getting Started

### Prerequisites

- **C++17 or later** compiler
- **CMake** for building

#### Install CMake

- **Ubuntu/Debian:**
  ```bash
  sudo apt-get install cmake
  ```

- **macOS (Homebrew):**
  ```bash
  brew install cmake
  ```

### Installation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/stdmedoth/spinoza.git
   cd spinoza
   ```

2. **Create a build directory and navigate into it:**
   ```bash
   mkdir build && cd build
   ```

3. **Generate build files with CMake:**
   ```bash
   cmake ..
   ```

4. **Build the project:**
   ```bash
   make
   ```

5. The compiled library will be available for linking in your project.

### Integrating Spinoza in Your Project

If you're using **CMake**, simply link the Spinoza library:

```cmake
add_subdirectory(spinoza)
target_link_libraries(my_project PRIVATE spinoza)
```

If you're **manually compiling**:

```bash
g++ -std=c++17 -I./include my_program.cpp -o my_program
```

## 🧑‍💻 Usage Example

Here is a simple example demonstrating how to use Spinoza for field simulations:

```cpp
#include <iostream>
#include "ScalarField.hpp"
#include "Field.hpp"
#include "VectorSpace.hpp"

int main()
{
    // Define a 3D vector space with 10,000 elements
    VectorSpace<double, 3, 10000> domain;
    Field<double, 10000> image;

    // Initialize the vector field and image values
    for (int i = 0; i < 10000; i++)
    {
        double x = 0.001 * i;
        double y = 0.002 * i;
        double z = 0.003 * i;
        domain[i] = Vector<double, 3>({x, y, z});
        image[i] = x + y + z;
    }

    // Create a scalar field for acceleration and compute the velocity field
    ScalarField<double, 3, 10000> acceleration(domain, image);
    ScalarField<double, 3, 10000> velocity = acceleration.integral(0, 10000);
    
    // Update the velocity field image and set it back
    image = velocity.getImage();
    image = image + 10.0;
    velocity.setImage(image);

    // Compute the position field from the velocity field
    ScalarField<double, 3, 10000> position = velocity.integral(0, 10000);
    image = position.getImage();

    // Output the results
    for (int i = 0; i < 10000; i++)
    {
        std::cout << image[i] << "\n";
    }

    return 0;
}
```

### Explanation:

- `VectorSpace`: Represents a space with vectors.
- `Field`: Represents the image of generic field.
- `ScalarField`: Represents a field where the value at each point is a scalar (used for acceleration, velocity, position).
- `integral`: Computes the integral of the field using Euler’s method.

## 📂 Project Structure

```
/spinoza
│
├── /include                # Header files
├── /src                    # Source files
├── /examples               # Example programs
├── CMakeLists.txt          # CMake configuration
├── README.md               # Documentation
├── LICENSE                 # License information
```

## 🤝 Contributing

Contributions are welcome! To contribute:

1. **Fork the repository.**
2. **Create a feature branch:** `git checkout -b my-feature`
3. **Commit your changes:** `git commit -am 'Added new feature'`
4. **Push to your branch:** `git push origin my-feature`
5. **Submit a pull request.**

## 📜 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

---

💡 **Explore the world of math & physics with Spinoza!** 🚀

---
