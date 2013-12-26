CSO-DAX COMMPRESSOR 0.34 IS NOW AVAILABLE ON LINUX

2 method of install (binaries et compilation)
---------------------

Type 1: Binaries copy
*--------------------------
-> Copy the 3 files in the bin folder in a folder referenced by the PATH varaible (for exemple /usr/bin)
-> For start program just run a console and run "csoCompiler"
Warning for this method you need to have the following librairy 
- zlib
- QT version 3.3.5 (includ on suse 10.1)

Type 2: Source compilation
---------------------------------
-> Go to src folder
-> Be sure you have this librairy and compilator:
        QT(3.3.5) et zlib(1.2.3) et gcc récent
-> In the src directory run make command and wait the compilation is over
-> When the compilation is over copy the 3 files (ciso daxcr et csoCompiler) in a folder referenced by the PATH varaible (for exemple /usr/bin)
->For run program start a command prompt and run csoCompiler