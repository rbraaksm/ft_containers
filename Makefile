NAME = all_containers

FILES = ./test/catchMain ./test/listTest ./test/vectorTest ./test/queueTest ./test/stackTest ./test/BidirectionalIteratorTest ./test/RandomAccessIteratorTest ./test/mapTest
SRCS = $(addsuffix .cpp, $(FILES))
OBJS = $(SRCS:.cpp=.o)

MFILES = ./test/catchMain.cpp
MOBJ = $(MFILES: .cpp=.o)

LFILES = ./test/listTest.cpp
LOBJ = $(LFILES: .cpp=.o)

BFILES = ./test/BidirectionalIteratorTest.cpp
BOBJ = $(BFILES: .cpp=.o)

MAFILES = ./test/mapTest.cpp
MAOBJ = $(MAFILES: .cpp=.o)

QFILES = ./test/queueTest.cpp
QOBJ = $(QFILES: .cpp=.o)

RFILES = ./test/RandomAccessIteratorTest.cpp
ROBJ = $(RFILES: .cpp=.o)

SFILES = ./test/stackTest.cpp
SOBJ = $(SFILES: .cpp=.o)

VFILES = ./test/vectorTest.cpp
VOBJ = $(VFILES: .cpp=.o)

CXXFLAGS = -std=c++11
ifdef asan
 CXXFLAGS += -g -fsanitize=address -fno-omit-frame-pointer -O0
endif

ifeq ($(shell uname), Linux)
 ECHO = -e
endif

# Colours
DARK_GREEN	= \033[0;32m
GREEN		= \033[0;92m
END			= \033[0;0m

PREFIX		= $(DARK_GREEN)$(NAME) $(END)\xc2\xbb

all: $(NAME)

list:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Bundling executable... $(END)list"
	@$(CXX) $(CXXFLAGS) $(MOBJ) $(LOBJ) -o $@

bidirectionaliterator:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Bundling executable... $(END)bidirectionaliterator"
	@$(CXX) $(CXXFLAGS) $(MOBJ) $(BOBJ) -o $@

map:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Bundling executable... $(END)map"
	@$(CXX) $(CXXFLAGS) $(MOBJ) $(MAOBJ) -o $@

queue:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Bundling executable... $(END)queue"
	@$(CXX) $(CXXFLAGS) $(MOBJ) $(QOBJ) -o $@

randomiterator:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Bundling executable... $(END)randomiterator"
	@$(CXX) $(CXXFLAGS) $(MOBJ) $(ROBJ) -o $@

stack:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Bundling executable... $(END)stack"
	@$(CXX) $(CXXFLAGS) $(MOBJ) $(SOBJ) -o $@

vector:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Bundling executable... $(END)vector"
	@$(CXX) $(CXXFLAGS) $(MOBJ) $(VOBJ) -o $@


$(NAME): $(OBJS)
	@echo $(ECHO) "$(PREFIX)$(GREEN) Bundling executable... $(END)$(NAME)"
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	@echo $(ECHO) "$(PREFIX)$(GREEN) Compiling file $(END)$< $(GREEN)to $(END)$@"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@echo $(ECHO) "$(PREFIX)$(GREEN) Removing .o files $(END)$(OUT_DIR)"
	@rm -f $(OBJS)

fclean: clean
	@echo $(ECHO) "$(PREFIX)$(GREEN) Removing executable $(END)$(OUT_DIR)"
	@rm -rf $(NAME) list bidirectionaliterator map queue randomiterator stack vector

re: fclean all

.PHONY: clean fclean re all
