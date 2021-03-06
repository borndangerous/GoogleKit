//
//    Copyright (c) 2014 Max Sokolov (http://maxsokolov.net)
//
//    Permission is hereby granted, free of charge, to any person obtaining a copy of
//    this software and associated documentation files (the "Software"), to deal in
//    the Software without restriction, including without limitation the rights to
//    use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
//    the Software, and to permit persons to whom the Software is furnished to do so,
//    subject to the following conditions:
//
//    The above copyright notice and this permission notice shall be included in all
//    copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
//    FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
//    COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
//    IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
//    CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#import "GKQuery.h"
#import "GKPlace.h"

typedef void (^GKPlacesRadarSearchQueryCompletionBlock)(NSArray *results, NSError *error);

/**
 * Description
 * @see https://developers.google.com/places/documentation/search#RadarSearchRequests
 */
@interface GKPlacesRadarSearchQuery : GKQuery

// required parameters
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
@property (nonatomic, assign) NSUInteger radius;

// optional parameters
@property (nonatomic, strong) NSString *keyword;
@property (nonatomic, assign) NSUInteger minprice; // 0...4
@property (nonatomic, assign) NSUInteger maxprice; // 0...4
@property (nonatomic, strong) NSString *name;
@property (nonatomic, assign) BOOL opennow;

/*
 * Description
 * @see https://developers.google.com/places/documentation/supported_types
 */
@property (nonatomic, strong) NSArray *types;

- (void)searchPlaces:(GKPlacesRadarSearchQueryCompletionBlock)completionHandler;

@end