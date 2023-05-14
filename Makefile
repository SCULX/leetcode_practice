# ��������
CXX = g++
ALL = lcpractice
# �Զ�������ǰĿ¼������cpp�ļ�
SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))
TARGET = $(patsubst %.o, %.exe, $(OBJS))

CXXFLAGS = -c -Wall

.PHONY: cleanwin cleanlin

# ��������������
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