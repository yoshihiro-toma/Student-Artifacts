//-------------------------------------------------------------------------
//
//	^Cgwicppt@C[TittleBG.cpp]
//	Author : touma yoshihiro
//
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//CN[ht@C
//-------------------------------------------------------------------------
#include"main.h"
#include"TittleBG.h"
//-------------------------------------------------------------------------
//}Nθ`
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//vg^CvιΎ
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//O[oΟ
//-------------------------------------------------------------------------
LPDIRECT3DTEXTURE9 t_bgTexturePolygon[TITLEBG_TEXTURE_NUM];
LPDIRECT3DVERTEXBUFFER9 t_bgVtxBuffPolygon[TITLEBG_TEXTURE_NUM];
VERTEX_2D *t_pVtxBG;		//ζΜΐWΜ|C^

//-------------------------------------------------------------------------
//^CgwiΜϊ»
//-------------------------------------------------------------------------
void InitTittleBG(void)
{
	LPDIRECT3DDEVICE9 bgDevice;
	bgDevice = GetDevice();

	for(int nCnt = 0;nCnt < TITLEBG_TEXTURE_NUM;nCnt++)
	{
		t_bgTexturePolygon[nCnt] = NULL;
		t_bgVtxBuffPolygon[nCnt] = NULL;

		bgDevice->CreateVertexBuffer(sizeof(VERTEX_2D)*4,D3DUSAGE_WRITEONLY,FVF_VERTEX_2D,D3DPOOL_MANAGED,&t_bgVtxBuffPolygon[nCnt],NULL);
	}

	//wiζΜξρo^
	t_bgVtxBuffPolygon[0]->Lock(0,0,(void**)&t_pVtxBG,0);

	//Έ_ξρΜέθ
	t_pVtxBG[0].pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
	t_pVtxBG[1].pos = D3DXVECTOR3(SCREEN_WIDTH,0.0f,0.0f);
	t_pVtxBG[2].pos = D3DXVECTOR3(0.0f,SCREEN_HEIGHT,0.0f);
	t_pVtxBG[3].pos = D3DXVECTOR3(SCREEN_WIDTH,SCREEN_HEIGHT,0.0f);

	t_pVtxBG[0].rhw = 1.0f;
	t_pVtxBG[1].rhw = 1.0f;
	t_pVtxBG[2].rhw = 1.0f;
	t_pVtxBG[3].rhw = 1.0f;

	t_pVtxBG[0].col = D3DCOLOR_RGBA(255,255,255,255);
	t_pVtxBG[1].col = D3DCOLOR_RGBA(255,255,255,255);
	t_pVtxBG[2].col = D3DCOLOR_RGBA(255,255,255,255);
	t_pVtxBG[3].col = D3DCOLOR_RGBA(255,255,255,255);

	t_pVtxBG[0].tex = D3DXVECTOR2(0.0,0.0);
	t_pVtxBG[1].tex = D3DXVECTOR2(1.0,0.0);
	t_pVtxBG[2].tex = D3DXVECTOR2(0.0,1.0);
	t_pVtxBG[3].tex = D3DXVECTOR2(1.0,1.0);
			
	D3DXCreateTextureFromFile(GetDevice(),"./data/TEXTURE/HAL.jpg",&t_bgTexturePolygon[0]);

	t_bgVtxBuffPolygon[0]->Unlock();

	t_bgVtxBuffPolygon[1]->Lock(0,0,(void**)&t_pVtxBG,0);

	//Έ_ξρΜέθ
	t_pVtxBG[0].pos = D3DXVECTOR3(100,100,0.0f);
	t_pVtxBG[1].pos = D3DXVECTOR3(650,100,0.0f);
	t_pVtxBG[2].pos = D3DXVECTOR3(100,400,0.0f);
	t_pVtxBG[3].pos = D3DXVECTOR3(650,400,0.0f);

	t_pVtxBG[0].rhw = 1.0f;
	t_pVtxBG[1].rhw = 1.0f;
	t_pVtxBG[2].rhw = 1.0f;
	t_pVtxBG[3].rhw = 1.0f;

	t_pVtxBG[0].col = D3DCOLOR_RGBA(255,255,255,255);
	t_pVtxBG[1].col = D3DCOLOR_RGBA(255,255,255,255);
	t_pVtxBG[2].col = D3DCOLOR_RGBA(255,255,255,255);
	t_pVtxBG[3].col = D3DCOLOR_RGBA(255,255,255,255);

	t_pVtxBG[0].tex = D3DXVECTOR2(0.0,0.0);
	t_pVtxBG[1].tex = D3DXVECTOR2(1.0,0.0);
	t_pVtxBG[2].tex = D3DXVECTOR2(0.0,1.0);
	t_pVtxBG[3].tex = D3DXVECTOR2(1.0,1.0);
			
	D3DXCreateTextureFromFile(GetDevice(),"./data/TEXTURE/titlelogo000.png",&t_bgTexturePolygon[1]);

	t_bgVtxBuffPolygon[1]->Unlock();

}
//-------------------------------------
//^CgwiIΉ
//-------------------------------------
void UninitTittleBG(void)
{
	//obt@Μ
	
	for(int nCnt = 0;nCnt < TITLEBG_TEXTURE_NUM;nCnt++)
	{
		if(t_bgVtxBuffPolygon[nCnt] != NULL)
		{
			t_bgVtxBuffPolygon[nCnt]->Release();
			t_bgVtxBuffPolygon[nCnt] = NULL;
		}
	
			//eNX`Μ
		if(t_bgTexturePolygon[nCnt] != NULL)
		{
			t_bgTexturePolygon[nCnt]->Release();
			t_bgTexturePolygon[nCnt] = NULL;
		}
	}
}
//-------------------------------------
//^CgwiΜXV
//-------------------------------------
void UpdateTittleBG(void)
{

}
//-------------------------------------
//^CgwiΜ`ζ
//-------------------------------------
void DrawTittleBG(void)
{
	for(int nCnt = 0;nCnt < TITLEBG_TEXTURE_NUM;nCnt++)
	{
		//wiΜ`ζ
		GetDevice()->SetStreamSource(0,t_bgVtxBuffPolygon[nCnt],0,sizeof(VERTEX_2D));
		//Έ_tH[}bgΜέθ
		GetDevice()->SetFVF(FVF_VERTEX_2D);
		//eNX`Μέθ
		GetDevice()->SetTexture(0,t_bgTexturePolygon[nCnt]);
		//|SΜ`ζ
		GetDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,4);
	}
}