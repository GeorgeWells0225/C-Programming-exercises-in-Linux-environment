#include <gtk/gtk.h>
#include <stdlib.h>
int main (int argc,char *argv[])
{
   GtkWidget *window;
   GtkWidget *entry;  /*����һ��ָ���ı����ָ��*/
   char title[]="Add a entry to the Window";
   char text[50];
   gtk_init(&argc,&argv);
   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title (GTK_WINDOW (window), title);
   gtk_widget_set_usize (window, 250, 100);
   entry = gtk_entry_new_with_max_length (20);
     /*�½�һ�����������Ƶ��ı����ı�������������20���ַ�*/
   gtk_container_add (GTK_CONTAINER (window), entry); /*���ı�����ӵ�������*/
   strcpy(text, gtk_entry_get_text (GTK_ENTRY (entry)));
     /*��ȡ�ı�����ı����ݣ������临�Ƶ�text�ַ���������*/
   strcat(text, "I like Linux C programs!");
     /*���µ��ַ������ӵ�text�ַ�������ĺ���*/
   gtk_entry_set_text (GTK_ENTRY (entry), text);  /*�����ı�����ı�����*/
   gtk_widget_show (window);    /*��ʾ����*/
   gtk_widget_show (entry);   /*��ʾ�ı���*/
   gtk_main();
   return 0;
}
