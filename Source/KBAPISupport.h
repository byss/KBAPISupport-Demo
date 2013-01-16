//
//  KBAPISupport.h
//  KBAPISupport
//
//  Created by Kirill byss Bystrov on 01.12.12.
//  Copyright (c) 2012 Kirill byss Bystrov. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

///////////////////////// Preparations /////////////////////////

#ifdef KBAPISUPPORT_DEBUG
#	undef KBAPISUPPORT_DEBUG
#endif

#ifdef KBAPISUPPORT_JSON
#	undef KBAPISUPPORT_JSON
#endif

#ifdef KBAPISUPPORT_USE_SBJSON
#	undef KBAPISUPPORT_USE_SBJSON
#endif

#ifdef KBAPISUPPORT_XML
#	undef KBAPISUPPORT_XML
#endif

#ifdef KBAPISUPPORT_DECODE
#	undef KBAPISUPPORT_DECODE
#endif

#ifdef KBAPISUPPORT_DECODE_FROM
#	undef KBAPISUPPORT_DECODE_FROM
#endif

#ifdef KBAPISUPPORT_BOTH_FORMATS
#	undef KBAPISUPPORT_BOTH_FORMATS
#endif

///////////////////////// Config /////////////////////////

// Turns on or off KBAPISupport debug messages
#define KBAPISUPPORT_DEBUG 0

// Turns on or off JSON objects support (using NSJSONSerialization)
#define KBAPISUPPORT_JSON 1

// Use SBJson aka json-framework instead of NSJSONSerialization
#define KBAPISUPPORT_USE_SBJSON 0

// Turns on or off XML objects (using GDataXML)
#define KBAPISUPPORT_XML 1

// Turns on or off converting server response from any iOS-supported encoding
#define KBAPISUPPORT_DECODE 0

// Sets the server response encoding
#define KBAPISUPPORT_DECODE_FROM (NSWindowsCP1251StringEncoding)

///////////////////////// Debug macros /////////////////////////

#ifndef MLOG
#	if KBAPISUPPORT_DEBUG && defined (DEBUG)
#		define MLOG(fmt, args...) NSLog (@"%s (%d): " fmt, __PRETTY_FUNCTION__, __LINE__, ##args)
#	else
#		define MLOG(...)
#	endif
#endif

#ifndef F_START
#	define F_START MLOG (@">>>");
#endif

#ifndef F_END
#	define F_END MLOG (@"<<<");
#endif

#define BUG_HERE NSLog (@"Execution reached line %d in %s (func %s). Possible bug.", __LINE__, __FILE__, __PRETTY_FUNCTION__);

///////////////////////// At least one format must be selected /////////////////////////

#if !(KBAPISUPPORT_JSON || KBAPISUPPORT_XML)
#	error Please select one of response formats in `Config' section
#endif

///////////////////////// Just-in-case warning /////////////////////////

#if KBAPISUPPORT_JSON && KBAPISUPPORT_XML
#	define KBAPISUPPORT_BOTH_FORMATS 1
#else
#	define KBAPISUPPORT_BOTH_FORMATS 0
#endif

///////////////////////// All included! /////////////////////////

#ifndef IMPORTED_FROM_KBAPISUPPORT_H
#	define IMPORTED_FROM_KBAPISUPPORT_H
#endif

#import "KBAPIConnection.h"
#import "KBAPIRequest.h"
#import "KBEntity.h"
#import "KBEntityList.h"
#import "KBNetworkIndicator.h"
#if !__has_feature(objc_arc)
#	import "KBAutoField.h"
#	import "KBAutoEntity.h"
#endif

#undef IMPORTED_FROM_KBAPISUPPORT_H

///////////////////////// THE END /////////////////////////
