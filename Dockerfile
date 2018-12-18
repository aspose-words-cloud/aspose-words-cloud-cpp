FROM compulim/msbuild
MAINTAINER Evgeny Kuleshov (evgeny.kuleshov@aspose.com) 

ENV BOOST_URL="https://dl.bintray.com/boostorg/release/1.68.0/source/boost_1_68_0.zip" \
    CMAKE_URL="https://github.com/Kitware/CMake/releases/download/v3.13.1/cmake-3.13.1-win64-x64.msi" \
    CPPCHECK_URL="http://github.com/danmar/cppcheck/releases/download/1.86/cppcheck-1.86-x64-Setup.msi" \
    WIN_SDK_URL="https://go.microsoft.com/fwlink/p/?LinkId=323507" \
    BOOST_ROOT="C://boost" 

WORKDIR C://

ADD https://aka.ms/vs/15/release/vs_buildtools.exe downloads\vs_buildtools.exe
ADD ${BOOST_URL} downloads/boost.zip
ADD ${CMAKE_URL} downloads/cmake.msi
ADD ${CPPCHECK_URL} downloads/cppcheck.msi

RUN C:\downloads\vs_buildtools.exe --quiet --wait --norestart --nocache \
    --installPath C:\BuildTools \
    --add Microsoft.VisualStudio.Component.Windows81SDK || IF "%ERRORLEVEL%"=="3010" EXIT 0

COPY loadboost.ps1 loadboost.ps1

RUN powershell /loadboost.ps1

RUN setx path "%path%;C:/Program Files/CMake/bin"