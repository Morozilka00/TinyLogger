### TinyLogger

TinyLogger is a minimal header-only C++ logging library designed for simplicity and zero dependencies.

It is made for small projects, learning C++, game prototypes, and embedded-style applications where full logging frameworks are too heavy.

## Features
Header-only (just drop and use)
Info / Warn / Error logging
Custom log format support
File + console logging

## usage

```cpp
#include "Tinylogger.hpp"
#include <iostream>
#include <fstream>

int main() {
    tinylog::config c;
    tinylog::setconfig(c, 
        "logs.txt",
        "[%Y-%m-%d %H:%M:%S] [INFO] ",
         "[%Y-%m-%d %H:%M:%S] [WARN] ",
          "[%Y-%m-%d %H:%M:%S] [ERROR] "
        );
    tinylog::clear(c);
    
    tinylog::info(c, "Server started");
    tinylog::warn(c, "Low memory");
    tinylog::error(c, "Crash detected");

    return 0;
}
