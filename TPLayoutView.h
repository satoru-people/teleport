//
//  TPLayoutView.h
//  teleport
//
//  Created by JuL on Thu Feb 26 2004.
//  Copyright (c) 2003-2005 abyssoft. All rights reserved.
//

#import <AppKit/AppKit.h>
#import <QuartzCore/QuartzCore.h>

@class TPLayoutLocalHostView, TPLayoutRemoteHostView, TPRemoteHost;

extern NSRect TPScaledRect(NSRect rect, float scale);

@interface TPLayoutView : NSView
{
	IBOutlet id delegate;
	IBOutlet NSTextField * infoLabel;
	
	float _scaleFactor;
	float _layoutHeight;
	NSTimeInterval _snapTime;
	
	TPLayoutLocalHostView * _localHostView;
	NSMutableDictionary * _remoteHostsViews;
	
	NSScroller * _scroller;
	float _scrollerDeltaX;
	
	CALayer * _separationLine;
	CALayer * _overlayLayer;
	
	NSWindow * _optionsWindow;
}

- (instancetype _Nonnull )initWithFrame:(NSRect)frameRect NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *_Nullable)coder NS_DESIGNATED_INITIALIZER;

- (TPLayoutRemoteHostView*_Nullable)remoteHostViewForHost:(TPRemoteHost*_Nullable)host;

- (void)updateLayout;

@end
