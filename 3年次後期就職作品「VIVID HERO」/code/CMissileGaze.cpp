//-------------------------------------------------------------------------
//
//	File:CMissileGazeΜt@C[CMissileGaze.cpp]
//	Author:DO
//
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//CN[ht@C
//-------------------------------------------------------------------------
#include "CMissileGaze.h"

//-------------------------------------------------------------------------
//ΓIoΟΜϊ»
//-------------------------------------------------------------------------

//-----------------------------------
//CMissileGazeΜRXgN^
//-----------------------------------
CMissileGaze::CMissileGaze(int nPriority) : CScene2D(nPriority)
{

}

//-----------------------------------
//CMissileGazeΜfXgN^
//-----------------------------------
CMissileGaze::~CMissileGaze()
{

}

//-----------------------------------
//CMissileGazeΜϊ»
//-----------------------------------
HRESULT CMissileGaze::Init(void)
{
	float Adjustment = 60.0f;
	float sizeX = 200.0f;
	float sizeY = 200.0f;

//	CScene2D::Create(80,"./data/TEXTURE/Game/UI/MissileFrame00.png",
//		D3DXVECTOR3(SCREEN_WIDTH - sizeX/2 - Adjustment + 10.0f,SCREEN_HEIGHT - sizeY/2 - Adjustment - 10.0f,0.0f),D3DXVECTOR3(250.0f,300.0f,0.0f));
//
//	CScene2D::Create(80,"./data/TEXTURE/Game/UI/MissleTex001.png",
//		D3DXVECTOR3(SCREEN_WIDTH - sizeX/2 - Adjustment,SCREEN_HEIGHT - sizeY/2 - Adjustment,0.0f),D3DXVECTOR3(sizeX,sizeY,0.0f));
//	CScene2D::Create(80,"./data/TEXTURE/Game/UI/MissleTex002.png",
//		D3DXVECTOR3(SCREEN_WIDTH - sizeX/2 - Adjustment,SCREEN_HEIGHT - sizeY/2 - Adjustment,0.0f),D3DXVECTOR3(sizeX,sizeY,0.0f));


	return S_OK;
}

//-----------------------------------
//CMissileGazeΜIΉ
//-----------------------------------
void CMissileGaze::Uninit(void)
{

}

//-----------------------------------
//CMissileGazeΜXV
//-----------------------------------
void CMissileGaze::Update(void)
{

}

//-----------------------------------
//CMissileGazeΜ`ζ
//-----------------------------------
void CMissileGaze::Draw(void)
{

}

//-----------------------------------
//CMissileGazeΜNGCg
//-----------------------------------
CMissileGaze *CMissileGaze::Create()
{
	CMissileGaze *pMissileGaze;
	pMissileGaze = new CMissileGaze;

	pMissileGaze->Init();

	return pMissileGaze;

}

