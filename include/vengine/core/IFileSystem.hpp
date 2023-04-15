/*
 * This file is part of V-Engine
 *
 * Copyright 2018, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

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