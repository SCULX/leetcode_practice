# 变量定义
CXX = g++
ALL = lcpractice
IDIR = mid
LDIR = bin
# 自动检索当前目录下所有cpp文件
SRCS = $(wildcard $(IDIR)/*.cpp)
OBJS = $(patsubst $(IDIR)/%.cpp, $(IDIR)/$(LDIR)/%.o, $(SRCS))
TARGET = $(patsubst %.o, %.exe, $(OBJS))
# win用del删除文件需要特殊路径
WinCleanTarget = $(patsubst $(IDIR)/$(LDIR)/%.exe, .\$(IDIR)\$(LDIR)\\%.exe, $(TARGET))

CXXFLAGS = -c -Wall

.PHONY: cleanwin cleanlin

# 按次序生成依赖
$(ALL): $(TARGET)
	@echo Its buiding...

# 需要显示指定.exe文件位置，不能用%.exe，否则会在当前目录下寻找，不会寻找到子目录
$(IDIR)/$(LDIR)/%.exe: $(IDIR)/$(LDIR)/%.o
	$(CXX) -o $@  $<

$(IDIR)/$(LDIR)/%.o: $(IDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

cleanwin:
	del *.o $(WinCleanTarget)

cleanlin:
	rm  $(TARGET)