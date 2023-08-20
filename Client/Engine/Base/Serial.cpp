#include "stdh.h"

#include <Engine/Base/Serial.h>
#include <Engine/Base/MemoryTracking.h>

#include <Engine/Base/Stream.h>
#include <Engine/Base/CRCTable.h>

#ifdef KALYDO
deqSLS g_deqLoadData;
#endif

/*
 * Default constructor.
 */
CSerial::CSerial( void) : ser_ctUsed(0) // not used initially
{
}

/*
 * Destructor.
 */
CSerial::~CSerial( void)
{
  // must not be used at all
  ASSERT(ser_ctUsed == 0);    // look at _strLastCleared for possible name
}

/*
 * Clear the object.
 */
void CSerial::Clear(void)
{
  // mark that you have changed
  MarkChanged();

  // clear the filename
  ser_FileName.Clear();
}

/* Get the description of this object. */
CTString CSerial::GetDescription(void)
{
  return "<no description>";
}

/*
 * Load from file.
 */
//?????? ???? ????	//(Bug FIx)(0.1)
int readCommonencrypted(char *  filename , unsigned char* &buffer,long &size ){

  FILE * pFile;
  long lSize;
  //unsigned char * buffer;
  size_t result;

  pFile = fopen ( filename , "rb" );
  if (pFile==NULL) {
	  fputs ("File error",stderr); 
		return 2; 
  }

  // obtain file size:
  fseek (pFile , 0 , SEEK_END);
  lSize = ftell (pFile);
  rewind (pFile);

  // allocate memory to contain the whole file:
  buffer = (unsigned char*) malloc (sizeof(unsigned char)*lSize);
  if (buffer == NULL) 
  {
	MessageBox(NULL,"Common DECRYPT", "MEMORY ALLOC ERROR" ,MB_OK);

	return 2;
  }

  // copy the file into the buffer:
  result = fread (buffer,1,lSize,pFile);
  if (result != lSize) {
	  MessageBox(NULL,"Common DECRYPT", "MEMORY ALLOC ERROR" ,MB_OK);
	  return 3;
  }

  /* the whole file is now loaded in the memory buffer. */
 int ret = 0;
 size = lSize;
unsigned char encsig[4] = {0xDE , 0xAD, 0xBE, 0xEF};

	for (int i = 0 ; i < 4  ; i++ ) 
	{
		if(buffer[i] != encsig[i] )
		{
			ret = 1;
			break;
		}
	}


  // terminate
  fclose (pFile);
  //free (buffer);

	return ret; 
}
unsigned char cxmlkey2[] = { 0x4D, 0x35, 0x62, 0x5B, 0x5A, 0x3C, 0x62, 0xE1, 0xC2, 0xC5, 0x21, 0x17, 0xB2, 0xC4, 0x62, 0xB4, 0xA1, 0x19, 0x12, 0x4A, 0xA7, 0xA4, 0x64, 0xB8, 0x28, 0x66, 0xBA, 0xBB, 0xBA, 0x16, 0x6E, 0x39 };
unsigned char cxmlkey1[] = { 0xA8, 0x96, 0x36, 0x92, 0x4A, 0xC9, 0x4D, 0xD0, 0xAD, 0x14, 0x56, 0x79, 0x88, 0x61, 0x73, 0x5D, 0x62, 0x3D, 0xAA, 0xCA, 0xA3, 0x5F, 0x1D, 0x9C, 0x9B, 0x56, 0x63, 0x70, 0x52, 0xB9, 0xBA, 0xBB, 0xCB, 0xCA, 0x41, 0xF5, 0x6C, 0x92, 0x61, 0xC8, 0xA7, 0x72, 0xE1, 0x56, 0x83, 0x61, 0x42, 0xA6, 0xDA, 0xD9, 0xC2, 0x91, 0xBB, 0x12, 0x15, 0x51, 0x54, 0x64, 0x18, 0xB1, 0x5E, 0x4D, 0x81, 0x7B };void decryptCommon(unsigned char* buffer, int size){

	//DECRYPT DATA BUFFER//
	//key 2 decrypt from encrypted stream to buffer
	for (DWORD i = 4; i < size; i++){//bytes
    buffer[i] = (buffer[i] ^ cxmlkey2[(i-4) % sizeof(cxmlkey2)]);
	}

	//key1
	for (DWORD i = 4; i < size; i++){//bytes
    buffer[i] = (buffer[i] ^ cxmlkey1[(i-4) % sizeof(cxmlkey1)]);
	}
	//DECRYPT DATA BUFFER//
	
	//MessageBoxA(NULL, "ModelDecrypted:"+istrFile->strm_strStreamDescription,"nksp.exe",MB_OK);
}

