CC = g++

TARGET := test
BUILDDIR := .build


.PHONY: clean tidy


$(TARGET): $(BUILDDIR)/main.o
	$(CC) $^ -o $@
	./$(TARGET)

$(BUILDDIR)/main.o: main.cpp $(BUILDDIR)
	$(CC) -c $< -o $@ 


$(BUILDDIR):
	mkdir $@

clean:
	rm -rf $(BUILDDIR)

tidy: clean
	rm -f $(TARGET)
