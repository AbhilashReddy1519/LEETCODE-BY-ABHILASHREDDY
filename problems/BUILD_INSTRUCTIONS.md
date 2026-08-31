# Compile C++ Files to `compiled/`

This workspace uses a helper script to compile all `.cpp` files into the `compiled/` folder.

## How to compile

1. Open a terminal in the workspace folder:
   - `c:\Users\ABHILASH REDDY\OneDrive\Documents\LEETCODE-BY-ABHILASHREDDY`
2. Run the batch script:
   - `compile_all.bat`

The script will create `compiled/` if it does not exist and compile each `.cpp` file into an `.exe` file in that folder.

## Requirements

- `g++` must be installed and available in your PATH.
- If using Visual Studio, you can adapt the script to use `cl.exe` instead.

## Result

Compiled executables will appear in:

- `compiled\Counting_Rooms.exe`
- `compiled\Longest Substring Without Repeating Characters.exe`
- `compiled\Maximum Average Subarray I.exe`
- `compiled\twoSum.exe`
