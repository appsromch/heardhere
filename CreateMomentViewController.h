//
//  CreateMomentViewController.h
//  Heard Here
//
//  Created by Dianna Mertz on 7/22/13.
//  Copyright (c) 2013 Dianna Mertz. All rights reserved.
//
@import UIKit;
#import "DetailTableViewController.h"
#import "DateTimePicker.h"
#import "Playlist.h"
#import "Song.h"
#import "Photo.h"

@protocol MomentAddDelegate;

@interface CreateMomentViewController : UIViewController <UITextFieldDelegate, NSFetchedResultsControllerDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate>

@property (strong, nonatomic) IBOutlet UITextField *momentNameTextField;
@property (strong, nonatomic) IBOutlet UILabel *fromDateLabel;
@property (strong, nonatomic) IBOutlet UILabel *fromTimeLabel;
@property (strong, nonatomic) IBOutlet UILabel *untilDateLabel;
@property (strong, nonatomic) IBOutlet UILabel *untilTimeLabel;
@property (strong, nonatomic) IBOutlet UIButton *photoButton;
@property (strong, nonatomic) IBOutlet UIImageView *playlistImageViewThumb;

@property (strong, nonatomic) DateTimePicker *fromDatePicker;
@property (strong, nonatomic) DateTimePicker *untilDatePicker;
@property (strong, nonatomic) DateTimePicker *fromTimePicker;
@property (strong, nonatomic) DateTimePicker *untilTimePicker;

@property (strong, nonatomic) NSDate *fromDate;
@property (strong, nonatomic) NSDate *untilDate;
@property (strong, nonatomic) NSDate *fromTime;
@property (strong, nonatomic) NSDate *untilTime;

@property (strong, nonatomic) NSSet *songsToBeInNewPlaylistSet;

@property(nonatomic, weak) id <MomentAddDelegate> momentDelegate;

@property(nonatomic, strong) Song *songObject;
@property(nonatomic, strong) Playlist *currentPlaylist;
@property(nonatomic, strong) Photo *currentPhoto;

@property(nonatomic, strong) NSManagedObjectContext *managedObjectContext;
@property(nonatomic, retain) NSFetchedResultsController *fetchedResultsController;

- (IBAction)cancel:(id)sender;
- (IBAction)save:(id)sender;
- (IBAction)cameraRoll:(id)sender;

@end

@protocol MomentAddDelegate
-(void)createMomentViewControllerDidSave;
-(void)createMomentViewControllerDidCancel:(Playlist*)playlistToDelete;
@end
