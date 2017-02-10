#ifndef __LINUX_SHELL_CMD__
#define __LINUX_SHELL_CMD__

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

#define LINUX_SHELL_CMD_BUFFER_SIZE 128
#ifdef FRM_WIN
std::string exec_shell_cmd(const char* cmd) {
    std::array<char, LINUX_SHELL_CMD_BUFFER_SIZE> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(_popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), LINUX_SHELL_CMD_BUFFER_SIZE, pipe.get()) != NULL)
            result += buffer.data();
    }
    _pclose(pipe);
    return result;
}
#else
std::string exec_shell_cmd(const char* cmd) {
    std::array<char, LINUX_SHELL_CMD_BUFFER_SIZE> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), LINUX_SHELL_CMD_BUFFER_SIZE, pipe.get()) != NULL)
            result += buffer.data();
    }
    pclose(pipe);
    return result;
}
#endif
#endif
