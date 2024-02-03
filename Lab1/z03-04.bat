
@echo off
echo --строка параметров: %* 
echo --параметр 1: %1
echo --параметр 2: %2
echo --параметр 3: %3
set /a a=%1 + %2
echo -- %1 + %2 = %a%
set /a a=%1 * %2
echo -- %1 * %2 = %a%
set /a a=%1 / %2
echo -- %3 / %2 = %a%
set /a a=%2 - %1
echo -- %2 - %1 = %a%
set /a a=(%2 - %1) * (%1 - %2)
echo -- (%2 - %1) * (%1 - %2) = %a%
