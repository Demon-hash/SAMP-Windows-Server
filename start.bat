@echo off
IF EXIST "server_log.txt" DEL "server_log.txt" /s
start "" samp-server.exe
exit