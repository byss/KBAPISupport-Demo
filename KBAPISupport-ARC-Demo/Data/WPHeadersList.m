//
//  WPHeadersList.m
//  KBAPISupport-ARC-Demo
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

#import "WPHeadersList.h"

#import "WPArticleHeader.h"
#import "GDataXMLElement+stuff.h"

@implementation WPHeadersList

#if KBAPISUPPORT_XML
+ (NSString *) entityTag {
	return @"Item";
}
#endif

+ (Class) entityClass {
	return [WPArticleHeader class];
}

#if KBAPISUPPORT_XML
+ (instancetype) entityFromXML:(GDataXMLElement *)XML {
	NSString *initialRequest = [XML childStringValue:@"Query"];
	GDataXMLElement *sectionTag = [XML firstChildWithName:@"Section"];
	if (initialRequest && sectionTag) {
		WPHeadersList *result = [super entityFromXML:sectionTag];
		result.initialRequest = initialRequest;
		return result;
	} else {
		return nil;
	}
}
#endif

#if KBAPISUPPORT_JSON
+ (instancetype) entityFromJSON:(id)JSON {
	if (!([JSON isKindOfClass:[NSArray class]] && ([JSON count] == 2) && [[JSON objectAtIndex:0] isKindOfClass:[NSString class]])) {
		return nil;
	}
	
	WPHeadersList *result = [[WPHeadersList alloc] initWithJSON:[JSON objectAtIndex:1]];
	result.initialRequest = [JSON objectAtIndex:0];
	return result;
}
#endif

@end
