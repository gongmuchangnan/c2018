# include <stdio.h>
# include <stdlib.h>
# include <Windows.h>
#include <conio.h>

# define WAITTIME 40

void print_space(int cnt);
int main(void)
{
	//��ȡ��Ļ��� 
	HANDLE handle_out;                              //����һ�����  
    CONSOLE_SCREEN_BUFFER_INFO screen_info;         //���崰�ڻ�������Ϣ�ṹ��  
    COORD pos = {0, 0};                             //����һ������ṹ��  
    handle_out = GetStdHandle(STD_OUTPUT_HANDLE);   //��ñ�׼����豸���  
    GetConsoleScreenBufferInfo(handle_out, &screen_info);   //��ȡ������Ϣ 
    const int LENGTH = screen_info.dwSize.X - 1;        //screen_info.dwSize.X(��������ȣ�Ҳ���Ǻ��������ֵ��1)
    //����ʵ�� 
	int cnt;
	int a, b, c;
	for(cnt = 0;; cnt++)
	{
		//�����߼�����, ʵ��ѭ�� 
		a = cnt % LENGTH;
		b = (cnt / LENGTH) % 2;
		c = abs(LENGTH * b - a);
		print_space(c);
		
		printf("R");
		Sleep(WAITTIME);
		system("cls");
	}
	CloseHandle(handle_out);    //�رձ�׼����豸���
}
void print_space(int cnt)
{
	int temp;
	for(temp = 0; temp < cnt; temp++)
	{
		printf(" ");
	}
}
