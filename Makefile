CURR_DIR=$(shell pwd)

BIN_DIR=bin
RELEASE_DIR=$(BIN_DIR)/Release
UNITTEST_DIR=$(BIN_DIR)/UnitTests
EXAMPLEACQLIB_DIR=$(RELEASE_DIR)/acqlibs

release: exampleacqlib
	mkdir -p $(RELEASE_DIR)
	cd $(RELEASE_DIR) && cmake -DCMAKE_BUILD_TYPE=Release "$(CURR_DIR)"
	make -C $(RELEASE_DIR)

unittests:
	mkdir -p $(UNITTEST_DIR)
	cd $(UNITTEST_DIR) && cmake -DCMAKE_BUILD_TYPE=UnitTests "$(CURR_DIR)"
	make -C $(UNITTEST_DIR)
	$(UNITTEST_DIR)/EnvDataLogger_UnitTests --gtest_output=xml:$(UNITTEST_DIR)/EnvDataLogger_UnitTests.xml
	
exampleacqlib:
	mkdir -p $(EXAMPLEACQLIB_DIR)
	cd $(EXAMPLEACQLIB_DIR) && cmake "$(CURR_DIR)/ExampleAcqLib"
	make -C $(EXAMPLEACQLIB_DIR)

clean: clean_main clean_unittests

clean_main:
	rm -rf $(RELEASE_DIR)/*

clean_unittests:
	rm -rf $(UNITTEST_DIR)/*
