#pragma once

#ifndef __DEFINE_H__
#define __DEFINE_H__

#define MAX_NAME_SIZE	16
#define MAX_MESSAGE_SIZE 128
#define SAFE_DELETE(p) if (p) { delete p; p = nullptr;}
#define SAFE_DELETE_ARR(p) if (p) { delete[] p; p = nullptr;}

#define LEFT	75
#define RIGHT	77
#define UP		72
#define DOWN	80

#endif