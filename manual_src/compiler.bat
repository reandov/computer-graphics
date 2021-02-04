@echo off

echo "Compiling file %1.cpp"
g++ -o bin/%1 -Wall src/%1.cpp -mwindows glut32.lib -lopengl32 -lglu32

echo "Executing file %1.exe"
start /d "bin/" %1.exe