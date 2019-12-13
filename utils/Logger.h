#pragma once
#include <string>
#include <stdio.h>
#define LOG_MSG_SIZE 128


enum LogStatus {
	LOG_INFO,
	LOG_WARNING,
	LOG_ERROR,
	LOG_CRITICAL,
	LOG_DEBUG
};

class Logger
{
	static const char* logFileName;

	static const char* addStatusPrefix(LogStatus status) {
		switch (status) {
		case LOG_INFO:
			return "[INFO] ";
		case LOG_WARNING:
			return "[WARNING] ";
		case LOG_ERROR:
			return "[ERROR] ";
		case LOG_CRITICAL:
			return "[CRITICAL] ";
		case LOG_DEBUG:
			return "[DEBUG] ";
		}
	}

	static void writeMessageToLogFile(const char* text) {
		FILE* fp;
		fopen_s(&fp, logFileName, "a+");
		if (fp != 0) {
			fprintf_s(fp, text);
			fclose(fp);
		}
	}
public:

	static void Log(LogStatus status, const char* msg) {
		char finalMessage[LOG_MSG_SIZE] = "";
		const char* prefix = addStatusPrefix(status);
		strncat(finalMessage, prefix, strlen(prefix));
		strncat(finalMessage, msg, strlen(msg));
		strncat(finalMessage, "\n", strlen("\n"));
		writeMessageToLogFile(finalMessage);
#ifdef _DEBUG
		printf(finalMessage);
#endif
	}
};



