@echo off
REM Compile all .cpp files in this folder into the compiled\ subfolder.

set "OUT_DIR=compiled"
if not exist "%OUT_DIR%" mkdir "%OUT_DIR%"

for %%F in (*.cpp) do (
    echo Compiling %%F...
    g++ -std=c++17 -O2 "%%F" -o "%OUT_DIR%\%%~nF.exe"
    if errorlevel 1 (
        echo ERROR: Failed to compile %%F
        exit /b 1
    )
)
echo.
echo All compiled executables are in %OUT_DIR%\
pause
