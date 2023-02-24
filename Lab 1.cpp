#include<stdio.h>

	struct Student
	{
		long long num;//学号
		char name[20];//姓名
		char sex[10];//性别
		int English;//英语
		int PC;//计算机
		int math;//高数
		int sum;//总分
		double avg;//平均分
	}stu[100];

	void Show_Header(int f) {
		if (f) {
			printf("\n序号\t学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");//输出带序号的表头
		}
		else {
			printf("\n学号\t姓名\t性别\t英语\t计算机\t高数\t总分\t平均分\n");//输出不带序号的表头
		}
	}

	void Main_Menu() {
		printf("\n\t\t\t\t学生信息管理系统\n");
		printf("\t1.显示学生信息\n");
		printf("\t2.查找学生信息\n");
		printf("\t3.修改学生信息\n");
		printf("\t4.添加学生信息\n");
		printf("\t请选择（1-4）：");
	}//输出主菜单

	void Update_Menu() {
		printf("\n\t1.姓名\n");
		printf("\t2.性别\n");
		printf("\t3.英语\n");
		printf("\t4.计算机\n");
		printf("\t5.高数\n");
	}//输出修改列表

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
	}//录入学生的信息

	void OutputStu(int n) {
		printf("%lld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2lf\n", stu[n].num, stu[n].name, stu[n].sex, stu[n].English, stu[n].PC, stu[n].math, stu[n].sum, stu[n].avg);
	}//输出指定学生的信息

	void OutputStu_wwl(int n) {
		Show_Header(1);
		for (int i = 0;i < n;i++) {
			printf("%d\t%lld\t%s\t%s\t%d\t%d\t%d\t%d\t%.2lf\n", i+1,stu[i].num, stu[i].name, stu[i].sex, stu[i].English, stu[i].PC, stu[i].math, stu[i].sum, stu[i].avg);
		}
		printf("\n");
	}//输出所有学生的信息

	int SearchStu_wwl(long long x, int n){
		int f = 1;
		for (int i = 0;i < n;i++) {
			if (x == stu[i].num) {
				printf("\n查找成功\n");
				f = 0;
				Show_Header(0);
				OutputStu(i);
				return i;
			}
		}
		if (f) {
			printf("\n该生的信息不存在");
		}
		return -1;
}//查找学生信息，通过学号查找学生信息

	void UpdataStu_wwl(int i) {
		if (i == -1) printf("\n该生的信息不存在，修改失败");
		else {
			int a = 0;
			int f = 1;
			while (f) {
				Update_Menu();
				printf("\n请选择要修改的信息（1-5）：");
				scanf_s("%d", &a);
				switch (a)
				{
				case 1:printf("请输入要修改记录的信息：");
					scanf_s("%s", stu[i].name, 20);
					f = 0;
					break;
				case 2:printf("请输入要修改记录的信息：");
					scanf_s("%s", stu[i].sex, 10);
					f = 0;
					break;
				case 3:printf("请输入要修改记录的信息：");
					scanf_s("%d", &stu[i].English);
					stu[i].sum = stu[i].English + stu[i].PC + stu[i].math;
					stu[i].avg = (double)stu[i].sum / 3.0;
					f = 0;
					break;
				case 4:printf("请输入要修改记录的信息：");
					scanf_s("%d", &stu[i].PC);
					stu[i].sum = stu[i].English + stu[i].PC + stu[i].math;
					stu[i].avg = (double)stu[i].sum / 3.0;
					f = 0;
					break;
				case 5:printf("请输入要修改记录的信息：");
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
	}//通过学号，修改学生指定信息

	void AppendStu_wwl(int* p) {
		printf("请输入学生信息：");
		InputStu_wwl(*p);
		++* p;
		printf("更新成功\n");
	}//添加学生信息

		int main(){
			int n, N;//n为学生总数，N为功能选择
			long long x=0;
			printf("请输入学生记录个数n=");
			scanf_s("%d", &n);
			printf("请输入学生信息：");
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
				case 2:printf("请输入待查找的学号：");
					long long x;
					scanf_s("%lld", &x);
					if (SearchStu_wwl(x, n) == -1) printf(",查找失败");
					break;
				case 3:printf("请输入要修改记录的学号：");
					scanf_s("%lld", &x);
					UpdataStu_wwl(SearchStu_wwl(x, n));
					break;
				case 4:AppendStu_wwl(&n);
					break;
				default:printf("\n请选择（1-4）");
					break;
				}
			}
			return 0;
		}
