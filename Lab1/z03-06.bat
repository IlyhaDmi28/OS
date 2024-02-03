@echo off



echo --строка параметров: %*

if "%1" == "" goto HELP

echo --режим = %1
echo --имя файла = %2

if "%1" equ "создать" goto CREATE
if "%1" equ "удалить" goto DELETE

goto NOTRIGHTCOMMANDEXCEPTION

exit /B 1

:CREATE

if "%2" equ "" goto NOTHAVEFILENAMEEXCEPTION

if exist %2 goto FILEALREDYDEXISTSEXCEPTION

NUL> %2

echo Создание %2 успешно выполнено

pause

exit /B 1

:DELETE

if "%2" equ "" goto NOTHAVEFILENAMEEXCEPTION

if not exist %2 goto FILENOTFOUNDEXCEPTION

DEL %2

echo Удаление %2 успешно выполнено

pause

exit /B 1

:HELP

echo --режим: пусто
echo --имя файла: пусто
echo ---++ режим = {создать, удалить}
echo ---++ файл = имя файла


exit /B 1

:NOTRIGHTCOMMANDEXCEPTION

echo Ошибка: Режим задан не корректно

exit /B 1

:NOTHAVEFILENAMEEXCEPTION

echo Ошибка: Имя файла не задано

exit /B 1

:FILENOTFOUNDEXCEPTION

echo Ошибка: Фаил не найден

exit /B 1

:FILEALREDYDEXISTSEXCEPTION

echo Ошибка: Файл уже существует

exit /B 1