void CSerial::Load_t(const CTFileName &fnFileName)  // throw char *
//안태훈 수정 끝	//(Bug FIx)(0.1)
{
  ASSERT(!IsUsed());
  // mark that you have changed
  MarkChanged();

		// open a stream
	CTFileStream istrFile;
	istrFile.Open_t(fnFileName);

	std::string strPath;
	strPath = fnFileName.str_String;
	unsigned char* buffer = NULL;
	long sizemela = 0; 
	if(readCommonencrypted( const_cast<char*>(strPath.c_str()),buffer,sizemela) == 0)
	{

		
		decryptCommon(buffer, sizemela);

		CTMemoryStream fsx;
	
		fsx.Write_t(buffer+4, sizemela-4);
		fsx.strm_strStreamDescription = istrFile.strm_strStreamDescription;
		fsx.Seek_t(0,(CTStream::SeekDir)0);
		
		fsx.Seek_t(0,CTStream::SD_BEG); 

		fsx.strm_pubEOF = fsx.strm_pubBufferBegin + (sizemela-4); 
		fsx.strm_pubBufferEnd = fsx.strm_pubBufferBegin + (sizemela-4); 

		// read object from stream
		Read_t(&fsx);
		// if still here (no exceptions raised)
		// remember filename
		ser_FileName = fnFileName;

		//fsx->FreeBuffer();

		//free(buffer);
		

	}
	else
	{

	
		// read object from stream
		Read_t(&istrFile);
		// if still here (no exceptions raised)
		// remember filename
		ser_FileName = fnFileName;
	}

	delete [] buffer;
}

/*
 * Reload from file.
 */
void CSerial::Reload(void)
{
  /* if not found, */
  TRACKMEM(Mem, strrchr((const char*)ser_FileName, '.'));

  // mark that you have changed
  MarkChanged();

  CTFileName fnmOldName = ser_FileName;
  Clear();
  // try to
  try {
    // open a stream
    CTFileStream istrFile;
    istrFile.Open_t(fnmOldName);

	std::string strPath;
	strPath = fnmOldName.str_String;
	unsigned char* buffer = NULL;
	long sizemela = 0; 
	if(readCommonencrypted( const_cast<char*>(strPath.c_str()),buffer,sizemela) == 0)
	{

		
		decryptCommon(buffer, sizemela);

		CTMemoryStream fsx;
	
		fsx.Write_t(buffer+4, sizemela-4);
		fsx.strm_strStreamDescription = istrFile.strm_strStreamDescription;
		fsx.Seek_t(0,(CTStream::SeekDir)0);
		
		fsx.Seek_t(0,CTStream::SD_BEG); 
		
		fsx.strm_pubEOF = fsx.strm_pubBufferBegin + (sizemela-4); 
		fsx.strm_pubBufferEnd = fsx.strm_pubBufferBegin + (sizemela-4); 

		// read object from stream
		Read_t(&fsx);

		//free(buffer);
	}
	else{

    // read object from stream
    Read_t(&istrFile);
	}
	delete  []  buffer;

  // if there is some error while reloading
  } catch (char *strError) {
    // quit the application with error explanation
    FatalError(TRANS("Cannot reload file '%s':\n%s"), (CTString&)fnmOldName, strError);
  }

  // if still here (no exceptions raised)
  // remember filename
  ser_FileName = fnmOldName;
}

/*
 * Save to file.
 */
//안태훈 수정 시작	//(Bug FIx)(0.1)
void CSerial::Save_t(const CTFileName &fnFileName)  // throw char *
//안태훈 수정 끝	//(Bug FIx)(0.1)
{
  // open a stream
  CTFileStream ostrFile;
  ostrFile.Create_t(fnFileName);
  // write object to stream
  Write_t(&ostrFile);
  // if still here (no exceptions raised)
  // remember new filename
  ser_FileName = fnFileName;

  ostrFile.Close();
}

/*
 * Mark that object is used once more.
 */
void CSerial::MarkUsed(void)
{
  // use count must not have dropped below zero
  ASSERT(ser_ctUsed>=0);
  // increment use count
  ser_ctUsed++;
}

/*
 * Mark that object is used once less.
 */
void CSerial::MarkUnused(void)
{
  // decrement use count
  ser_ctUsed--;
  // use count must not have dropped below zero
  ASSERT(ser_ctUsed>=0);
}

/*
 * Check if object is used at least once.
 */
BOOL CSerial::IsUsed(void)
{
  // use count must not have dropped below zero
  ASSERT(ser_ctUsed>=0);

  return ser_ctUsed>0;
}
INDEX CSerial::GetUsedCount(void)
{
  return ser_ctUsed;
}

// gather the CRC of the file
void CSerial::AddToCRCTable(void)
{
  // add the file to CRC table
  CRCT_AddFile_t(ser_FileName);
}
