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
   box = gtk_vbox_new (FALSE,0);  /*����һ����ֱ���������������������뵽��������*/
   gtk_container_add(GTK_CONTAINER(window),box); 

   /*������������check��ť�������Ǽ��뵽��ֱ����*/
   check = gtk_check_button_new_with_label ("coffee");
   gtk_box_pack_start(GTK_BOX(box),check,TRUE,TRUE,0);
   check = gtk_check_button_new_with_label ("tea");
   gtk_box_pack_start (GTK_BOX(box),check,TRUE,TRUE,0);

   /*��������3��radio��ť�������Ǽ��뵽��ֱ��ע�⣺���ɵ�һ��radio��ťʱgroup����ΪNULL������ÿ���ڸ����д���һ��radio��ť��Ҫʹ��gtk_radio_button_group ������ȡ�µ�groupֵ */
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

