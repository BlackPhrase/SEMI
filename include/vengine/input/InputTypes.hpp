/*
 * This file is part of V-Engine
 *
 * Copyright 2018-2019, 2023 BlackPhrase
 *
 * Licensed under terms of the MIT license
 * See LICENSE.md file for full terms
 * DO NOT REMOVE THIS NOTICE!
*/

/// @file

#pragma once

enum class KeyCode : int
{
	Invalid = -1,
	
	BackSpace,
	Tab,
	Enter,
	
	Shift,
	Ctrl,
	Alt,
	
	Pause,
	CapsLock,
	Escape,
	
	PageUp,
	PageDown,
	
	End,
	Home,
	
	LeftArrow,
	UpArrow,
	RightArrow,
	DownArrow,
	
	Insert,
	Delete,
	
	Zero,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	
	A,
	B,
	C,
	D,
	E,
	F,
	G,
	H,
	I,
	J,
	K,
	L,
	M,
	N,
	O,
	P,
	Q,
	R,
	S,
	T,
	U,
	V,
	W,
	X,
	Y,
	Z,
	
	/*
	Num/*Pad0,
	Num/*Pad1,
	Num/*Pad2,
	Num/*Pad3,
	Num/*Pad4,
	Num/*Pad5,
	Num/*Pad6,
	Num/*Pad7,
	Num/*Pad8,
	Num/*Pad9,
	*/
	
	Multiply,
	Add,
	Subtract,
	DecimalPoint,
	Divide,
	
	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,
	
	SemiColon,
	EqualSign,
	Comma,
	Dash,
	Period,
	ForwardSlash,
	GraveAccent,
	OpenBracket,
	BackSlash,
	CloseBracket,
	SingleQuote,
	
	SizeOfEnum
};

enum class MouseButton : int
{
	Invalid = -1,
	
	Left = 0,
	Right,
	Middle,
	
	//WheelUp, // NOTE: not a button...
	//WheelDown, // NOTE: not a button...
};