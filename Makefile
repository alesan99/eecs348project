CC := g++
CC_FLAGS := -g
BUILD_TARGET := aee.out
SOURCES := calculator.cpp
HEADERS := state_handler.h state.h result_state.h input_state.h
OBJS=$(addprefix obj/,$(subst .cpp,.o,$(SOURCES)))
OBJDIR= obj
SRCDIR= src
default: clean debug

debug:	$(OBJS)
	$(CC) $(CC_FLAGS) -o bin/$(BUILD_TARGET) $(OBJS)
	
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CC_FLAGS) -o $@ -c $<
	
clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(SRCDIR)/$(BUILD_TARGET)
setup:
	mkdir -p bin/
	mkdir -p obj/
