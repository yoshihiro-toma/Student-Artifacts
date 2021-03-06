//-------------------------------------------------------------------------
//
//	File	:CSceneXt@C[CSceneX.cpp]
//	Author	:DO
//
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
//CN[ht@C
//-------------------------------------------------------------------------
#include "CSceneX.h"
#include "CManager.h"
#include "CTextureManager.h"

//----------------------------------
//RXgN^
//----------------------------------
CSceneX::CSceneX(int nPriority) : CScene(nPriority)
{
	//****ΚuApxAXP[Μϊ»****
	m_Pos			 = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_Rot			 = D3DXVECTOR3(0.0f,0.0f,0.0f);
	m_Scl			 = D3DXVECTOR3(1.0f,1.0f,1.0f);
	m_Texture		 = NULL;
	m_TextureName	 = NULL;
	m_XfileName		 = NULL;
}

//----------------------------------
//fXgN^
//----------------------------------
CSceneX::~CSceneX()
{

}

//----------------------------------
//CSceneXΜϊ»
//----------------------------------
HRESULT CSceneX::Init(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	//***eNXeΜΗέέ***
	if(m_TextureName != NULL)
	{
		m_Texture = CManager::GetTextureManagerPointer()->GetTexture(CManager::GetTextureManagerPointer() -> Load(m_TextureName));
	}

	//fΜ[h
	m_XFile_Info = CManager::GetXFileManagerPointer()->GetXFile(CManager::GetXFileManagerPointer()->Load(m_XfileName));

	MatrixUpdate();

	return S_OK;
}

//----------------------------------
//CSceneXΜIΉ
//----------------------------------
void CSceneX::Uninit(void)
{
	Release();
}

//----------------------------------
//CSceneXΜXV
//----------------------------------
void CSceneX::Update(void)
{
	MatrixUpdate();
}

//----------------------------------
//CSceneXΜ`ζ
//----------------------------------
void CSceneX::Draw(void)
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	D3DXMATERIAL *pMat;
	D3DMATERIAL9 matDef;		//}bgΜftHg

	pDevice -> SetTransform(D3DTS_WORLD,&m_mtxWorld);	//έθ

	//fΜ`ζ
	pDevice -> GetMaterial(&matDef);
	pMat = (D3DXMATERIAL*)m_XFile_Info.BuffMat->GetBufferPointer();

	for(int nCntMat = 0;nCntMat < (int)m_XFile_Info.numMat;nCntMat++)
	{
		pDevice -> SetMaterial(&pMat[nCntMat].MatD3D);
		pDevice -> SetTexture(0,m_Texture);
		m_XFile_Info.Mesh -> DrawSubset(nCntMat);
	}
	pDevice -> SetMaterial(&matDef);
}

//----------------------------------
//CSceneXΜ}gbNX`FW
//----------------------------------
void  CSceneX::MatrixUpdate()
{
	LPDIRECT3DDEVICE9 pDevice;
	pDevice = GetDevice();

	D3DXMATRIX mtxScl,mtxRot,mtxTranslate;

	D3DXMatrixIdentity(&m_mtxWorld);
	D3DXMatrixScaling(&mtxScl,m_Scl.x,m_Scl.y,m_Scl.z);	//XP[π½f

	D3DXMatrixMultiply(&m_mtxWorld,&m_mtxWorld,&mtxScl);
	D3DXMatrixRotationYawPitchRoll(&mtxRot,m_Rot.y,m_Rot.x,m_Rot.z);		//|@sb`@[

	D3DXMatrixMultiply(&m_mtxWorld,&m_mtxWorld,&mtxRot);
	D3DXMatrixTranslation(&mtxTranslate,m_Pos.x,m_Pos.y,m_Pos.z);		//Κuπ½f

	D3DXMatrixMultiply(&m_mtxWorld,&m_mtxWorld,&mtxTranslate);
}

//----------------------------------
//CSceneXΜZbg|WV»ΜP
//----------------------------------
void  CSceneX::SetPosition(float x,float y,float z)
{
	m_Pos.x = x;
	m_Pos.y = y;
	m_Pos.z = z;
}

//----------------------------------
//CSceneXΜZbg|WV»ΜQ
//----------------------------------
void  CSceneX::SetPosition(D3DXVECTOR3 pos)
{
	m_Pos = pos;
}

//----------------------------------
//CSceneXΜQbg|WV
//----------------------------------
D3DXVECTOR3  CSceneX::GetPosition(void)
{
	return m_Pos;
}

//----------------------------------
//CSceneXΜZbg[e[V»ΜP
//----------------------------------
void CSceneX::SetRotation(float x,float y,float z)
{
	m_Rot.x = x;
	m_Rot.y = y;
	m_Rot.z = z;
}

//----------------------------------
//CSceneXΜZbg[e[V»Μ2
//----------------------------------
void CSceneX::SetRotation(D3DXVECTOR3 rot)
{
	m_Rot.x = rot.x;
	m_Rot.y = rot.y;
	m_Rot.z = rot.z;
}

//----------------------------------
//CSceneXΜQbg[e[V
//----------------------------------
D3DXVECTOR3 CSceneX::GetRotation(void)
{
	return m_Rot;
}

//----------------------------------
//CSceneXΜZbg^Cv
//----------------------------------
void CSceneX::SetType(int nType)
{
	m_Type = CTYPE_SCENEX;
}


//----------------------------------
//CSceneXDΜ	NGCg(ψt)
//TextureName:eNX`ΜΌO
//PosX,PosY,PosZ:eNX`ΜΐW
//----------------------------------
CSceneX *CSceneX::Create(LPCTSTR XfileName,D3DXVECTOR3 Pos)
{
	CSceneX *pSceneX;
	pSceneX = new CSceneX;

	pSceneX->m_XfileName	 = XfileName;
	pSceneX->m_Pos			 = Pos;
	
	pSceneX->Init();

	return pSceneX;
}
