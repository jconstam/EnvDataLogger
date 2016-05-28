CURR_DIR=$(shell pwd)

RELEASE_DIR="$(CURR_DIR)/bin_release"
UNITTEST_DIR="$(CURR_DIR)/bin_unittests"

release:
	mkdir -p $(RELEASE_DIR)
	cd $(RELEASE_DIR) && cmake -DCMAKE_BUILD_TYPE=Release ..
	make -C $(RELEASE_DIR)

unittests:
	mkdir -p $(UNITTEST_DIR)
	cd $(UNITTEST_DIR) && cmake -DCMAKE_BUILD_TYPE=UnitTests ..
	make -C $(UNITTEST_DIR)
	./bin_unittests/EnvDataLogger_UnitTests

clean: clean_main clean_unittests

clean_main:
	rm -rf $(RELEASE_DIR)/*

clean_unittests:
	rm -rf $(UNITTEST_DIR)/*
