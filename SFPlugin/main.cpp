#include <Windows.h>
#include "main.h"

#define PLUGIN_NAME "\\Command_Factory"
#define EMPTY_COMMAND "N/A"
#define MAX_SIZE 100

#include <regex>
#include <sstream>
#include <string>
#include <vector>
#include <memory>
#include <utility>
#include <fstream>
#include <algorithm> 
#include <cctype>

SAMPFUNCS *SF = new SAMPFUNCS();

std::unordered_map<std::string, std::pair<std::regex, std::string>> syntaxes = {
	{ "cfcreate",{ std::regex("\\/[a-zA-Z0-9_]+ \\/.+"), "<custom_command> <in_game_command>" } },
	{ "cfdelete",{ std::regex("\(\/)?[a-zA-Z0-9_]+"), "<custom_command_to_delete>" } }
};

void chat_say(std::string message) {
	char* message_c = new char[message.size() + 1];
	strcpy_s(message_c, 300, message.c_str());

	SF->getSAMP()->getPlayers()->pLocalPlayer->Say(message_c);
	free(message_c);
}

void chat_msg(DWORD color, std::string message) {
	char* message_c = new char[message.size() + 1];
	strcpy_s(message_c, 300, message.c_str());

	SF->getSAMP()->getChat()->AddChatMessage(color, message_c);
	free(message_c);
}

static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

std::vector<void(__stdcall*) (std::string)> functions;
std::vector<pair<std::string, std::string>> commands(100, std::make_pair(EMPTY_COMMAND,EMPTY_COMMAND));
std::fstream file;
std::string  path;

const int line = __LINE__ + 2;
void initialize() {
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
	functions.push_back(static_cast<void(__stdcall*) (std::string)>([](std::string params) { chat_say(commands[__LINE__ - line].second + " " + params); }));
}


int findFirstFreeFunction()
{
	int i = 0;
	for (auto comanda : commands)
	{
		if (comanda.first == EMPTY_COMMAND)
		{
			return i;
		}
		i++;
	}
	
	return -1;
}

bool findCommand(std::string cmd)
{
	if (cmd[0] == '/')
		cmd.erase(0, 1);
	for (auto comanda : commands)
	{
		if (comanda.first == cmd)
		{
			return true;
		}
	}

	return false;
}

void __stdcall cflist(std::string params) {
	chat_msg(0x8cff66, "{8000ff}[Command Factory]{8cff66} The list of saved commands is:");
	int i = 1;
	for(auto comanda: commands)
	{
		if (comanda.first != EMPTY_COMMAND)
			chat_msg(0xFFA1B2, "  " + std::to_string(i++) + ". [/" + comanda.first + "] --> [" + comanda.second + "]");
	}
}

void __stdcall cfcreate(std::string params) {
	std::regex syntax_regex = syntaxes[__FUNCTION__].first;

	if (!std::regex_match(params, syntax_regex)) {
		std::string syntax_text = syntaxes[__FUNCTION__].second;
		chat_msg(0xFFA500, "{8000ff}[Command Factory]{FFA500} Syntax: " + syntax_text + "!");
		return;
	}

	int position;
	std::stringstream ss(params);
	std::string custom_command; ss >> custom_command;
	custom_command.erase(0, 1);

	if (findCommand(custom_command))
	{
		chat_msg(0xd22d2d, "{8000ff}[Command Factory]{d22d2d} Error: Command was already created, please use [/cfdelete " + custom_command + "] and retry.");
		return;
	}

	std::string in_game_command; std::getline(ss, in_game_command);
	in_game_command.erase(0, 1);
	rtrim(in_game_command);

	std::pair<std::string, std::string> cmd_pair = std::make_pair(custom_command, in_game_command);

	position = findFirstFreeFunction();
	if (position == -1)
	{
		chat_msg(0xd22d2d, "{8000ff}[Command Factory]{d22d2d} Maximum number of stored commands reached!");
		return;
	}

	commands[position] = cmd_pair;
	writeIniFile(cmd_pair);

	SF->getSAMP()->registerChatCommand(custom_command, functions.at(position));
}

