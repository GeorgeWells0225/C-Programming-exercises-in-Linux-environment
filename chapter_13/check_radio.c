#include<gtk/gtk.h>
int main (int argc,char *argv[])
{
   GtkWidget *window;
   GtkWidget *box;
   GSList *group;
   GtkWidget *check,*radio;
   char title[]="Check and Radio";
   gtk_init (&argc,&argv);
   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title (GTK_WINDOW (window), title);
   gtk_container_border_width (GTK_CONTAINER(window),50); 
   box = gtk_vbox_new (FALSE,0);  /*创建一个垂直框容器，并将该容器加入到主窗口中*/
   gtk_container_add(GTK_CONTAINER(window),box); 

   /*以下生成两个check按钮，将它们加入到垂直框中*/
   check = gtk_check_button_new_with_label ("coffee");
   gtk_box_pack_start(GTK_BOX(box),check,TRUE,TRUE,0);
   check = gtk_check_button_new_with_label ("tea");
   gtk_box_pack_start (GTK_BOX(box),check,TRUE,TRUE,0);

   /*以下生成3个radio按钮，将它们加入到垂直框。注意：生成第一个radio按钮时group参数为NULL，而后每次在该组中创建一个radio按钮都要使用gtk_radio_button_group 函数获取新的group值 */
   radio = gtk_radio_button_new_with_label (NULL,"Apple");
   gtk_box_pack_start (GTK_BOX(box),radio,TRUE,TRUE,0);
   group = gtk_radio_button_group (GTK_RADIO_BUTTON(radio));
   radio = gtk_radio_button_new_with_label (group,"Banana");
   gtk_box_pack_start (GTK_BOX(box),radio,TRUE,TRUE,0);
   group = gtk_radio_button_group (GTK_RADIO_BUTTON(radio));
   radio = gtk_radio_button_new_with_label (group,"Orange"); 
   gtk_box_pack_start (GTK_BOX(box),radio,TRUE,TRUE,0);
   gtk_widget_show_all (window);
   gtk_main();
   return 0;
}

