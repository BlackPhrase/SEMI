/// @file

#pragma once

struct IArchiveLoader;
struct IFile;

struct IFileSystem
{
	///
	//virtual bool Init() = 0; // TODO: shouldn't be part of the interface
	
	///
	//virtual void Shutdown() = 0; // TODO: shouldn't be part of the interface
	
	///
	virtual void AddResourcePath(const char *asPath, bool abReadOnly = true) = 0;
	
	///
	virtual void AddArchiveLoader(IArchiveLoader &apLoader) = 0;
	
	///
	virtual void RemoveArchiveLoader(const IArchiveLoader &apLoader) = 0;
	
	///
	virtual IFile *OpenFile(const char *asPath, const char *asMode) const = 0;
	
	///
	virtual void CloseFile(const IFile &apFile) = 0;
};