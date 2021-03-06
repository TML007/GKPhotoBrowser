//
//  GKPhotoView.h
//  GKPhotoBrowser
//
//  Created by QuintGao on 2017/10/23.
//  Copyright © 2017年 QuintGao. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GKPhoto.h"
#import "GKPhotoScrollView.h"
#import "GKPhotoLoadingView.h"
#import "GKWebImageProtocol.h"
#import "GKLoadingView.h"

NS_ASSUME_NONNULL_BEGIN

@class GKPhotoView;

@protocol GKPhotoViewDelegate<NSObject>

- (void)photoViewSingleTap:(GKPhotoView *)photoView;
- (void)photoViewDoubleTap:(GKPhotoView *)photoView;

@end

@interface GKPhotoView : UIView<UIScrollViewDelegate>

@property (nonatomic, weak) id<GKPhotoViewDelegate> delegate;

@property (nonatomic, strong, readonly) GKPhotoScrollView *scrollView;

@property (nonatomic, strong, readonly) UIImageView *imageView;

@property (nonatomic, strong, readonly) GKLoadingView *loadingView;

@property (nonatomic, strong, readonly) GKPhoto *photo;

/** 是否重新布局 */
@property (nonatomic, assign) BOOL isLayoutSubViews;

- (instancetype)initWithFrame:(CGRect)frame imageProtocol:(id<GKWebImageProtocol>)imageProtocol;

// 设置数据
- (void)setupPhoto:(GKPhoto *)photo;

- (void)adjustFrame;

// 缩放
- (void)zoomToRect:(CGRect)rect animated:(BOOL)animated;

// 重新布局
- (void)resetFrame;

@end

NS_ASSUME_NONNULL_END
