@echo off
echo ImageMagick fix libpng warning: iCCP: Not recognizing known sRGB profile ......
echo Search PNG in subdirs and process ...
set fn=F:\ImageMagick-7.1.0-Q16\magick.exe

for /f "tokens=*" %%i in ("F:/QT/myProject/CoinFile/res/ *.png") do "%fn%" "%%i" -strip "%%i"
pause
