# ATL_TEXT_SEARCHER

An ATL project, contains two COM objects.
One is to scan and find matches file paths, one is to scan files to find matched lines.

A client written in C#, to invoke COM objects.

Download this project and then open it in Visual Studio(v141+) in Administrator, build the COM project then run the project.
Right now the dll is linked to the C# by path reference.
To run a real COM project, find the file in your file folder, open a CMD window in Administrator,
use "regsvr32.exe your_COM_dll_path" to register the COM, then remove the path reference of the C# project, add a new reference from COM option.
You will find a new COM named the same as the project. Add it, and run the C# project.

compile.bat run.bat clean.bat files are provided.

A Fake version of ATL implemented on Linux use pure C++ in both Server and Client is provided here: https://github.com/xwang186/FakeATLonLinux
Linux does not have COM, but the fake implementation can be helpful in deeply understanding how COM works.
