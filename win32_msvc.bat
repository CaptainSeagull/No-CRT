@echo off

cd %~dp0

rem Require Visual Studio's cl
where cl >nul 2>nul
IF %ERRORLEVEL% NEQ 0 (
    echo "Error: cl is not in the path. Please setup Visual Studio to do cl builds by calling vcvarsall.bat"
    goto skipEverything
)

IF NOT EXIST "build" mkdir "build"
pushd "build"
cl -FeTest -nologo -Gm- -GR- -FC -Zi -Oi -GS- -Gs9999999 -MTd -EHa- -Od ../main.cpp -FmTest.map -link -nodefaultlib kernel32.lib user32.lib -stack:0x100000,0x100000 -subsystem:windows,5.2
popd

:skipEverything