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
   gtk_container_border_width(GTK_CONTAINER(window),40);/*设置窗口边框的宽度为40*/
   vbox = gtk_vbox_new(FALSE,0);/*创建一个垂直框*/
   gtk_container_add(GTK_CONTAINER(window),vbox);
   /*下面是创建进度条*/
   adjustment = gtk_adjustment_new(70.0,0.0,100.0,1.0,0.0,0.0);
   bar = gtk_progress_bar_new_with_adjustment(GTK_ADJUSTMENT(adjustment));
   gtk_progress_bar_set_bar_style(GTK_PROGRESS_BAR(bar),
   GTK_PROGRESS_CONTINUOUS);
   gtk_progress_bar_set_orientation(GTK_PROGRESS_BAR(bar),
   GTK_PROGRESS_LEFT_TO_RIGHT); 
   gtk_box_pack_start(GTK_BOX(vbox),bar,TRUE,TRUE,15);/*将进度条添加到垂直框*/
   /*下面是创建微调按钮*/
   adjustment = gtk_adjustment_new(80.0,0.0,100.0,1.0,0.0,0.0);
   spinbutton = gtk_spin_button_new(GTK_ADJUSTMENT(adjustment),1.0,1);
   gtk_box_pack_start(GTK_BOX(vbox),spinbutton,TRUE,TRUE,15);/*将微调按钮添加到垂直框*/
   /*下面是创建组合框*/
   glist = NULL;
   glist = g_list_append(glist,"banana");/*列表框中供选择的字符串*/
   glist = g_list_append(glist,"apple"); 
   glist = g_list_append(glist,"orange");
   glist = g_list_append(glist,"pear");
   combo = gtk_combo_new();
   gtk_combo_set_popdown_strings(GTK_COMBO(combo),glist);
   gtk_box_pack_start(GTK_BOX(vbox),combo,TRUE,TRUE,15);/*将组合框添加到垂直框*/
   gtk_widget_show_all (window);/*显示窗口中的所有元件*/
   gtk_main();
   return 0;
} 
