program_NAME := mediainv
program_CXX_SRCS := $(wildcard src/*.cpp)
program_CXX_OBJS := ${program_CXX_SRCS:.cpp=.o}
program_OBJS = $(program_CXX_OBJS)
program_INCLUDE_DIRS := src
program_LIBRARY_DIRS :=
program_LIBRARIES :=

CPPFLAGS += $(foreach includedir,$(program_INCLUDE_DIRS),-I$(includedir)) -O2 -std=gnu++14
LDFLAGS += $(foreach librarydir,$(program_LIBRARY_DIRS),-L$(librarydir))
LDFLAGS += $(foreach library,$(program_LIBRARIES),-l$(library))

.PHONY: all test install clean

all: $(program_NAME) test install clean

$(program_NAME): $(program_OBJS)
	$(LINK.cc) $(program_OBJS) -o $(program_NAME)

test:
	@- g++ -std=c++14 -g -Wall -Wextra -o test tests/alltests.cpp; ./test

install:
	@- install -m557 mediainv /usr/bin

clean:
	- @- $(RM) $(program_NAME)
	- @- $(RM) $(program_OBJS)
	- @- rm test

