CC := g++ -o
CC += $(CC) -O2

$(CC) src/main.cpp fifo_server
