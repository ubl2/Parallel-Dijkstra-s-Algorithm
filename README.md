# Parallel-Dijkstra-s-Algorithm
This program is to use MPI Library to Parallelize Dijkstra's algorithm. This would increase the efficiency with which we can find shortest distance from one source to multiple destinations. Used GCP to compare the run times on various machines with different machine configurations.

<h2> How to run the code on local machine</h2>
1. Install MinGW from https://www.mingw-w64.org/.</br>
2. Install Visual Studio 2019 from <a href="https://docs.microsoft.com/en-us/visualstudio/releases/2019/release-notes"> Visual Studio</a>.</br>
3. Configure MinGW into Visual Studio 2019.</br>
4. Open the Visual Studio Installer, click on the "Modify" button. Install Destop development with C++.</br>
5. Open the Visual Studio, click on open project and load he submitted project.</br>
6. Go to Project->Test Properties->C/C++-> Additional Include Directories->Edit.</br>
7. In edit, add new line, browse to Program Files 86\Microsoft SDKs\MPI\Include and select it.</br>
8. Go to Project->Test Properties->Linker.</br>
9. Go to C:\Program Files 86\Microsoft SDKs\MPI\Lib\x86 and add it.</br>
10. Click on Run local Debugger.</br>
11.To run on multiple proccessors: \project_mpi\Debug\.</br>
12. Open command prompt there. </br>
13. Run the command "mpiexec -n 5 project_mpi.exe".</br>

<h2> How to run the code on GCP</h2>
To run it on the Google cloud, create a new project, and then create a new Virtual machine instance named as “e2-standard-4”. Once that is done, install the mpi library on the virtual machine by using the command “apt-get install lam4-dev”. Also, run the command “sudo apt-get install lam-runtime” and “lamboot”. Create a new CPP file and paste the provided code from the zip file into the new CPP file. Once that is done, compile the code by using the command “mpicxx -o source project.c“. After that, run the code by typing in “mpirun -np 5 --oversubscribe ./source” and get the output. 

<h2>Languages and Utilities Used</h2>

- <b>PowerShell</b> 
- <b>Visual Studio</b>
- <b>MPI Libraru</b>
- <b>C++</b>

<h2> Results</h2>



<h2>Environments Used </h2>

- <b>Windows 10</b> (21H2)
  
