set CMakeBuildFolder=%1
set ProjectName=%2


C:\Qt\5.15.1\msvc2019_64\bin\windeployqt.exe  %CMakeBuildFolder%/Debug/%ProjectName%.exe 
C:\Qt\5.15.1\msvc2019_64\bin\windeployqt.exe  %CMakeBuildFolder%/Release/%ProjectName%.exe 