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

Here's a better example of how to use Spinoza for field simulations:

```cpp
#include <iostream>
#include "Field.hpp"
#include "VectorField.hpp"
#include "ScalarField.hpp"
#include "VectorSpace.hpp"

int main()
{
    // Define a 3D vector space with 10,000 elements
    VectorSpace<double, 3, 10000> domain;
    Field<double, 10000> image;
    VectorSpace<double, 3, 10000> vector_image;

    // Initialize the scalar field and vector field values
    for (int i = 0; i < 10000; i++)
    {
        double x = 0.001 * i;
        double y = 0.002 * i;
        double z = 0.003 * i;
        domain[i] = Vector<double, 3>({x, y, z});
        image[i] = x + y + z;
        vector_image[i] = Vector<double, 3>({x, y, z});
    }

    // Create a scalar field (temperature) and output its image
    ScalarField<double, 3, 10000> temperature(domain, image);
    image = temperature.getImage();
    for (int i = 0; i < 10000; i++)
    {
        std::cout << image[i] << "\n";
    }

    // Create a vector field (position) and output its image
    VectorField<double, 3, 10000> position(domain, vector_image);
    vector_image = position.getImage();
    for (int i = 0; i < 10000; i++)
    {
        std::cout << vector_image[i] << "\n";
    }

    return 0;
}
```

### Explanation:

- **`VectorSpace`**: Represents a space with vectors.
- **`Field`**: Represents the image of a scalar or vector field.
- **`ScalarField`**: Represents a scalar field where the value at each point is a scalar (used for temperature or other scalar quantities).
- **`VectorField`**: Represents a vector field where the value at each point is a vector (used for position or other vector quantities).
- **`getImage()`**: Retrieves the field values as an array.
  
In the example:

- A scalar field `temperature` is computed and printed.
- A vector field `position` is computed and printed.

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
