# Spinoza - Math & Physics Simulation Project

This is a C++ project for mathematical and physics simulations, providing tools for vector operations, differentiation, and integration using Euler's method. The project is built with pure C++ and does not rely on external libraries beyond the standard C++ library.

## Project Structure

```
/spinoza
│
├── /include
│   ├── Vector.hpp           # Definition of the Vector class
│   ├── Function.h           # Definition of the Function class (for differentiation & integration)
│
├── /src
│   ├── Vector.cpp           # Implementation of the Vector class
│   ├── Function.cpp         # Implementation of Function class
│   └── main.cpp             # Main function with example simulations
│
├── CMakeLists.txt           # CMake configuration file
├── README.md                # This file
└── a.out                    # Executable generated after compilation
```

### File Descriptions

- **Vector.hpp**: Defines the `Vector` class for N-dimensional vector operations.
- **Function.h**: Implements differentiation and integration methods using Euler’s approach for vector fields.
- **Vector.cpp**: Implements vector operations.
- **Function.cpp**: Implements numerical differentiation and integration for vector fields.
- **main.cpp**: Contains test simulations demonstrating the capabilities of the project.

## Prerequisites

Ensure you have CMake installed:

### Ubuntu/Debian:
```bash
sudo apt-get install cmake
```

### macOS:
```bash
brew install cmake
```

## Compilation

1. **Clone the repository:**
   ```bash
   git clone https://github.com/stdmedoth/spinoza
   cd spinoza
   ```

2. **Create a build directory:**
   ```bash
   mkdir build
   cd build
   ```

3. **Generate build files with CMake:**
   ```bash
   cmake ..
   ```

4. **Build the project:**
   ```bash
   make
   ```
   This will generate the executable `spinoza` in the `build` directory.

## Running Simulations

Execute the program with:
```bash
./spinoza
```

The output will display vector operations, field mappings, and numerical calculations.

## Features

✔ Vector operations in N-dimensional space  
✔ Simulation of vector fields  
✔ Numerical differentiation using Euler's method  
✔ Numerical integration using Euler's method  
✔ Expandable framework for further simulations  

## Contributions

Contributions are welcome! Feel free to fork the repository, add new features, or improve existing code.

1. Fork this repository.
2. Create a branch: `git checkout -b my-feature`.
3. Commit changes: `git commit -am 'Adding my feature'`.
4. Push to branch: `git push origin my-feature`.
5. Open a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

🚀 **Enjoy exploring mathematical and physics simulations!**

