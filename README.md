# TinyLogger

TinyLogger (Header Only) — lightweight C++ logging library for simple file and console logging.

Supports:
- Info / Warn / Error levels
- Custom log formats
- File logging
- Simple configuration API

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
    
    tinylog::info(c, "Info");
    tinylog::warn(c, "Warn");
    tinylog::error(c, "Error");

    return 0;
}
