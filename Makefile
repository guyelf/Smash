#TODO: replace ID with your own IDS, for example: 123456789_123456789
SUBMITTERS := 312146954_205375504
COMPILER := g++
COMPILER_FLAGS := --std=c++11 -Wall
SRCS := Commands.cpp signals.cpp smash.cpp BackgroundCommand.cpp ChangeDirCommand.cpp ChangePrompt.cpp CopyCommand.cpp ExternalCommand.cpp ForegroundCommand.cpp GetCurrDirCommand.cpp JobsList.cpp killCommand.cpp PipeCommand.cpp QuitCommand.cpp RedirectionCommand.cpp ShowPidCommand.cpp Wrappers.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
HDRS := Commands.h signals.h MyExceptions.h Wrappers.h #put header files
TESTS_INPUTS := $(wildcard test_input*.txt)
TESTS_OUTPUTS := $(subst input,output,$(TESTS_INPUTS))
SMASH_BIN := smash

$(SMASH_BIN): $(OBJS)
	$(COMPILER) $(COMPILER_FLAGS) $^ -o $@

$(OBJS): %.o: %.cpp
	$(COMPILER) $(COMPILER_FLAGS) -c $^

zip: $(SRCS) $(HDRS)
	zip $(SUBMITTERS).zip $^ submitters.txt Makefile

clean:
	rm -rf $(SMASH_BIN) $(OBJS) $(TESTS_OUTPUTS) 
	rm -rf $(SUBMITTERS).zip
