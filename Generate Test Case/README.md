# ✨ Stress Testing Script

## 📌 Overview

This repository contains a **stress testing script** designed to compare the output of a solution program against a brute force (correct) program using randomly generated test cases. It automates the process of compiling, running, and verifying results.

---

## 💂 Files Included

- 🛠 **`stress.bat`** - Batch script to automate the stress test process.
- 🎢 **`gen.cpp`** - Test case generator.
- ⚡ **`solution.cpp`** - Optimized solution to be tested.
- 🏗 **`brute.cpp`** - Correct but inefficient reference solution.

---

## 🚀 How It Works

1. **🛠 Compilation:** The script compiles `gen.cpp`, `solution.cpp`, and `brute.cpp`.
2. **💜 Test Case Generation:** Runs `gen.exe` to produce random test cases.
3. **⚙️ Execution:** Feeds the generated input into both `solution.exe` and `brute.exe`.
4. **🔍 Comparison:** Compares the outputs of `solution.exe` and `brute.exe`.
5. **🚩 Stopping on Mismatch:** If a discrepancy is found, the script outputs the failing test case.

---

## ▶️ Usage

Run the script from the command line:

```bash
stress.bat [number_of_tests] [compile_flag]
```

- 🎯 `number_of_tests` (optional): Number of test cases to generate. Default is **100**.
- 💽 `compile_flag` (optional): Set to **0** to skip compilation. Default is **1** (compile).

### 🔹 Example:

```bash
stress.bat 50 1
```

This runs **50 test cases** and compiles the programs before execution.

---

## ✅ Expected Output

- If all test cases pass:
  ```bash
  🎉 All test cases passed :D
  ```
- If a mismatch occurs:
  - 🚨 Displays the **input that caused the failure**.
  - 📊 Shows the outputs from `solution.exe` and `brute.exe`.

---

## 🛠 Troubleshooting

- ❌ **Compilation Errors:** Ensure `g++` is installed and accessible in your system path.
- 🔀 **Infinite Loop / Crash:** Check `solution.cpp` for edge cases.
- 🤔 **FC command not found:** The script uses `fc` (file compare), which is available by default on Windows.

---

## 🎨 Customization

Modify `generate_test()` in **`gen.cpp`** to create different types of test cases.

### 👒 Example `gen.cpp`

The `gen.cpp` file generates test cases with random values within a given range:

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define accuracy chrono::steady_clock::now().time_since_epoch().count()
#define rep(i, a, n) for (int i = a; i <= n; ++i)

mt19937 rng(accuracy);

int rand(int l, int r) {
    uniform_int_distribution<int> ludo(l, r);
    return ludo(rng);
}

void generate_test() {
    int n = rand(2, 5), k = rand(1, n - 1);
    vector<int> v(n);
    for (int &x : v) x = rand(0, 50);
    cout << n << " " << k << endl;
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

signed main() {
    srand(accuracy);
    int t = 1;
    cout << t << '\n';
    while (t--) {
        generate_test();
    }
}
```

### 💡 Example Output from `gen.exe`

```bash
3 2
10 20 30
```

Explanation:
- `3 2` → Three elements in the array, `k = 2`.
- `10 20 30` → Random values in the array.

