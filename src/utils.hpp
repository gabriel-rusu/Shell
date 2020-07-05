#pragma once
#include <string>
#include <iostream>


const int CHDIR = 1;
const int SETUID = 2;
const int SETGUID = 3;
const int SETPRIORITY = 4;
const int SYMLINC = 5;

std::string &rtrim(std::string &str, const std::string &chars  = "\t\n\v\f\r ");
std::string &ltrim(std::string &str, const std::string &chars  = "\t\n\v\f\r ");