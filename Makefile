# 变量定义
CXX = g++
ALL = lcpractice
# 自动检索单前目录下所有cpp文件
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
TARGET = $(patsubst %.o, %.exe, $(OBJS))

CXXFLAGS = -c -Wall

.PHONY: cleanwin cleanlin

# 按次序生成依赖
$(ALL): $(TARGET)
	@echo It's buiding...

%.exe: %.o
	$(CXX) -o $@  $<

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

cleanwin:
	del *.o $(TARGET)

cleanlin:
	rm  $(TARGET)