#include<gtk/gtk.h>
int main(int argc,char **argv)
{       
   GtkWidget *window;
   GtkWidget *vbox;
   GtkObject *adjustment;
   GtkWidget *bar;
   GtkWidget *spinbutton;
   GList *glist;
   GtkWidget *combo;
   char title[]="Bar, Spinbutton and Combo";
   gtk_init(&argc,&argv);
   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title (GTK_WINDOW (window), title);
   gtk_container_border_width(GTK_CONTAINER(window),40);/*���ô��ڱ߿�Ŀ��Ϊ40*/
   vbox = gtk_vbox_new(FALSE,0);/*����һ����ֱ��*/
   gtk_container_add(GTK_CONTAINER(window),vbox);
   /*�����Ǵ���������*/
   adjustment = gtk_adjustment_new(70.0,0.0,100.0,1.0,0.0,0.0);
   bar = gtk_progress_bar_new_with_adjustment(GTK_ADJUSTMENT(adjustment));
   gtk_progress_bar_set_bar_style(GTK_PROGRESS_BAR(bar),
   GTK_PROGRESS_CONTINUOUS);
   gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(bar),
   GTK_PROGRESS_LEFT_TO_RIGHT); 
   gtk_box_pack_start(GTK_BOX(vbox),bar,TRUE,TRUE,15);/*����������ӵ���ֱ��*/
   /*�����Ǵ���΢����ť*/
   adjustment = gtk_adjustment_new(80.0,0.0,100.0,1.0,0.0,0.0);
   spinbutton = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment),1.0,1);
   gtk_box_pack_start(GTK_BOX(vbox),spinbutton,TRUE,TRUE,15);/*��΢����ť��ӵ���ֱ��*/
   /*�����Ǵ�����Ͽ�*/
   glist = NULL;
   glist = g_list_append(glist,"banana");/*�б���й�ѡ����ַ���*/
   glist = g_list_append(glist,"apple"); 
   glist = g_list_append(glist,"orange");
   glist = g_list_append(glist,"pear");
   combo = gtk_combo_new();
   gtk_combo_set_popdown_strings(GTK_COMBO(combo),glist);
   gtk_box_pack_start(GTK_BOX(vbox),combo,TRUE,TRUE,15);/*����Ͽ���ӵ���ֱ��*/
   gtk_widget_show_all (window);/*��ʾ�����е�����Ԫ��*/
   gtk_main();
   return 0;
} 
