@echo off
set /p birth_year=Enter your birth year:
set current_year=%date:~10,4%
set /a age=current_year - %birth_year%
echo your age is:%age%
pause