#pragma once

#include "SAMPFUNCS_API.h"
#include "game_api.h"

extern SAMPFUNCS *SF;

void readIniFile();
void writeIniFile(std::pair<std::string, std::string>);
void __stdcall cfcreate(std::string params);
void chat_msg(DWORD color, std::string message);
void chat_say(std::string message);
