#include<stdio.h>

	struct Student
	{
		long long num;//ѧ��
		char name[20];//����
		char sex[10];//�Ա�
		int English;//Ӣ��
		int PC;//�����
		int math;//����
		int sum;//�ܷ�
		double avg;//ƽ����
	}stu[100];

	void Show_Header(int f) {
		if (f) {
			printf("\n���\tѧ��\t����\t�Ա�\tӢ��\t�����\t����\t�ܷ�\tƽ����\n");//�������ŵı�ͷ
		}
		else {
			printf("\nѧ��\t����\t�Ա�\tӢ��\t�����\t����\t�ܷ�\tƽ����\n");//���������ŵı�ͷ
		}
	}

	void Main_Menu() {
		printf("\n\t\t\t\tѧ����Ϣ����ϵͳ\n");
		printf("\t1.��ʾѧ����Ϣ\n");
		printf("\t2.����ѧ����Ϣ\n");
		printf("\t3.�޸�ѧ����Ϣ\n");
		printf("\t4.���ѧ����Ϣ\n");
		printf("\t��ѡ��1-4����");
	}//������˵�

	void Update_Menu() {
		printf("\n\t1.����\n");
		printf("\t2.�Ա�\n");
		printf("\t3.Ӣ��\n");
		printf("\t4.�����\n");
		printf("\t5.����\n");
	}//����޸��б�

	void InputStu_wwl(int n) {
		scanf_s("%lld", &stu[n].num);
		getchar();
		scanf_s("%s", stu[n].name,20);
		getchar();
		scanf_s("%s", stu[n].sex,10);
		scanf_s("%d", &stu[n].English);
		scanf_s("%d", &stu[n].PC);
		scanf_s("%d", &stu[n].math);
		stu[n].sum = stu[n].English + stu[n].PC + stu[n].math;
		stu[n].avg = (double)stu[n].sum / 3.0;
	}//¼��ѧ������Ϣ

	void OutputStu(int n) {
		printf("%lld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2lf\n", stu[n].num, stu[n].name, stu[n].sex, stu[n].English, stu[n].PC, stu[n].math, stu[n].sum, stu[n].avg);
	}//���ָ��ѧ������Ϣ

	void OutputStu_wwl(int n) {
		Show_Header(1);
		for (int i = 0;i < n;i++) {
			printf("%d\t%lld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2lf\n", i+1,stu[i].num, stu[i].name, stu[i].sex, stu[i].English, stu[i].PC, stu[i].math, stu[i].sum, stu[i].avg);
		}
		printf("\n");
	}//�������ѧ������Ϣ

	int SearchStu_wwl(long long x, int n){
		int f = 1;
		for (int i = 0;i < n;i++) {
			if (x == stu[i].num) {
				printf("\n���ҳɹ�\n");
				f = 0;
				Show_Header(0);
				OutputStu(i);
				return i;
			}
		}
		if (f) {
			printf("\n��������Ϣ������");
		}
		return -1;
}//����ѧ����Ϣ��ͨ��ѧ�Ų���ѧ����Ϣ

	void UpdataStu_wwl(int i) {
		if (i == -1) printf("\n��������Ϣ�����ڣ��޸�ʧ��");
		else {
			int a = 0;
			int f = 1;
			while (f) {
				Update_Menu();
				printf("\n��ѡ��Ҫ�޸ĵ���Ϣ��1-5����");
				scanf_s("%d", &a);
				switch (a)
				{
				case 1:printf("������Ҫ�޸ļ�¼����Ϣ��");
					scanf_s("%s", stu[i].name, 20);
					f = 0;
					break;
				case 2:printf("������Ҫ�޸ļ�¼����Ϣ��");
					scanf_s("%s", stu[i].sex, 10);
					f = 0;
					break;
				case 3:printf("������Ҫ�޸ļ�¼����Ϣ��");
					scanf_s("%d", &stu[i].English);
					stu[i].sum = stu[i].English + stu[i].PC + stu[i].math;
					stu[i].avg = (double)stu[i].sum / 3.0;
					f = 0;
					break;
				case 4:printf("������Ҫ�޸ļ�¼����Ϣ��");
					scanf_s("%d", &stu[i].PC);
					stu[i].sum = stu[i].English + stu[i].PC + stu[i].math;
					stu[i].avg = (double)stu[i].sum / 3.0;
					f = 0;
					break;
				case 5:printf("������Ҫ�޸ļ�¼����Ϣ��");
					scanf_s("%d", &stu[i].math);
					stu[i].sum = stu[i].English + stu[i].PC + stu[i].math;
					stu[i].avg = (double)stu[i].sum / 3.0;
					f = 0;
					break;
				default:
					printf("\n");
				}
			}
			Show_Header(0);
			OutputStu(i);
		}
	}//ͨ��ѧ�ţ��޸�ѧ��ָ����Ϣ

	void AppendStu_wwl(int* p) {
		printf("������ѧ����Ϣ��");
		InputStu_wwl(*p);
		++* p;
		printf("���³ɹ�\n");
	}//���ѧ����Ϣ

		int main(){
			int n, N;//nΪѧ��������NΪ����ѡ��
			long long x=0;
			printf("������ѧ����¼����n=");
			scanf_s("%d", &n);
			printf("������ѧ����Ϣ��");
			for (int i = 0;i < n;i++) {
				InputStu_wwl(i);
			}
			while (1) {
				Main_Menu();
				scanf_s("%d", &N);
				switch (N)
				{
				case 1:OutputStu_wwl(n);
					break;
				case 2:printf("����������ҵ�ѧ�ţ�");
					long long x;
					scanf_s("%lld", &x);
					if (SearchStu_wwl(x, n) == -1) printf(",����ʧ��");
					break;
				case 3:printf("������Ҫ�޸ļ�¼��ѧ�ţ�");
					scanf_s("%lld", &x);
					UpdataStu_wwl(SearchStu_wwl(x, n));
					break;
				case 4:AppendStu_wwl(&n);
					break;
				default:printf("\n��ѡ��1-4��");
					break;
				}
			}
			return 0;
		}
