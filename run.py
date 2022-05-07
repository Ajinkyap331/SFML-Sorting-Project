import subprocess
subprocess.call("g++ -c Data.cpp", shell=True)
subprocess.call("g++ -c ./main.cpp", shell=True)
subprocess.call("g++ main.o Data.o -o app -lsfml-graphics -lsfml-window -lsfml-system", shell=True)
subprocess.call("./app", shell=True)
