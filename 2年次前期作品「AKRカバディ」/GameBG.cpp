//-------------------------------------------------------------------------
//
//	Q[wicppt@C[polygon.cpp]
//	Author : touma yoshihiro
//
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//CN[ht@C
//-------------------------------------------------------------------------
#include"main.h"
#include"GameBG.h"
//-------------------------------------------------------------------------
//}Nθ`
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//vg^CvιΎ
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//O[oΟ
//-------------------------------------------------------------------------
LPDIRECT3DTEXTURE9 g_bgTexturePolygon[BG_NUM];
LPDIRECT3DVERTEXBUFFER9 g_bgVtxBuffPolygon[BG_NUM];
VERTEX_2D *g_pVtxBG;						//ζΜΐWΜ|C^

//-------------------------------------------------------------------------
//Q[wiΜϊ»
//-------------------------------------------------------------------------
void InitGameBG(void)
{
	LPDIRECT3DDEVICE9 bgDevice;
	bgDevice = GetDevice();

	for(int nCnt = 0;nCnt < BG_NUM;nCnt++)
	{
		g_bgTexturePolygon[nCnt] = NULL;
		g_bgVtxBuffPolygon[nCnt] = NULL;

		bgDevice->CreateVertexBuffer(sizeof(VERTEX_2D)*4,D3DUSAGE_WRITEONLY,FVF_VERTEX_2D,D3DPOOL_MANAGED,&g_bgVtxBuffPolygon[nCnt],NULL);
	}
	//wiζΜξρo^
	g_bgVtxBuffPolygon[0]->Lock(0,0,(void**)&g_pVtxBG,0);

	//Έ_ξρΜέθ
	g_pVtxBG[0].pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
	g_pVtxBG[1].pos = D3DXVECTOR3(SCREEN_WIDTH,0.0f,0.0f);
	g_pVtxBG[2].pos = D3DXVECTOR3(0.0f,SCREEN_HEIGHT,0.0f);
	g_pVtxBG[3].pos = D3DXVECTOR3(SCREEN_WIDTH,SCREEN_HEIGHT,0.0f);

	g_pVtxBG[0].rhw = 1.0f;
	g_pVtxBG[1].rhw = 1.0f;
	g_pVtxBG[2].rhw = 1.0f;
	g_pVtxBG[3].rhw = 1.0f;

	g_pVtxBG[0].col = D3DCOLOR_RGBA(255,255,255,255);
	g_pVtxBG[1].col = D3DCOLOR_RGBA(255,255,255,255);
	g_pVtxBG[2].col = D3DCOLOR_RGBA(255,255,255,255);
	g_pVtxBG[3].col = D3DCOLOR_RGBA(255,255,255,255);

	g_pVtxBG[0].tex = D3DXVECTOR2(0.0,0.0);
	g_pVtxBG[1].tex = D3DXVECTOR2(1.0,0.0);
	g_pVtxBG[2].tex = D3DXVECTOR2(0.0,1.0);
	g_pVtxBG[3].tex = D3DXVECTOR2(1.0,1.0);
			
	D3DXCreateTextureFromFile(GetDevice(),"./data/TEXTURE/game_BG02.jpg",&g_bgTexturePolygon[0]);

	g_bgVtxBuffPolygon[0]->Unlock();
	
}
//-------------------------------------
//Q[wiIΉ
//-------------------------------------
void UninitGameBG(void)
{
	for(int nCnt = 0;nCnt < BG_NUM;nCnt++)
	{
		//obt@Μ	
		if(g_bgVtxBuffPolygon[nCnt] != NULL)
		{
			g_bgVtxBuffPolygon[nCnt]->Release();
			g_bgVtxBuffPolygon[nCnt] = NULL;
		}
	
			//eNX`Μ
		if(g_bgTexturePolygon[nCnt] != NULL)
		{
			g_bgTexturePolygon[nCnt]->Release();
			g_bgTexturePolygon[nCnt] = NULL;
		}
	}
}
//-------------------------------------
//Q[wiΜXV
//-------------------------------------
void UpdateGameBG(void)
{

}
//-------------------------------------
//Q[wiΜ`ζ
//-------------------------------------
void DrawGameBG(void)
{
	for(int nCnt = 0;nCnt < BG_NUM;nCnt++)
	{
		//wiΜ`ζ
		GetDevice()->SetStreamSource(0,g_bgVtxBuffPolygon[nCnt],0,sizeof(VERTEX_2D));
		//Έ_tH[}bgΜέθ
		GetDevice()->SetFVF(FVF_VERTEX_2D);
		//eNX`Μέθ
		GetDevice()->SetTexture(0,g_bgTexturePolygon[nCnt]);
		//|SΜ`ζ
		GetDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);
	}
}