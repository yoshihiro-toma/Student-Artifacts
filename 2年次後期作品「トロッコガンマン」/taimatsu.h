//��-------------------------------------------------------------------------��
//
//	File	:��������[taimatsu.h]
//	Author	:�����D�O
//
//��-------------------------------------------------------------------------��

//��-------------------------------------------------------------------------��
//�v���g�^�C�v�錾
//��-------------------------------------------------------------------------��
void InitTaimatsu(void);
void UninitTaimatsu(void);
void UpdateTaimatsu(void);
void DrawTaimatsu(void);

D3DXVECTOR3 Getpostaimatsu(void);

//�����̐��ɂ���ăo�O��
#define TAIMATSU_KANKAKU	(1000.0f)	//������ݒu���銴�o
#define TAIMATSU_POSX		(65)		//�����̍��E�ړ��̈ʒu