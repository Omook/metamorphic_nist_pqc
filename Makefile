# Makefile

CC = gcc                   # 컴파일러 설정
CFLAGS = -Wall             # 컴파일 옵션 설정
TARGET = t              # 생성할 실행 파일 이름
SOURCES = $(wildcard *.c cross/*.c	cross/cross_meta/*.c)
#SOURCES = $(wildcard *.c hawk/hawk256/*.c	hawk/hawk_meta/*.c)

$(TARGET): $(SOURCES)
	$(CC) -O3 $(SOURCES) -o  $(TARGET)

clean:
	rm -f $(TARGET)