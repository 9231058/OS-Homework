#ifndef ERROR_FUNCTIONS_H
#define ERROR_FUNCTIONS_H

void errMsg(const char *format, ...);

void errExit(const char *format, ...);

void err_exit(const char *format, ...);

void errExitEN(int errnum, const char *format, ...);

void fatal(const char *format, ...);

void usageErr(const char *format, ...);

void cmdLineErr(const char *format, ...);

#endif
