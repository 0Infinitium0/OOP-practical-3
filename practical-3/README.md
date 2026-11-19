# Practical 03: Constructors and Rule of Five

- **Student Name:** Satinderpal Singh Chaney
- **Roll Number:** E26B00S2034
- **Repository:** `practical 3`

## Aim
To understand object creation, copying, moving, and safe management of an owned resource in C++.

## Question
Implement a class that demonstrates default, parameterized, copy and move constructors, and the Rule of Five.

## Overview of Implementation (`practical3.cpp`)
The `DynamicArray` class manages a heap-allocated `int*` buffer along with its element count (`size_`):
- **Default Constructor:** Initializes `data_` to `nullptr` and `size_` to `0`.
- **Parameterized Constructor:** Allocates a dynamic array of size `n` and populates values (`10 20 30 40 50`).
- **Rule of Five:**
  1. **Destructor (`~DynamicArray()`):** Releases heap memory using `delete[] data_` and resets pointers/size.
  2. **Copy Constructor (`DynamicArray(const DynamicArray&)`):** Performs a deep copy into a newly allocated buffer.
  3. **Copy Assignment Operator (`operator=(const DynamicArray&)`):** Checks for self-assignment, allocates and deep-copies elements, and frees old memory.
  4. **Move Constructor (`DynamicArray(DynamicArray&&) noexcept`):** Transfers `data_` and `size_` directly from the rvalue source and sets the source to `nullptr` / `0`.
  5. **Move Assignment Operator (`operator=(DynamicArray&&) noexcept`):** Guards against self-move, frees existing memory, transfers ownership, and resets the source object.

## Compilation & Execution

### Windows (PowerShell / MinGW `g++`)
```powershell
g++ -std=c++17 -Wall -Wextra practical3.cpp -o practical3.exe
.\practical3.exe
```

### Linux / macOS (`g++` / `clang++`)
```bash
g++ -std=c++17 -Wall -Wextra practical3.cpp -o practical3
./practical3
```

## Memory-Checking Instructions

### Option 1: AddressSanitizer & LeakSanitizer (GCC / Clang — Linux, macOS, WSL)
Compile with AddressSanitizer (`-fsanitize=address`) and debug symbols (`-g`):
```bash
g++ -std=c++17 -g -O1 -fsanitize=address,undefined practical3.cpp -o practical3_asan
./practical3_asan
```
AddressSanitizer automatically checks for heap-use-after-free, double-free, out-of-bounds accesses, and memory leaks upon exit.

### Option 2: Valgrind (Linux / WSL)
Run with full leak checking enabled:
```bash
g++ -std=c++17 -g practical3.cpp -o practical3_dbg
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./practical3_dbg
```
Expected summary: `All heap blocks were freed -- no leaks are possible` and `0 errors from 0 contexts`.

## Uploading to GitHub (`practical 3`)
1. Create a new repository on GitHub named **`practical 3`** (GitHub will provide a URL such as `https://github.com/<your-username>/practical-3.git` or `practical%203.git`).
2. Extract the ZIP archive into a local folder and initialize Git:
   ```bash
   git init
   git add .
   git commit -m "Add Practical 03: Constructors and Rule of Five"
   git branch -M main
   git remote add origin <YOUR_GITHUB_REPOSITORY_URL>
   git push -u origin main
   ```
