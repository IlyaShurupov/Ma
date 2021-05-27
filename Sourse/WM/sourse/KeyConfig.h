#pragma once


#define WINDOW_TRANSFORM 555




#define EV_ST_IN_ACTION  0
#define EV_ST_REALESED 1
#define EV_ST_PRESED 2
#define EV_ST_DOWN  3
#define EV_ST_UP 4
#define EV_ST_MOUSE_MOVE 5
#define EV_ST_APPLY 6
#define EV_ST_CANCEL 7

#define EV_SELECT (GLFW_MOUSE_BUTTON_1)

#define EV_SCALE (GLFW_KEY_S)
#define EV_MOVE (GLFW_KEY_G)
#define EV_ROTATE (GLFW_KEY_R)

#define EV_CAMERA_MOVE (GLFW_KEY_SPACE)
#define EV_CAMERA_ROTATE (GLFW_MOUSE_BUTTON_3)
#define EV_CAMERA_ZOOM (GLFW_MOUSE_BUTTON_2)

#define EV_DELETE (GLFW_KEY_DELETE)
#define EV_ADD (GLFW_KEY_ENTER)
#define EV_CLEAR_ALL (GLFW_KEY_END)

#define EV_INCREASE_RESOLUTION (GLFW_KEY_UP)
#define EV_DECREASE_RESOLUTION (GLFW_KEY_DOWN)



#define EVENT_NONE -1

#define 	GLFW_MOUSE_BUTTON_1   0
#define 	GLFW_MOUSE_BUTTON_2   1
#define 	GLFW_MOUSE_BUTTON_3   2
#define 	GLFW_MOUSE_BUTTON_4   3
#define 	GLFW_MOUSE_BUTTON_5   4
#define 	GLFW_MOUSE_BUTTON_6   5
#define 	GLFW_MOUSE_BUTTON_7   6
#define 	GLFW_MOUSE_BUTTON_8   7

#define WINDOW_TRANSFORM 555

#define 	GLFW_KEY_1   49
#define 	GLFW_KEY_2   50
#define 	GLFW_KEY_3   51
#define 	GLFW_KEY_4   52
#define 	GLFW_KEY_5   53
#define 	GLFW_KEY_6   54
#define 	GLFW_KEY_7   55
#define 	GLFW_KEY_8   56
#define 	GLFW_KEY_9   57
#define 	GLFW_KEY_SEMICOLON   59 
#define 	GLFW_KEY_EQUAL   61 
#define 	GLFW_KEY_A   65
#define 	GLFW_KEY_B   66
#define 	GLFW_KEY_C   67
#define 	GLFW_KEY_D   68
#define 	GLFW_KEY_E   69
#define 	GLFW_KEY_F   70
#define 	GLFW_KEY_G   71
#define 	GLFW_KEY_H   72
#define 	GLFW_KEY_I   73
#define 	GLFW_KEY_J   74
#define 	GLFW_KEY_K   75
#define 	GLFW_KEY_L   76
#define 	GLFW_KEY_M   77
#define 	GLFW_KEY_N   78
#define 	GLFW_KEY_O   79
#define 	GLFW_KEY_P   80
#define 	GLFW_KEY_Q   81
#define 	GLFW_KEY_R   82
#define 	GLFW_KEY_S   83
#define 	GLFW_KEY_T   84
#define 	GLFW_KEY_U   85
#define 	GLFW_KEY_V   86
#define 	GLFW_KEY_W   87
#define 	GLFW_KEY_X   88
#define 	GLFW_KEY_Y   89
#define 	GLFW_KEY_Z   90
#define 	GLFW_KEY_LEFT_BRACKET   91 /* [ */
#define 	GLFW_KEY_BACKSLASH   92 /* \ */
#define 	GLFW_KEY_RIGHT_BRACKET   93 /* ] */
#define 	GLFW_KEY_GRAVE_ACCENT   96 /* ` */
#define 	GLFW_KEY_WORLD_1   161 /* non-US #1 */
#define 	GLFW_KEY_WORLD_2   162 /* non-US #2 */
#define 	GLFW_KEY_ESCAPE   256
#define 	GLFW_KEY_ENTER   257
#define 	GLFW_KEY_TAB   258
#define 	GLFW_KEY_BACKSPACE   259
#define 	GLFW_KEY_INSERT   260
#define 	GLFW_KEY_DELETE   261
#define 	GLFW_KEY_RIGHT   262
#define 	GLFW_KEY_LEFT   263
#define 	GLFW_KEY_DOWN   264
#define 	GLFW_KEY_UP   265
#define 	GLFW_KEY_PAGE_UP   266
#define 	GLFW_KEY_PAGE_DOWN   267
#define 	GLFW_KEY_HOME   268
#define 	GLFW_KEY_END   269
#define 	GLFW_KEY_CAPS_LOCK   280
#define 	GLFW_KEY_SCROLL_LOCK   281
#define 	GLFW_KEY_NUM_LOCK   282
#define 	GLFW_KEY_PRINT_SCREEN   283
#define 	GLFW_KEY_PAUSE   284
#define 	GLFW_KEY_F1   290
#define 	GLFW_KEY_F2   291
#define 	GLFW_KEY_F3   292
#define 	GLFW_KEY_F4   293
#define 	GLFW_KEY_F5   294
#define 	GLFW_KEY_F6   295
#define 	GLFW_KEY_F7   296
#define 	GLFW_KEY_F8   297
#define 	GLFW_KEY_F9   298
#define 	GLFW_KEY_F10   299
#define 	GLFW_KEY_F11   300
#define 	GLFW_KEY_F12   301
#define 	GLFW_KEY_F13   302
#define 	GLFW_KEY_F14   303
#define 	GLFW_KEY_F15   304
#define 	GLFW_KEY_F16   305
#define 	GLFW_KEY_F17   306
#define 	GLFW_KEY_F18   307
#define 	GLFW_KEY_F19   308
#define 	GLFW_KEY_F20   309
#define 	GLFW_KEY_F21   310
#define 	GLFW_KEY_F22   311
#define 	GLFW_KEY_F23   312
#define 	GLFW_KEY_F24   313
#define 	GLFW_KEY_F25   314
#define 	GLFW_KEY_KP_0   320
#define 	GLFW_KEY_KP_1   321
#define 	GLFW_KEY_KP_2   322
#define 	GLFW_KEY_KP_3   323
#define 	GLFW_KEY_KP_4   324
#define 	GLFW_KEY_KP_5   325
#define 	GLFW_KEY_KP_6   326
#define 	GLFW_KEY_KP_7   327
#define 	GLFW_KEY_KP_8   328
#define 	GLFW_KEY_KP_9   329
#define 	GLFW_KEY_KP_DECIMAL   330
#define 	GLFW_KEY_KP_DIVIDE   331
#define 	GLFW_KEY_KP_MULTIPLY   332
#define 	GLFW_KEY_KP_SUBTRACT   333
#define 	GLFW_KEY_KP_ADD   334
#define 	GLFW_KEY_KP_ENTER   335
#define 	GLFW_KEY_KP_EQUAL   336
#define 	GLFW_KEY_LEFT_SHIFT   340
#define 	GLFW_KEY_LEFT_CONTROL   341
#define 	GLFW_KEY_LEFT_ALT   342
#define 	GLFW_KEY_LEFT_SUPER   343
#define 	GLFW_KEY_RIGHT_SHIFT   344
#define 	GLFW_KEY_RIGHT_CONTROL   345
#define 	GLFW_KEY_RIGHT_ALT   346
#define 	GLFW_KEY_RIGHT_SUPER   347
#define 	GLFW_KEY_MENU   348