//
//  TPRemoteHost.h
//  teleport
//
//  Created by JuL on Fri Feb 27 2004.
//  Copyright (c) 2003-2005 abyssoft. All rights reserved.
//

#import "TPHost.h"
#import "PTKeyCombo.h"

typedef NS_OPTIONS(NSUInteger, TPHostState) {
	TPHostUndefState			= 0,
	TPHostSharedState			= 1 << 0,
	TPHostPeeredOfflineState	= 1 << 1,
	TPHostPeeredOnlineState		= 1 << 2,
	TPHostControlledState		= 1 << 3,
	TPHostIncompatibleState		= 1 << 4,
	TPHostPeeringState			= 1 << 5,
	TPHostPeeredState			= TPHostPeeredOfflineState | TPHostPeeredOnlineState | TPHostControlledState | TPHostPeeringState,
	TPHostOnlineState			= TPHostSharedState | TPHostPeeredOnlineState | TPHostControlledState | TPHostIncompatibleState | TPHostPeeringState,
	TPHostDraggableState		= TPHostSharedState | TPHostPeeredOnlineState,
	TPHostAllStates				= 0xFFFF
} ;

@class TPOptionsProxy;

@interface TPRemoteHost : TPHost
{
	NSString * _identifier;
	SInt32 _osVersion;
	SecCertificateRef _certRef;
	NSString * _address;
	int _port;
	NSImage * _backgroundImage;
	NSArray * _screens;
	int _localScreenIndex;
	int _sharedScreenIndex;
	NSPoint _sharedScreenPosition;
	PTKeyCombo * _keyCombo;
	NSMutableDictionary * _customOptions;
	TPOptionsProxy * _optionsProxy;
	
	TPHostCapability _capabilities;
	TPHostState _state;
	TPHostState _previousHostState;
}

- (instancetype _Nullable )init
#if NS_ENFORCE_NSOBJECT_DESIGNATED_INITIALIZER
    NS_DESIGNATED_INITIALIZER
#endif
    ;
- (nullable instancetype)initWithCoder:(NSCoder *_Nullable)coder NS_DESIGNATED_INITIALIZER;

- (instancetype _Nullable ) initWithIdentifier:(NSString*_Nullable)identifier address:(NSString*_Nullable)address port:(int)port;

- (void)setIdentifier:(NSString*_Nullable)identifier;
- (void)setOSVersion:(SInt32)osVersion;

/* Address */
- (void)setAddress:(NSString*_Nullable)address;
@property (nonatomic) int port;

/* Certificate */
@property (nonatomic) SecCertificateRef _Nullable certificate;
@property (nonatomic, readonly, copy) NSData * _Nullable certificateData;
@property (nonatomic, getter=isCertified, readonly) BOOL certified;

/* Screens */
@property (nonatomic, copy) NSArray * _Nullable screens;

@property (nonatomic, readonly, strong) NSScreen * _Nullable localScreen;
@property (nonatomic) unsigned int localScreenIndex;

- (unsigned)sharedScreenIndex;
- (void)setSharedScreenIndex:(unsigned)sharedScreenIndex;

@property (nonatomic, readonly) NSRect hostRect;
@property (nonatomic, readonly) NSRect adjustedHostRect;
@property (nonatomic, readonly) NSRect fullHostRect;
- (void)setHostPosition:(NSPoint)position;

@property (nonatomic, copy) PTKeyCombo * _Nullable keyCombo;

- (void)setBackgroundImage:(NSImage*_Nullable)backgroundImage;

/* Capabilities */
- (void)setCapabilities:(TPHostCapability)capabilities;
- (void)setCapability:(TPHostCapability)capability isEnabled:(BOOL)enabled;

/* State */
@property (nonatomic) TPHostState hostState;
@property (nonatomic, readonly) TPHostState previousHostState;
- (BOOL)isInState:(TPHostState)hostState;

/* Custom options */
@property (nonatomic, readonly, strong) id _Nullable options;
- (id _Nullable )optionForKey:(NSString*_Nullable)key;
- (void)setCustomOption:(id _Nullable )option forKey:(NSString*_Nullable)key;
@property (nonatomic, readonly, copy) NSArray * _Nullable customizedOptions;
@property (nonatomic, readonly) BOOL hasCustomOptions;

- (void)resetCustomOptions;
- (void)makeDefaultOptions;

@end

@interface NSArray (TPRemoteHostAdditions)

- (NSArray*_Nullable)hostsWithState:(TPHostState)state;

@end
