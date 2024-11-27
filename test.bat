@echo off
setlocal enabledelayedexpansion

set PROGRAM=%~1

for /L %%P in (4,1,12) do (
    set /A N=1
    for /L %%I in (1,1,%%P) do (
        set /A N=!N!*2
    )
    
    echo Executing !PROGRAM! with n = !N!
    .\!PROGRAM! !N!
)
endlocal