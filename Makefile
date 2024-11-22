CC := g++
CC_FLAGS := -g -std=c++11
BUILD_TARGET := aee.out
SOURCES := calculator.cpp state.cpp input_state.cpp result_state.cpp state_handler.cpp operators.cpp
HEADERS := state.h input_state.h result_state.h state_handler.h
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
