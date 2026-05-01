//Tinylogger.hpp
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include<iostream>
#include<fstream>

namespace tinylog {
    struct config {
        std::string FormatI;
        std::string FormatW;
        std::string FormatE;
    
        std::string file;
    };
    void setconfig(config& c, std::string f, const char* FormatInf, const char* FormatWarn, const char* FormatError) {
        c.file = f;
        c.FormatI = FormatInf;
        c.FormatW = FormatWarn;
        c.FormatE = FormatError;
        return;
    }
    void clear(config& c) {
        FILE* f = fopen(c.file.c_str(), "w");
        fprintf(f, "");
        fclose(f);
    }
    void info(config& c, std::string t) {
        time_t now = time(0);

        tm ltm;
        localtime_s(&ltm, &now);

        char buff[128];
        strftime(buff, sizeof(buff), c.FormatI.c_str(), &ltm);

        FILE* f = fopen(c.file.c_str(), "a");

        std::string m = std::string(buff) + t.c_str() + "\n";

        fprintf(f, "%s", m.c_str());
        fprintf(stdout, "%s", m.c_str());
        fclose(f);
    }


    void warn(config& c, std::string t) {
        time_t now = time(0);

        tm ltm;
        localtime_s(&ltm, &now);

        char buff[128];
        strftime(buff, sizeof(buff), c.FormatW.c_str(), &ltm);

        FILE* f = fopen(c.file.c_str(), "a");

        std::string m = std::string(buff) + t.c_str() + "\n";

        fprintf(f, "%s", m.c_str());
        fprintf(stdout, "%s", m.c_str());
        fclose(f);
    }


    void error(config& c, std::string t) {
        time_t now = time(0);

        tm ltm;
        localtime_s(&ltm, &now);

        char buff[128];
        strftime(buff, sizeof(buff), c.FormatE.c_str(), &ltm);

        FILE* f = fopen(c.file.c_str(), "a");

        std::string m = std::string(buff) + t.c_str() + "\n";

        fprintf(f, "%s", m.c_str());
        fprintf(stdout, "%s", m.c_str());
        fclose(f);
    }
}