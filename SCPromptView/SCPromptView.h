//
//  SCPromptView.h
//  SCPromptViewDemo
//
//  Created by 陈世翰 on 17/3/9.
//  Copyright © 2017年 Coder Chan. All rights reserved.
//

#import <UIKit/UIKit.h>
#define SCPROMPT_SHOW_COMMAND @"SCPROMPT_SHOW_COMMAND"

#define SCPROMPT_SHOW(SHOWCOMMAND,PARAM) \
[[SCPromptManager sharedManager] showPromptViewWithCommand:SHOWCOMMAND param:PARAM];

#define SCPROMPT_REGISTER(_CLASS_,COMMANDKEY) \
[[SCPromptManager sharedManager] registerPromptViewWithClass:_CLASS_ forShowCommand:COMMANDKEY];


@protocol SCPromptViewDelegate <NSObject>
@required
/**
 *  @brief 添加自定义的子空间
 */
-(void)sc_setUpCustomSubViews;
/**
 *  @brief 子控件读取数据
 */
-(void)sc_loadParam:(id)param;

@optional
/**
 *  @brief 显示时间
 */
-(NSTimeInterval)sc_showTime;
/**
 *  @brief 滑动距离
 */
-(CGFloat)sc_slideDistance;
/**
 *  @brief 震动距离
 */
-(CGFloat)sc_shakeDistance;
/**
 *  @brief 出现动画时间
 */
-(NSTimeInterval)sc_showAnimationDuration;
/**
 *  @brief 隐藏动画时间
 */
-(NSTimeInterval)sc_hideAnimationDuration;

@end

@interface SCPromptView : UIView<SCPromptViewDelegate>
/**
 *   内容
 */
@property (nonatomic,strong)UIView *contentView;

@end

@interface SCPromptManager : NSObject

+(instancetype)sharedManager;
/**
 *  @brief 注册样式类
 *  @param viewClass 样式类
 *  @param showCommand 显示命令
 */
-(void)registerPromptViewWithClass:(Class)viewClass forShowCommand:(NSString *)showCommand;
/**
 *  @brief 通知显示promptView
 *  @param showCommand 绑定的显示命令
 *  @param param 参数
 */
-(void)showPromptViewWithCommand:(NSString *)showCommand param:(id)param;

@end

