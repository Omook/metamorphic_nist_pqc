# Makefile

CC = gcc            # 컴파일러 설정
CFLAGS = -Wall      # 컴파일 옵션 설정
TARGET = test       # 생성할 실행 파일 이름

all: $(TARGET)

$(TARGET): main.c add.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c add.c

clean:
	rm -f $(TARGET)