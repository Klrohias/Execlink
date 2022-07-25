# Execlink
![Execlink](https://socialify.git.ci/Klrohias/Execlink/image?description=1&font=Source%20Code%20Pro&forks=1&issues=1&language=1&name=1&owner=1&pulls=1&stargazers=1&theme=Dark)
> Create a executable file to replace another executable file.

# Background
One day I found that `ld.gold.exe` in `NDK21d` has some problems, I have `NDK24` in my disk, there is a `ld.lld.exe` in it.     
But I can't rename `ld.lld.exe` to `ld.gold.exe` and replace directly, so I write a simple program to execute `ld.lld.exe`.     

# Usage
in `Visual Studio Developer PowerShell`:
```powershell
.\BUILD.ps1 .\cmd.ps1
.\BUILD.ps1 .\ld.gold.ps1
```
Then, you can get `ld.gold.exe` and `link_to_cmd.exe` in `_OUTPUT` directory.

```
PS D:\xxx> .\_OUTPUT\link_to_cmd.exe /r dir
 Volume in drive D is data1
 Volume Serial Number is xxxx-xxxx

 Directory of D:\xxx

07/25/2022  03:49 PM    <DIR>          .
07/25/2022  03:49 PM    <DIR>          ..
07/25/2022  03:33 PM                17 .gitignore
07/25/2022  03:42 PM               736 BUILD.ps1
07/25/2022  03:28 PM                61 CLEAN.ps1
07/25/2022  03:43 PM               114 cmd.ps1
07/25/2022  03:34 PM               193 ld.gold.ps1
07/25/2022  03:48 PM             1,090 LICENSE
07/25/2022  03:32 PM             1,981 source.cpp
07/25/2022  03:31 PM    <DIR>          _CACHE
07/25/2022  03:44 PM    <DIR>          _OUTPUT
               7 File(s)          4,192 bytes
               4 Dir(s)  83,799,851,008 bytes free
```
Just like execute `cmd.exe` directly.     
Same, you can write your own configuration based on cmd.ps1 or ld.gold.ps1 and use BUILD.ps1 to generate.

# License
`MIT`
