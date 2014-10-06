#ifndef COMMAND_H
#define COMMAND

void command_dispatcher(const char* command);

void join(int group_id);

void send(int group_id, const char* message_body);

void leave(const char* arg);

void quit();

#endif
