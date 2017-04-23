#pragma once

// The layout changed considerably since Peter Boettcher's 2000 work
// (https://groups.google.com/forum/?hl=en#!topic/comp.soft-sys.matlab/wkHYgh-5AnU)
// but I try to stay close to his field name conventions.
// 
// If you wish to try and fill in the blanks, it's advised to uncomment the a-p variable
// names so you'd be able to inspect them in raw watch.
//
// (c) Ofek Shilon 2017


struct strct_field_info_tag
{
	long	numFields : 32;
	long	/*a*/ : 32;
	size_t	/*b*/ : 64;
	char* field_name; // first field name 
};
struct struct_field_info
{
	size_t /*c*/ : 64;
	strct_field_info_tag* pFieldInfo;
};

struct mxArray_tag
{
	mxArray_tag* crosslink_fwd;
	mxClassID classID;
	long /*d*/ : 32;  // equals 4 after mxDuplicateArray, 0 otherwise
	mxArray_tag* crosslink_back;
	size_t number_of_dims;
	long /*e*/ : 32;

	struct
	{
		bool /*f*/ : 1;
		bool /*g*/ : 1;
		bool /*h*/ : 1;
		bool global : 1;
		bool /*i*/ : 1;
		bool sparse : 1;
		bool /*j*/ : 1;
		bool /*k*/ : 1;
	} dataflags;

	char /*l*/ : 8;
	char /*m*/ : 8;
	char /*n*/ : 8;

	size_t rowdim, coldim;

	// This is probably declared as a large union in Mathworks internal headers, but since we're interested
	// in inspecting the contents and not changing them directly - the type logic goes into the natvis file.
	void* pData;

	union
	{
		  void* pimag_data;
		  struct_field_info* pStructFieldInfo;
	};

	// sparse row/col data:
	size_t* irptr;
	size_t* jcptr;
	size_t nelements_allocated;

	size_t  /*o*/ : 64;
	size_t  /*p*/ : 64;
};

