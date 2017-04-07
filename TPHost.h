//
//  TPHost.h
//  Teleport
//
//  Created by JuL on Sun Dec 07 2003.
//  Copyright (c) 2003-2005 abyssoft. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "TPTCPSocket.h"
#import "TPScreen.h"

#define MAX_CAPABILITIES 3
typedef NS_OPTIONS(NSUInteger, TPHostCapability) {
	TPHostNoCapability                = 0,
	TPHostEncryptionCapability        = 1 << 0,
	TPHostEventTapsCapability         = 1 << 1,
	TPHostDragNDropCapability         = TPHostEventTapsCapability,
	TPHostDirectEventTapsCapability   = 1 << 2
} ;

/*
 13.x.x  OS X 10.9.x Mavericks
 12.x.x  OS X 10.8.x Mountain Lion
 11.x.x  OS X 10.7.x Lion
 10.x.x  OS X 10.6.x Snow Leopard
 9.x.x  OS X 10.5.x Leopard
 8.x.x  OS X 10.4.x Tiger
 7.x.x  OS X 10.3.x Panther
 6.x.x  OS X 10.2.x Jaguar
 5.x    OS X 10.1.x Puma
 */

static inline int TPHostOSVersion(int version)
{
	return version + 4;
}

extern NSString * _Nullable TPHostDidUpdateNotification;

extern NSString * _Nullable TPHostIdentifierKey;
extern NSString * _Nullable TPHostComputerNameKey;
extern NSString * _Nullable TPHostBackgroundImageDataKey;
extern NSString * _Nullable TPHostMacAddressKey;
extern NSString * _Nullable TPHostPortKey;
extern NSString * _Nullable TPHostCapabilitiesKey;
extern NSString * _Nullable TPHostOSVersionKey;

@interface TPHost : NSObject <NSCoding>
{
	NSString * _computerName;
	IOEthernetAddress _macAddress;
}

@property (nonatomic, readonly, copy) NSString * _Nullable identifier;
@property (nonatomic, readonly) SInt32 osVersion;

@property (nonatomic, readonly, copy) NSString * _Nullable address;

@property (nonatomic, copy) NSString * _Nullable computerName;

@property (nonatomic, readonly) BOOL hasValidMACAddress;
- (void)invalidateMACAddress;
@property (nonatomic) IOEthernetAddress MACAddress;

@property (nonatomic, readonly, copy) NSArray * _Nullable screens;
- (NSScreen*_Nullable)screenAtIndex:(unsigned)screenIndex;

- (instancetype _Nullable )init
#if NS_ENFORCE_NSOBJECT_DESIGNATED_INITIALIZER
    NS_DESIGNATED_INITIALIZER
#endif
    ;
- (nullable instancetype)initWithCoder:(NSCoder *_Nullable)coder NS_DESIGNATED_INITIALIZER;

+ (NSImage*_Nullable)backgroundImageFromDesktopPicture:(NSImage*_Nullable)desktopPicture;
- (NSImage*_Nullable)defaultBackgroundImage;
@property (nonatomic, readonly, copy) NSImage * _Nullable backgroundImage;
@property (nonatomic, readonly, copy) NSData * _Nullable backgroundImageData;
@property (nonatomic, readonly) BOOL hasCustomBackgroundImage;

@property (nonatomic, readonly) TPHostCapability capabilities;
- (BOOL)hasCapability:(TPHostCapability)capability;
- (BOOL)pairWithHost:(TPHost*_Nullable)host hasCapability:(TPHostCapability)capability;

+ (TPHost*_Nullable)hostFromHostData:(NSData*_Nullable)hostData;
@property (nonatomic, readonly, copy) NSData * _Nullable hostData;

- (void)notifyChange;

@end
