/**
 * @file func.hpp
 * @author Pojmaevich Mirko (mirkopoj@gmail.com)
 *         Torletti Lara (lara.a.torletti@gmail.com)
 * @brief menu maker
 * @version 0.1
 * @date 2024-06-13
 *
 * @copyright Copyright (c) 2024
 *
 */

#pragma once
#include <termios.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

void gotoxy(int x, int y);

void initTermios(int echo);

void resetTermios(void);

bool kbhit();

char getch_(int echo);

char getch(void);

char getche(void);

int getmax_x();

int getmax_y();