# Version 1.0 
# CXX = g++
# TARGET = main
# OBJ = TestThread.o thread.o thread.h

# $(TARGET):$(OBJ)
# 	$(CXX) -o $(TARGET) $(OBJ)
# TestThread.o:TestThread.cpp
# 	$(CXX) -c TestThread.cpp
# thread.o:thread.cpp
# 	$(CXX) -c thread.cpp


# #Version 2.0
# CXX = g++
# TARGET = main
# OBJ = TestThread.o thread.o thread.h

# $(TARGET):$(OBJ)
# 	$(CXX) -o $@ $^

# %.o:%.cpp
# 	$(CXX) -c $< -o $@

# .PHONY: clean
# clean:
# 	rm -f *.o $(TARGET)


# Version 3.0
CXX = g++
TARGET = main
# 使用 wildcard 获取所有 .c 文件
ALLSRC = $(wildcard *.cpp)
#使用 patsubst 将 .c 文件转换为 .o 文件
OBJ = $(patsubst %.cpp, %.o, $(ALLSRC))

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) -c $< -o $@

.PHONY: clean
clean:
	rm -f *.o $(TARGET)
