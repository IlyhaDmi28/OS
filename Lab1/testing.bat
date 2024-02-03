C:\Windows\System32\chcp 65001
@echo off

echo --строка параметров: %*

echo --Параметр 1: %1
shift
echo --Параметр 2: %1

for /l %%P in (1, 1, 5) do (
    echo --Итерация: %%P
	shift
)

 