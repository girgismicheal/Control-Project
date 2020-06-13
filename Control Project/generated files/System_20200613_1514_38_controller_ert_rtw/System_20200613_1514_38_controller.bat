@if not "%MINGW_ROOT%" == "" (@set "PATH=%PATH%;%MINGW_ROOT%")

cd .

if "%1"=="" ("G:\matlab\R2018a\bin\win64\gmake"  -f System_20200613_1514_38_controller.mk all) else ("G:\matlab\R2018a\bin\win64\gmake"  -f System_20200613_1514_38_controller.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
