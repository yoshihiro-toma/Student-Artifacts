//-------------------------------------------------------------------------
//
//	Ugwicppt@C[ResultBG.cpp]
//	Author : touma yoshihiro
//
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//CN[ht@C
//-------------------------------------------------------------------------
#include"main.h"
#include"ResultBG.h"
//-------------------------------------------------------------------------
//}Nθ`
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//vg^CvιΎ
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//O[oΟ
//-------------------------------------------------------------------------
LPDIRECT3DTEXTURE9 r_bgTexturePolygon[RESULTBG_TETURE_NUM];
LPDIRECT3DVERTEXBUFFER9 r_bgVtxBuffPolygon[RESULTBG_TETURE_NUM];
VERTEX_2D *r_pVtxBG;		//ζΜΐWΜ|C^

//-------------------------------------------------------------------------
//UgwiΜϊ»
//-------------------------------------------------------------------------
void InitResultBG(void)
{
	LPDIRECT3DDEVICE9 bgDevice;
	bgDevice = GetDevice();

	for(int nCnt = 0;nCnt < RESULTBG_TETURE_NUM;nCnt++)
	{
		r_bgTexturePolygon[nCnt] = NULL;
		r_bgVtxBuffPolygon[nCnt] = NULL;

		bgDevice->CreateVertexBuffer(sizeof(VERTEX_2D)*4,D3DUSAGE_WRITEONLY,FVF_VERTEX_2D,D3DPOOL_MANAGED,&r_bgVtxBuffPolygon[nCnt],NULL);
	}
		//wiζΜξρo^
		r_bgVtxBuffPolygon[0]->Lock(0,0,(void**)&r_pVtxBG,0);

		//Έ_ξρΜέθ
		r_pVtxBG[0].pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
		r_pVtxBG[1].pos = D3DXVECTOR3(SCREEN_WIDTH,0.0f,0.0f);
		r_pVtxBG[2].pos = D3DXVECTOR3(0.0f,SCREEN_HEIGHT,0.0f);
		r_pVtxBG[3].pos = D3DXVECTOR3(SCREEN_WIDTH,SCREEN_HEIGHT,0.0f);

		r_pVtxBG[0].rhw = 1.0f;
		r_pVtxBG[1].rhw = 1.0f;
		r_pVtxBG[2].rhw = 1.0f;
		r_pVtxBG[3].rhw = 1.0f;

		r_pVtxBG[0].col = D3DCOLOR_RGBA(255,255,255,255);
		r_pVtxBG[1].col = D3DCOLOR_RGBA(255,255,255,255);
		r_pVtxBG[2].col = D3DCOLOR_RGBA(255,255,255,255);
		r_pVtxBG[3].col = D3DCOLOR_RGBA(255,255,255,255);

		r_pVtxBG[0].tex = D3DXVECTOR2(0.0,0.0);
		r_pVtxBG[1].tex = D3DXVECTOR2(1.0,0.0);
		r_pVtxBG[2].tex = D3DXVECTOR2(0.0,1.0);
		r_pVtxBG[3].tex = D3DXVECTOR2(1.0,1.0);
			
		D3DXCreateTextureFromFile(GetDevice(),"./data/TEXTURE/yuuhi.jpg",&r_bgTexturePolygon[0]);

		r_bgVtxBuffPolygon[0]->Unlock();

		//wiζΜξρo^
		r_bgVtxBuffPolygon[1]->Lock(0,0,(void**)&r_pVtxBG,0);

		//Έ_ξρΜέθ
		r_pVtxBG[0].pos = D3DXVECTOR3(0.0f,0.0f,0.0f);
		r_pVtxBG[1].pos = D3DXVECTOR3(SCREEN_WIDTH,0.0f,0.0f);
		r_pVtxBG[2].pos = D3DXVECTOR3(0.0f,SCREEN_HEIGHT,0.0f);
		r_pVtxBG[3].pos = D3DXVECTOR3(SCREEN_WIDTH,SCREEN_HEIGHT,0.0f);

		r_pVtxBG[0].rhw = 1.0f;
		r_pVtxBG[1].rhw = 1.0f;
		r_pVtxBG[2].rhw = 1.0f;
		r_pVtxBG[3].rhw = 1.0f;

		r_pVtxBG[0].col = D3DCOLOR_RGBA(255,255,255,255);
		r_pVtxBG[1].col = D3DCOLOR_RGBA(255,255,255,255);
		r_pVtxBG[2].col = D3DCOLOR_RGBA(255,255,255,255);
		r_pVtxBG[3].col = D3DCOLOR_RGBA(255,255,255,255);

		r_pVtxBG[0].tex = D3DXVECTOR2(0.0,0.0);
		r_pVtxBG[1].tex = D3DXVECTOR2(1.0,0.0);
		r_pVtxBG[2].tex = D3DXVECTOR2(0.0,1.0);
		r_pVtxBG[3].tex = D3DXVECTOR2(1.0,1.0);
			
		D3DXCreateTextureFromFile(GetDevice(),"./data/TEXTURE/thankyou.png",&r_bgTexturePolygon[1]);

		r_bgVtxBuffPolygon[1]->Unlock();

		//wiζΜξρo^
		r_bgVtxBuffPolygon[2]->Lock(0,0,(void**)&r_pVtxBG,0);

		//Έ_ξρΜέθ
		r_pVtxBG[0].pos = D3DXVECTOR3(170,125,0.0f);
		r_pVtxBG[1].pos = D3DXVECTOR3(310,125,0.0f);
		r_pVtxBG[2].pos = D3DXVECTOR3(170,225,0.0f);
		r_pVtxBG[3].pos = D3DXVECTOR3(310,225,0.0f);

		r_pVtxBG[0].rhw = 1.0f;
		r_pVtxBG[1].rhw = 1.0f;
		r_pVtxBG[2].rhw = 1.0f;
		r_pVtxBG[3].rhw = 1.0f;

		r_pVtxBG[0].col = D3DCOLOR_RGBA(255,255,255,255);
		r_pVtxBG[1].col = D3DCOLOR_RGBA(255,255,255,255);
		r_pVtxBG[2].col = D3DCOLOR_RGBA(255,255,255,255);
		r_pVtxBG[3].col = D3DCOLOR_RGBA(255,255,255,255);

		r_pVtxBG[0].tex = D3DXVECTOR2(0.0,0.0);
		r_pVtxBG[1].tex = D3DXVECTOR2(1.0,0.0);
		r_pVtxBG[2].tex = D3DXVECTOR2(0.0,1.0);
		r_pVtxBG[3].tex = D3DXVECTOR2(1.0,1.0);
			
		D3DXCreateTextureFromFile(GetDevice(),"./data/TEXTURE/gekiha.png",&r_bgTexturePolygon[2]);

		r_bgVtxBuffPolygon[2]->Unlock();
}
//-------------------------------------
//UgwiIΉ
//-------------------------------------
void UninitResultBG(void)
{
	//obt@Μ
	
	for(int nCnt = 0;nCnt < RESULTBG_TETURE_NUM;nCnt++)
	{
		if(r_bgVtxBuffPolygon[nCnt] != NULL)
		{
			r_bgVtxBuffPolygon[nCnt]->Release();
			r_bgVtxBuffPolygon[nCnt] = NULL;
		}
	
			//eNX`Μ
		if(r_bgTexturePolygon[nCnt] != NULL)
		{
			r_bgTexturePolygon[nCnt]->Release();
			r_bgTexturePolygon[nCnt] = NULL;
		}
	}
}
//-------------------------------------
//UgwiΜXV
//-------------------------------------
void UpdateResultBG(void)
{

}
//-------------------------------------
//UgwiΜ`ζ
//-------------------------------------
void DrawResultBG(void)
{
	for(int nCnt = 0;nCnt < RESULTBG_TETURE_NUM;nCnt++)
	{
		//wiΜ`ζ
		GetDevice()->SetStreamSource(0,r_bgVtxBuffPolygon[nCnt],0,sizeof(VERTEX_2D));
		//Έ_tH[}bgΜέθ
		GetDevice()->SetFVF(FVF_VERTEX_2D);
		//eNX`Μέθ
		GetDevice()->SetTexture(0,r_bgTexturePolygon[nCnt]);
		GetDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP,0,2);
	}
}