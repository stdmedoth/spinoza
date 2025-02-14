# Vector Field Project

This is a C++ project simulating a vector field, using classes to represent vectors and vector fields. The project does not use any external libraries except the standard C++ library. The goal is to demonstrate the creation of a vector field, vector manipulation, and printing the field.

## Project Structure

The project is structured as follows:

```
/VectorFieldProject
│
├── /include
│   ├── Vector.hpp           # Definition of the Vector class
│   ├── VectorField.h        # Definition of the VectorField class
│   ├── Function.h           # Definition of the Function class (for numerical methods)
│
├── /src
│   ├── Vector.cpp           # Implementation of the Vector class
│   ├── VectorField.cpp      # Implementation of the VectorField class
│   ├── Function.cpp         # Implementation of numerical methods (derivatives and integrals)
│   └── main.cpp             # Main function
│
├── CMakeLists.txt           # CMake configuration file
├── README.md                # This file
└── a.out                    # Executable generated after compilation
```

### File Descriptions

- **Vector.hpp**: Contains the definition of the `Vector` class, which represents a vector in an `N`-dimensional space.
- **VectorField.h**: Contains the definition of the `VectorField` class, which stores multiple vectors associated with points in space.
- **Function.h**: Defines the `Function` class, which includes numerical methods such as derivatives and integrals.
- **Vector.cpp**: Implementation of the `Vector` class, with methods for vector manipulation.
- **VectorField.cpp**: Implementation of the `VectorField` class, with methods for manipulating vector fields.
- **Function.cpp**: Implements numerical methods, including differentiation and integration using Euler's method.
- **main.cpp**: Test code that creates a vector field and prints the field.

## Numerical Methods Used

This project implements basic numerical techniques for differentiation and integration.

### **Derivative Calculation**

The derivative of a function at a discrete set of points is approximated using:

\[ f'(x_i) \approx \frac{f(x_{i+1}) - f(x_i)}{x_{i+1} - x_i} \]

This method is implemented in the `Function` class, where the difference between adjacent values is computed to estimate the rate of change.

### **Integral Calculation using Euler's Method**

The integral is computed using Euler’s method, which approximates the cumulative sum of function values over discrete intervals:

\[ I_{n+1} = I_n + f(x_n) \cdot h \]

where \( h = x_{n+1} - x_n \) is the step size. This is similar to the rectangular integration method and provides a straightforward numerical approach to estimating integrals.

## Prerequisites

This project uses CMake as the build system. Make sure you have CMake installed on your system. You can install CMake using the following commands:

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
   If you don't have the repository on your machine, clone it with the command:
   ```bash
   git clone https://your-repository.git
   cd VectorFieldProject
   ```

2. **Create the build directory:**
   Create a `build` directory to store the build files:
   ```bash
   mkdir build
   cd build
   ```

3. **Generate build files with CMake:**
   Run CMake to generate the necessary build files:
   ```bash
   cmake ..
   ```

4. **Build the project:**
   Compile the project using `make`:
   ```bash
   make
   ```

   This will generate the executable `VectorFieldProject` in the `build` directory.

## Running the Program

To run the program, use the following command from the `build` directory:

```bash
./VectorFieldProject
```

The program will print the vector field, where each point is associated with a vector.

## How it works

The code creates a 3-dimensional vector field with 4 points, where each point has an associated vector. The vector field is printed with the points and their respective vectors.

### Sample output:
```
{
  [0, 0, 0] -> [1, 1, 1]
  [1, 0, 0] -> [0, 1, -1]
  [0, 1, 0] -> [-1, 0, 1]
  [0, 0, 1] -> [1, -1, 0]
}
```

## Contributions

Feel free to contribute to the project! If you find a bug or would like to improve the code, feel free to fork the repository and submit a pull request.

1. Fork this repository.
2. Create a branch for your feature or fix: `git checkout -b my-feature`.
3. Commit your changes: `git commit -am 'Adding my feature'`.
4. Push to the branch: `git push origin my-feature`.
5. Open a pull request to the main repository.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

**Enjoy the project and feel free to make improvements or experiment with new features!**

