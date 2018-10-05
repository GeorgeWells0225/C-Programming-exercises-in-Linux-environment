#include <gtk/gtk.h>
#include <stdlib.h>
int main (int argc,char *argv[])
{
   GtkWidget *window;
   GtkWidget *entry;  /*定义一个指向文本框的指针*/
   char title[]="Add a entry to the Window";
   char text[50];
   gtk_init(&argc,&argv);
   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title (GTK_WINDOW (window), title);
   gtk_widget_set_usize (window, 250, 100);
   entry = gtk_entry_new_with_max_length (20);
     /*新建一个有字数限制的文本框，文本框中最多可输入20个字符*/
   gtk_container_add (GTK_CONTAINER (window), entry); /*将文本框添加到窗口中*/
   strcpy(text, gtk_entry_get_text (GTK_ENTRY (entry)));
     /*获取文本框的文本内容，并将其复制到text字符串数组中*/
   strcat(text, "I like Linux C programs!");
     /*将新的字符串连接到text字符串数组的后面*/
   gtk_entry_set_text (GTK_ENTRY (entry), text);  /*设置文本框的文本内容*/
   gtk_widget_show (window);    /*显示窗口*/
   gtk_widget_show (entry);   /*显示文本框*/
   gtk_main();
   return 0;
}
