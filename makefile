CC = g++
CPPFLAGS = -Wall -g
BIN_DIR = bin

all: clean $(BIN_DIR)/btcolor

$(BIN_DIR)/btcolor: $(BIN_DIR)/rbbst.o $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) $(BIN_DIR)/rbbst.o btcolor.cpp -o $(BIN_DIR)/btcolor:

$(BIN_DIR)/rbbst.o: bst.h rbbst.h $(BIN_DIR)/.dirstamp
	$(CC) $(CPPFLAGS) rbbst.h -o $(BIN_DIR)/rbbst.o

$(BIN_DIR)/.dirstamp:
	-@mkdir -p $(BIN_DIR)
	-@touch $@

clean:
	-@rm -rf $(BIN_DIR)