@ECHO OFF
CALL cl.bat /EHsc ROUTE.cpp
echo "build success"
echo "running.."

CALL ROUTE.exe
echo "ROUTE.exe exited.."