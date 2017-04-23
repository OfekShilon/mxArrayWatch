// This project is pre-configured to expect Matlab installation at "C:\Program Files\MATLAB\R2016a"
// To successfully build, verify that the project properties "C++/General/Additional Include Directories"
// and "Linker/General/Additional Library Directories" match your own Matlab installation.


// There are various ways to demonstrate debugging with the mxArray watch.  Here's one:
//
// (1) build the project (it is recommended in DEBUG as watching variables would be easier),
// (2) Copy the output ToyMex.mexw64 to somewhere in your Matlab path, OR from Matlab cd to the
//     folder containing this mex.
// (3) From VS, *attach* to matlab (Debug/Attach to Process)
// (4) Set a breakpoint somewhere in mexFunction
// (4) in the Matlab command window, type something like -
//     >> A = rand(3)
//     >> ToyMex(A)
//
// You're very encouraged to play around with this toy sample. Before you rebuild with your changes
// remember to 'clear mex' in Matlab - otherwise it might prevent you from replacing the mex file.
//
// mxArrayWatch is tested on Matlab 2016a, 2016b, and 2017a. mxArray's layout has been known to change
// considerably between versions, but seems stable since at least 2015.
//
// (c) Ofek Shilon 2017

#define DLL_EXPORT_SYM __declspec(dllexport)
#include "mex.h"

#include "mxArrayWatch.h"


MEXFUNCTION_LINKAGE
void  mexFunction(int nlhs, mxArray *plhs[],
	int nrhs, const mxArray *prhs[])
{
	const mxArray* pA = prhs[0];

	// Set a breakpoint somewhere after pA assignment, set a watch on pA and lo its wonders

	int SetBreakpointHere = 1; // line might be optimized away in release

	//...
	// Your other awesome stuff goes here
	//...
}
