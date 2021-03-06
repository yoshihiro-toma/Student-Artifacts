//=============================================================================
//
// サウンド処理 [sound.h]
// Author : AKIRA TANAKA
//
//=============================================================================
#ifndef _SOUND_H_
#define _SOUND_H_

#include "main.h"

//*****************************************************************************
// サウンドファイル
//*****************************************************************************
typedef enum
{
	SOUND_LABEL_TITLE_BGM = 0,			// BGM1
	SOUND_LABEL_GAME_MAIN,				// BGM2
	SOUND_LABEL_SE_DECIDE,				// 決定音
	SOUND_LABEL_SE_bomb000,				// 爆発音
	SOUND_LABEL_SE_gakutyou_beam_05,	// レーザー発射音
	SOUND_LABEL_SE_sen_ge_bom18,		// 一斉爆発音
	SOUND_LABEL_MAX,
} SOUND_LABEL;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
HRESULT InitSound(HWND hWnd);
void UninitSound(void);
HRESULT PlaySound(SOUND_LABEL label);
void StopSound(SOUND_LABEL label);
void StopSound(void);

#endif
