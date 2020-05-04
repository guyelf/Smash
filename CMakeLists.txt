cmake_minimum_required(VERSION 3.13)
project(smash)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

#add_custom_target(OS_Wet1 COMMAND make
#        CLION_EXE_DIR=${PROJECT_BINARY_DIR})


add_executable(smash
        smash.cpp
        Commands.cpp
        signals.cpp
        ShowPidCommand.cpp
        GetCurrDirCommand.cpp
        ChangeDirCommand.cpp
        MyExceptions.h
        Wrappers.cpp Wrappers.h
        PipeCommand.cpp
        RedirectionCommand.cpp
        killCommand.cpp
        BackgroundCommand.cpp
        ForegroundCommand.cpp
        QuitCommand.cpp ExternalCommand.cpp
        JobsList.cpp ChangePrompt.cpp
        CopyCommand.cpp
        quit_nojobs2.exp
        quit_nojobs2.in)

#todo: Might come handy, otherwise remove //system_functions.h cmake-build-debug/BuiltInCommand.cpp