# FROM compulim/msbuild
FROM microsoft/windowsservercore

# Visual Studio
ADD https://aka.ms/vs/15/release/vs_buildtools.exe vs_buildtools.exe
RUN C:\vs_BuildTools.exe \
        --add Microsoft.VisualStudio.Product.BuildTools \
        --add Microsoft.VisualStudio.Workload.MSBuildTools \
        --add Microsoft.VisualStudio.Workload.VCTools \
        --add Microsoft.VisualStudio.Component.VC.ATL \
        --add Microsoft.VisualStudio.Component.VC.ATLMFC \
        --includeRecommended \
        --passive \
        --norestart \
        --wait \
        --nocache
RUN del C:\vs_BuildTools.exe 

# Chocolatey & Git
RUN powershell -NoProfile -InputFormat None -ExecutionPolicy Bypass -Command "iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))"
RUN %ALLUSERSPROFILE%\chocolatey\bin\choco.exe install -y git

WORKDIR C://

MAINTAINER Evgeny Kuleshov (evgeny.kuleshov@aspose.com) 

ENV BOOST_URL="https://downloads.sourceforge.net/project/boost/boost-binaries/1.68.0/boost_1_68_0-msvc-14.0-64.exe?r=https%3A%2F%2Fsourceforge.net%2Fprojects%2Fboost%2Ffiles%2Fboost-binaries%2F1.68.0%2Fboost_1_68_0-msvc-14.0-64.exe%2Fdownload&ts=1545814847" \
    CMAKE_URL="https://github.com/Kitware/CMake/releases/download/v3.13.1/cmake-3.13.1-win64-x64.msi" \
    CPPCHECK_URL="http://github.com/danmar/cppcheck/releases/download/1.86/cppcheck-1.86-x64-Setup.msi" \
    WIN_SDK_URL="https://go.microsoft.com/fwlink/p/?LinkId=323507" \
    BOOST_ROOT="C://boost" \
    GIT_VERSION=2.15.1 \
    GIT_PATCH_VERSION=2
WORKDIR C://


ADD ${BOOST_URL} boost.exe
ADD ${CMAKE_URL} cmake.msi
ADD ${CPPCHECK_URL} cppcheck.msi


RUN powershell -Command $ErrorActionPreference = 'Stop' ; \
    [Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12 ; \
    Invoke-WebRequest $('https://github.com/git-for-windows/git/releases/download/v{0}.windows.{1}/MinGit-{0}.{1}-busybox-64-bit.zip' -f $env:GIT_VERSION, $env:GIT_PATCH_VERSION) -OutFile 'mingit.zip' -UseBasicParsing ; \
    Expand-Archive mingit.zip -DestinationPath c:\mingit ; \
    Remove-Item mingit.zip -Force ; \
    setx /M PATH $('c:\mingit\cmd;{0}' -f $env:PATH)

COPY installSW.ps1 installSW.ps1

RUN powershell Set-ExecutionPolicy RemoteSigned

RUN powershell /installSW.ps1

RUN setx path "%path%;C:/Program Files/CMake/bin;C:/Program Files/Cppcheck"


RUN git clone https://github.com/Microsoft/cpprestsdk
RUN mkdir build & mkdir install
RUN cmake -G "Visual Studio 15 2017" -Thost=x64 -Ax64 -DCPPREST_EXCLUDE_WEBSOCKETS=ON -DCPPREST_EXCLUDE_COMPRESSION=ON -DCPPREST_EXCLUDE_BROTLI=ON -DBUILD_TESTS=OFF -DBUILD_SAMPLES=OFF -DCMAKE_INSTALL_PREFIX=install\cpprestsdk -S cpprestsdk -B build
RUN cmake --build build --config Debug --target install
RUN cmake --build build --config Release --target install
