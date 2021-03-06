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

#import "GKPlaceAutocomplete.h"

@implementation GKPlaceAutocompleteTerm

- (instancetype)initWithDictionary:(NSDictionary *)dictionary {
    
    self = [super init];
    if (self) {
        
        _value = [dictionary objectForKey:@"value"];
        _offset = [[dictionary objectForKey:@"offset"] integerValue];
    }
    return self;
}

@end

@implementation GKPlaceAutocomplete

- (instancetype)initWithDictionary:(NSDictionary *)dictionary {
    
    self = [super init];
    if (self) {

        _textDescription = [dictionary objectForKey:@"description"];
        _placeId = [dictionary objectForKey:@"place_id"];
        
        NSMutableArray *terms = [NSMutableArray array];
        for (NSDictionary *term in [dictionary objectForKey:@"terms"])
            [terms addObject:[[GKPlaceAutocompleteTerm alloc] initWithDictionary:term]];

        _terms = [NSArray arrayWithArray:terms];
    }
    return self;
}

@end