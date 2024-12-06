CC := g++
CC_FLAGS := -g
BUILD_TARGET := aee.out
SOURCES := test.cpp math.cpp
OBJS=$(addprefix obj/,$(subst .cpp,.o,$(SOURCES)))
OBJDIR= obj
SRCDIR= src
default: debug

debug:	$(OBJS)
	mkdir -p bin/
	$(CC) $(CC_FLAGS) -o bin/$(BUILD_TARGET) $(OBJS)
	
$(OBJDIR)/%.o: %.cpp
	$(CC) $(CC_FLAGS) -o $@ -c $<
	
clean:
	rm -f $(OBJDIR)/*.o
	rm -f bin/$(BUILD_TARGET)