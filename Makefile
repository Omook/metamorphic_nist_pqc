# Makefile

CC = gcc                   # 컴파일러 설정
CFLAGS = -Wall             # 컴파일 옵션 설정
TARGET = t              # 생성할 실행 파일 이름
#SOURCES = $(wildcard *.c cross/*.c	cross/cross_meta/*.c)
SOURCES = $(wildcard *.c LESS/*.c	LESS/LESS_meta/*.c)
#SOURCES = $(wildcard *.c hawk/hawk512/*.c	hawk/hawk_meta/*.c)
#SOURCES = $(wildcard *.c PERK/PERK_128_fast_3/*.c	PERK/PERK_meta/*.c)
#SOURCES = $(wildcard *.c sdith/sdith_threshold_cat5_p251/*.c	sdith/sdith_threshold_cat5_p251/sha3/*.c	sdith/sdith_meta/*.c)
#SOURCES = $(wildcard *.c MAYO/*.c	MAYO/MAYO_meta/*.c)
#SOURCES = $(wildcard *.c QRUOV/*.c	QRUOV/QRUOV_meta/*.c)
#SOURCES = $(wildcard *.c SNOVA/*.c	SNOVA/shake/*.c	SNOVA/shake/*.c	SNOVA/SNOVA_meta/*.c)
#SOURCES = $(wildcard *.c UOV/*.c	UOV/UOV_meta/*.c)



$(TARGET): $(SOURCES)
	$(CC) -O3 $(SOURCES) -o  $(TARGET)

clean:
	rm -f $(TARGET)