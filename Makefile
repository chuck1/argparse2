
inc_dir = -Iinclude
lib_dir = 

cflags = -std=c++0x

src = $(shell find src -name "*.cpp")

obj = $(patsubst %.cpp,%.o,$(src))

bin = build/libargparse.a

test = build/test

GCC = g++

.PHONY: all

all: $(test)

%.o: %.cpp
	@$(GCC) -c $^ -o $@ $(inc_dir) $(cflags)

$(bin): $(obj)
	@echo build $@
	@mkdir -p $(dir $@)
	@ar rcs $@ $(obj)
	@ranlib $@

$(test): $(bin)
	@mkdir -p $(dir $@)
	@$(GCC) test/main.cpp -Lbuild -largparse -o $@ $(inc_dir) $(lib_dir) $(cflags)

clean:
	@rm -rf build

help:
	@echo $(src)
	@echo $(obj)


