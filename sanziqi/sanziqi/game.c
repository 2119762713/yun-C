#include "game.h"


//��������
void Init(char board[ROW][COL], int row, int col)
{
	for (int i=0;i<row;i++)
	{
		//���Ǹ�һ�г�ʼ���ո�
		for (int j = 0; j < col; j++)
		{
			//���Ǹ�һ�г�ʼ���ո�
			board[i][j] = ' ';//���ھ͸������ʼ���ո���
		}
	}
}

//void DisplayBoard(char board[ROW][COL], int row, int col)//�����Ż��Ż�һ��
//{
//	int i = 0;
//	for (i = 0; i < row; i++)
//	{
//		//���Ǵ�ӡһ������Ԫ��
//		printf(" %c | %c | %c \n",board[i][0], board[i][1], board[i][2]);
//		if (i<row-1)//��������ֻ��ӡ�������ۣ������Ǵ�ӡ���в�����
//		{
//			//�ٴ�ָ���
//			printf("---|---|---\n");
//	}
//
//	/*
//	   |   |
//	---|---|---
//	   |   |
//	---|---|---
//	   |   |
//	 *///�������Ҫ��ӡ������
//}



void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);//���Ǵ�ӡһ������Ԫ��+|
			//�����Ǵ�ӡ ����Ԫ����ֵ 
			if (j < col - 1)//��������ֻ��ӡ�������ۣ������Ǵ�ӡ���в�����
				//�����ж��Ǵ�ӡ   |   |   ��������ƽ���Ǵ�ӡ   |   |   |
			{
				printf("|");
				//�����Ǵ�ӡ    |      |
			}
		}
		//������������ѭ��3���� ��ֵ | ��ֵ | ��ֵ 
		printf("\n");
		if (i < row - 1)//��������ֻ��ӡ�������ۣ������Ǵ�ӡ���в�����
			//                  |   |                             |   |     
			//�����ж��Ǵ�ӡ ---|---|---������ж����Ǵ�ӡ���� ---|---|---������
			//                  |   |                             |   |     
			//               ---|---|---                       ---|---|---
			//                  |   |                             |   |    
			//                                                 ---|---|--- 
		{
			for (j = 0; j < col; j++)
			{
				  //�ٴ�ָ���
				  printf("---");
				  //�����Ǵ�ӡ ---
				if(j<col-1)//��������ֻ��ӡ�������ۣ������Ǵ�ӡ���в�����
					//�����ж��Ǵ�ӡ   |   |   ��������ƽ���Ǵ�ӡ   |   |   |
				  printf("|");
				//�����Ǵ�ӡ   |   |
			}
			printf("\n");
			//�����������ӡ��---|---|---
		}
	}
	//����ȫ����������ӡ   |   |   
	//                  ---|---|---
	//                     |   |   
    //                  ---|---|---
	//                     |   |   
}//�ǲ��Ǻ����ΪʲôҪ��ô�Ż�����Ϊ�� ��Ҫ��10*10��������ѳ����ĳ�10�����ˣ�����������Щ�㷨


void PlayerMove(char board[ROW][COL], int row, int col)//����������ʵ�ֺ���
{
	int x = 0;
	int y = 0;
	printf("�����!\n");
	while (1)//whileѭ������Ϊ�� �������������������������
	{
		printf("������Ҫ�µ�����:>");
		int b = scanf("%d%d", &x, &y);//���������������㲻֪���ǲ��ǺϷ���Ч�ģ����Ǿ���Ҫ�ж���
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�����ж�������������ֻ����1-3��Ϊʲô����0�أ���Ϊ��Ҳ��ǳ���Ա����֪�������±��Ǵ�0��ʼ�ģ�һ�㶼�Ǿ��ô�1��ʼ��
		{
			if (board[x - 1][y - 1] == ' ')//����������������ʼ���ǿո�ʹ���û�б��¹�//�������������겻���±꣬����Ҫ-1
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������Ѿ��¹�����,�����ظ����壡\n");
			}
		}
		else
		{
			printf("����Ƿ�������������!\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)//�����������ʵ�ֺ���
{
	int x = 0;
	int y = 0;
	printf("������!\n");
	while(1)
	{
		x = rand() % row;//������������ɵ������������,ȡģrow����3,���������ֵ��Χ��0-2֮��
		y = rand() % col;//������������ɵ������������,ȡģcol����3,���������ֵ��Χ��0-2֮��
		//�������ɵ����겻�����ǷǷ������꣬��Ϊ���ǵ����ֵ��Զ��0-2���±꣬���Բ���-1
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int  IsFull(char board[ROW][COL], int row, int col)//�ж���ƽ�ֻ��Ǽ�����Ϸ���������˷���һ��1����������0
{
	int i = 0;
	int j = 0;
	for (i=0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')//ѭ���ж�ÿ��ÿ����û�пո�����о�������û������0�����򷵻�1
			{
				return 0;
			}
		}
	}
	return 1;//���˷���1
}

char RetBOOT(char board[ROW][COL], int row, int col)//�жϵ��Ի��������Ӯ
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		////�����жϺ�����                  ***
		//                ***
		//                       ***
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] !=' ')
		{
			return board[i][1];
		}
	}

	for (i = 0; i < col; i++)
	{
		////�����ж�������*    *    *
		//                *    *    *
		//                *    *    *
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[1][i] !=' ')
		{
			return board[1][i];
		}
	}
	//������if�ж����ж϶Խ��ߵ�    *               
	//                                *           
	//                                  *       
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//������if�ж����ж϶Խ��ߵ�                 *
	//                                         *
	//                                       *
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//�ж��Ƿ�ƽ��
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
		return 'C';
}