CC := g++
CC_FLAGS := -g -std=c++17
BUILD_TARGET := aee.out
SOURCES := calculator.cpp input_state.cpp result_state.cpp state_handler.cpp operators.cpp execute.cpp input.cpp
HEADERS := state.h input_state.h result_state.h state_handler.h execute.h operators.h input.h
OBJS=$(addprefix obj/,$(subst .cpp,.o,$(SOURCES)))
OBJDIR= obj
SRCDIR= src
default: debug

debug:	$(OBJS)
	$(CC) $(CC_FLAGS) -o bin/$(BUILD_TARGET) $(OBJS)
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CC_FLAGS) -o $@ -c $<
	
clean:
	rm -f $(OBJDIR)/*.o
	rm -f bin/$(BUILD_TARGET)
setup:
	mkdir -p bin/
	mkdir -p obj/
test: setup debug
	bash ./run_tests.sh
release: $(OBJS)
	$(CC) $(CC_FLAGS) -Wall -O2 -o bin/AEE_release $(OBJS)