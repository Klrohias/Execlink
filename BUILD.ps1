
if ($args.Length -eq 0) {
    exit;
}
$config = $args[0];

if ((Test-Path -Path .\_CACHE\) -eq $False) {
    mkdir .\_CACHE
}
if ((Test-Path -Path .\_OUTPUT\) -eq $False) {
    mkdir .\_OUTPUT
}

. $config;

"`"$TARGET`"" | Out-File .\_CACHE\target.inc;

$builtBlacklists = '';
if ($BLACKLISTS -ne "") {
    ($BLACKLISTS -Replace "`r", "" -Split "`n") | ForEach-Object {
        $builtBlacklists += '"' + $_ + '", ' + "`n";
    }
}
$builtBlacklists | Out-File .\_CACHE\blacklists.inc;

$buildConfig = '';
if ($DEBUG) {
    $buildConfig += '#define _ENABLE_DEBUG' + "`n"
}
$buildConfig | Out-File .\_CACHE\config.inc

cl source.cpp /std:c++latest;
mv -Force .\source.exe .\_OUTPUT\$NAME;
rm .\source.obj