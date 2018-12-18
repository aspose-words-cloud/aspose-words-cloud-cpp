[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12


Add-Type -AssemblyName System.IO.Compression.FileSystem
function Unzip
{
    param([string]$zipfile, [string]$outpath)

    [System.IO.Compression.ZipFile]::ExtractToDirectory($zipfile, $outpath)
    Remove-Item -path $zipfile
}

mkdir "C://boost"

Unzip "downloads/boost.zip" "C://boost"
Start-Process msiexec.exe -Wait -ArgumentList '/i downloads/cmake.msi /quiet'
Start-Process msiexec.exe -Wait -ArgumentList '/i downloads/cppcheck.msi /quiet'

# Remove-Item -path sdksetup.msi
# Remove-Item -path cmake.msi
# Remove-Item -path cppcheck.msi

