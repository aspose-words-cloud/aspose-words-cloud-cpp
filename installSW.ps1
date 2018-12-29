Set-ExecutionPolicy Unrestricted
[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12


Add-Type -AssemblyName System.IO.Compression.FileSystem
function Unzip
{
    param([string]$zipfile, [string]$outpath)

    [System.IO.Compression.ZipFile]::ExtractToDirectory($zipfile, $outpath)
    Remove-Item -path $zipfile
}

# Unzip "boost.zip" "C://boost"
START-PROCESS -WAIT -FilePath ./boost.exe -ArgumentList "/VERYSILENT"
Write-Host "Installing cmake"
Start-Process msiexec.exe -Wait -ArgumentList '/i cmake.msi /quiet'
Write-Host "Cmake installed"
Remove-Item -path cmake.msi

Write-Host "Installing cppcheck"
Start-Process msiexec.exe -Wait -ArgumentList '/i cppcheck.msi /quiet'
Write-Host "Cppcheck installed"
Remove-Item -path cppcheck.msi    

Set-Location C:/