void __stdcall cfdelete(std::string params)
{
	std::regex syntax_regex = syntaxes[__FUNCTION__].first;

	if (!std::regex_match(params, syntax_regex)) {
		std::string syntax_text = syntaxes[__FUNCTION__].second;
		chat_msg(0xFFA500, "{8000ff}[Command Factory]{FFA500} Syntax: " + syntax_text + "!");
		return;
	}	
	
	file.open(path.c_str(), std::ios::out);
	bool deleted = false;

	std::stringstream ss(params);
	std::string custom_command; ss >> custom_command;
	if (custom_command[0] == '/')
		custom_command.erase(0, 1);

	char cstr_cmd[301];
	for (auto it = commands.begin(); it != commands.end(); it++)
	{
		if ((*it).first == custom_command )
		{
			strcpy_s(cstr_cmd, 300, custom_command.c_str());
			SF->getSAMP()->getInput()->UnregisterClientCommand(cstr_cmd);
			chat_msg(0xff00bf, "{8000ff}[Command Factory]{ff00bf} Deleted [/" + (*it).first + "] --> [" + (*it).second + "]");
			(*it).first = EMPTY_COMMAND;
			deleted = true;
		}
		else if ( (*it).first != EMPTY_COMMAND)
		{
			file << "/" << (*it).first << " " << (*it).second << "\n";
		}
	}
	if (!deleted)
		chat_msg(0xd22d2d, "{8000ff}[Command Factory]{d22d2d} Error: Command was not found!");
	file.close();
}

void readIniFile()
{
	chat_msg(0x8cff66, "{8000ff}[Command Factory]{8cff66} Initializing user defined commands...");
	file.open(path.c_str(), std::ios::in);
	std::string line;
	int position;
	int i = 1;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string custom_command; ss >> custom_command;

		std::string in_game_command; 
		std::getline(ss, in_game_command);
		in_game_command.erase(0, 1);
		rtrim(in_game_command);

		chat_msg(0xFFA1B2, "  " + std::to_string(i++) + ". [" + custom_command + "] --> [" + in_game_command + "]");

		custom_command.erase(0, 1);

		std::pair<std::string, std::string> cmd_pair = std::make_pair(custom_command, in_game_command);

		position = findFirstFreeFunction();
		if (position == -1)
		{
			chat_msg(0xd22d2d, "{8000ff}[Command Factory]{d22d2d} Maximum number of stored commands reached!");
			return;
		}

		commands[position] = cmd_pair;

		SF->getSAMP()->registerChatCommand(custom_command, functions.at(position));
	}
	file.close();
	chat_msg(0x8cff66, "{8000ff}[Command Factory]{8cff66} Commands successfully loaded!");
}

void writeIniFile(std::pair<std::string, std::string> cmd_pair)
{
	file.open(path.c_str(), std::ios::app);
	std::string line;
	chat_msg(0x66FF8C, "{8000ff}[Command Factory]{66FF8C} Saved [/" + cmd_pair.first + "] --> [" + cmd_pair.second + "]");
	file << "/" << cmd_pair.first << " " << cmd_pair.second << "\n";
	file.close();
}

void __stdcall mainloop()
{
	static bool initialized = false;
	
	if (!initialized)
	{
		if (GAME && GAME->GetSystemState() == eSystemState::GS_PLAYING_GAME && SF->getSAMP()->IsInitialized())
		{
			initialize();
			initialized = true;
			path = getenv("appdata");
			path += PLUGIN_NAME;
			mkdir(path.c_str());
			path += "\\cmd_creator.ini";
			
			readIniFile();
			SF->getSAMP()->registerChatCommand("cfcreate", cfcreate);
			SF->getSAMP()->registerChatCommand("cfdelete", cfdelete);
			SF->getSAMP()->registerChatCommand("cflist", cflist);
		}
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReasonForCall, LPVOID lpReserved)
{
	if (dwReasonForCall == DLL_PROCESS_ATTACH)
		SF->initPlugin(mainloop, hModule);
	return TRUE;
}
