@echo off
g++ -DRECURSION_CODER1_MAIN codeR1.cpp -o codeR1.exe
if %ERRORLEVEL% EQU 0 (
    echo Compilation successful!
    echo Running the program...
    codeR1.exe
) else (
    echo Compilation failed!
)
pause
