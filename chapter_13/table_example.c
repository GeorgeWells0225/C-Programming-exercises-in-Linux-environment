#include <gtk/gtk.h>
int main (int argc,char *argv[])
{
GtkWidget *window; /*ָ�򴰿ڵ�ָ��*/
GtkWidget *table; /*ָ�����ָ��*/
GtkWidget *entry; /*ָ���ı����ָ��*/
GtkWidget *button; /*ָ��ť��ָ��*/
GtkWidget *label1; /*ָ���ǩ1��ָ��*/
GtkWidget *label2; /*ָ���ǩ2��ָ��*/
char title[]="Table example";
gtk_init(&argc,&argv);
window=gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_title (GTK_WINDOW (window), title);
gtk_widget_set_usize (window, 250, 100);
table=gtk_table_new (2,2,FALSE);
/*����һ��2��2�еı�񣬵�Ԫ���С����ݵ�Ԫ���е�Ԫ����С�Զ�����*/
button=gtk_button_new_with_label("Button");/*�½���ť*/
entry =gtk_entry_new ();/*�½��ı���*/
label1=gtk_label_new ("This is label 1");/*�½���ǩ1*/
label2=gtk_label_new ("This is label 2");/*�½���ǩ2*/
gtk_container_add (GTK_CONTAINER (window), table);
/*�����ǽ��ĸ�Ԫ���ֱ���ӵ������Ӧ��λ����*/
gtk_table_attach (GTK_TABLE(table), button, 0, 1, 0, 1,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
gtk_table_attach (GTK_TABLE(table), label1, 1, 2, 0, 1,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
gtk_table_attach (GTK_TABLE(table), entry, 0, 1, 1, 2,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
gtk_table_attach (GTK_TABLE(table), label2, 1, 2, 1, 2,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
gtk_widget_show_all (window);   /*��ʾ�����е�����Ԫ��*/
gtk_main();
return 0;
}
