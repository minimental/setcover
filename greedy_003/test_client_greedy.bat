@echo off
for /F %%G in ('dir .\data /b') do test_client_greedy.exe .\data\%%G