# Watching mxArray Contents within Visual Studio

mxArray is the main type that Matlab uses to expose functionality to external native code. It is the input/output both to mex files and to compiler-generated functions.

mxArray is an opaque type, defined in matrix.h as -
```cpp
typedef struct mxArray_tag mxArray;
```
and so setting a regular watch on it while debugging (either mex files or calls to compiled components) results in a null watch. An intervention is in order.

The code in this project is a [natvis file](https://msdn.microsoft.com/en-us/library/jj620914.aspx) customizing the VS debugger to show some of the mxArray contents when setting a watch on an mxArray variable. It also contains a sample mex code, used for demonstration of this enhanced debugging view. To use this natvis in your own project just include it as one of your project files.

This work is based on rough reversing and is still very partial. Moreover, `mxArray`'s layout is known to be prone to change between matlab versions. Current natvis has been tested with Matlab 2016a, 2016b & 2017a, but we believe it should work with at least 2014+ versions.

## Getting Started

There are various ways to demonstrate debugging with the mxArray watch. Here's one:

1. Build the project (it is recommended in DEBUG as watching variables would be easier),
2. Copy the output ToyMex.mexw64 to somewhere in your Matlab path, OR from Matlab `cd` to the
folder containing this mex.
3. From VS, *attach* to Matlab (Debug / Attach to Process)
4. Set a breakpoint somewhere in mexFunction
5. in the Matlab command window, type something like -
```
>> A = rand(3)
>> ToyMex(A)
```

When setting a watch on the received `mxArray` in VS, you should see [something like:](images/double_expand.png)

You're very encouraged to play around with this toy sample. Before you rebuild with your changes
remember to 'clear mex' in Matlab - otherwise it might prevent you from replacing the mex file.


(c) Ofek Shilon 2017
