/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x11.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sngantch <sngantch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:19:54 by sngantch          #+#    #+#             */
/*   Updated: 2025/02/20 19:58:23 by sngantch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef X11_H
# define X11_H

// Key Events
# define KeyPress          2
# define KeyRelease        3
# define ButtonPress       4
# define ButtonRelease     5
# define MotionNotify      6
# define EnterNotify       7
# define LeaveNotify       8
# define FocusIn           9
# define FocusOut          10
# define KeymapNotify      11
# define Expose            12
# define GraphicsExpose    13
# define NoExpose          14
# define VisibilityNotify  15
# define CreateNotify      16

# define UnmapNotify       18
# define MapNotify         19
# define MapRequest        20
# define ReparentNotify    21
# define ConfigureNotify   22
# define ConfigureRequest  23
# define GravityNotify     24
# define ResizeRequest     25
# define CirculateNotify   26
# define CirculateRequest  27
# define PropertyNotify    28
# define SelectionClear    29
# define SelectionRequest  30
# define SelectionNotify   31
# define ColormapNotify    32
# define ClientMessage     33
# define MappingNotify     34
# define GenericEvent      35
# define LASTEvent         36

// Event Masks
# define NoEventMask       0L
# define KeyPressMask      (1L << 0)
# define KeyReleaseMask    (1L << 1)
# define ButtonPressMask   (1L << 2)
# define ButtonReleaseMask (1L << 3)
# define EnterWindowMask   (1L << 4)
# define LeaveWindowMask   (1L << 5)
# define PointerMotionMask (1L << 6)
# define PointerMotionHintMask (1L << 7)
# define Button1MotionMask (1L << 8)
# define Button2MotionMask (1L << 9)
# define Button3MotionMask (1L << 10)
# define Button4MotionMask (1L << 11)
# define Button5MotionMask (1L << 12)
# define ButtonMotionMask  (1L << 13)
# define KeymapStateMask   (1L << 14)
# define ExposureMask      (1L << 15)
# define VisibilityChangeMask (1L << 16)

# define ResizeRedirectMask (1L << 18)
# define SubstructureNotifyMask (1L << 19)
# define SubstructureRedirectMask (1L << 20)
# define FocusChangeMask   (1L << 21)
# define PropertyChangeMask (1L << 22)
# define ColormapChangeMask (1L << 23)
# define OwnerGrabButtonMask (1L << 24)

# define XK_BackSpace                     0xff08  /* Back space, back char */
# define XK_minus                         0x002d  /* U+002D HYPHEN-MINUS */
# define XK_Tab                           0xff09
# define XK_Linefeed                      0xff0a  /* Linefeed, LF */
# define XK_Clear                         0xff0b
# define XK_Return                        0xff0d  /* Return, enter */
# define XK_Pause                         0xff13  /* Pause, hold */
# define XK_Scroll_Lock                   0xff14
# define XK_Sys_Req                       0xff15
# define XK_Escape                        53//0xff1b
# define XK_Delete                        0xffff  /* Delete, rubout */
# define XK_Up                            126//0xff52  /* Move up, up arrow */
# define XK_Right                         124//0xff53  /* Move right, right arrow */
# define XK_Down                          125 //0xff54  /* Move down, down arrow */
# define XK_Left                          123 //0xff51  /* Move left, left arrow */
# define DestroyNotify                    53//17
# define StructureNotifyMask              0 //= 131072
# define XK_plus                          0x002b  /* U+002B PLUS SIGN */
# define XK_minus                         0x002d  /* U+002D HYPHEN-MINUS */

#endif 
