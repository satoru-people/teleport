//
//  TPOptionsController.h
//  teleport
//
//  Created by Julien Robert on 02/04/09.
//  Copyright 2009 Apple. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class TPRemoteHost, TPLayoutView, TPKeyComboView, TPLayoutScreenView, TPLayoutOptionsProxy;

@interface TPOptionsController : NSResponder
{	
	IBOutlet NSObjectController * hostController;
	IBOutlet NSTextField * titleTextField;
	IBOutlet NSView * hostOptionsView;
	IBOutlet TPLayoutView * layoutView;
	IBOutlet TPKeyComboView * keyComboView;
	IBOutlet NSButton * restoreSaveDefaultsButton;
	
	TPRemoteHost * _host;
	TPLayoutOptionsProxy * _optionsProxy;
	TPLayoutScreenView * _currentScreenView;
	NSRect _currentScreenFrame;
}

+ (TPOptionsController*_Nullable)controller;

- (instancetype _Nonnull )init
#if NS_ENFORCE_NSOBJECT_DESIGNATED_INITIALIZER
    NS_DESIGNATED_INITIALIZER
#endif
    ;

- (nullable instancetype)initWithCoder:(NSCoder *_Nullable)coder NS_DESIGNATED_INITIALIZER;

- (void)showOptionsForHost:(TPRemoteHost*_Nullable)host sharedScreenIndex:(unsigned)screenIndex fromRect:(NSRect)frame;
- (IBAction)restoreToDefaults:(id _Nullable )sender;
- (IBAction)useAsDefaults:(id _Nullable )sender;
- (IBAction)closeOptions:(id _Nullable )sender;

@property (nonatomic, readonly, strong) TPRemoteHost * _Nullable host;
@property (nonatomic, readonly, strong) id _Nullable hostOptions;

@end
