#include <gtk/gtk.h>
int main (int argc,char *argv[])
{
GtkWidget *window; /*ָ�򴰿ڵ�ָ��*/
GtkWidget *hpaned; /*ָ��ť��ָ��*/
GtkWidget *entry; /*ָ���ı����ָ��*/
GtkWidget *label; /*ָ���ǩ��ָ��*/
char title[]="Hpaned example";
gtk_init(&argc,&argv);
window=gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_title (GTK_WINDOW (window), title);
gtk_widget_set_usize (window, 220, 100);
hpaned = gtk_hpaned_new();
entry = gtk_entry_new();
label = gtk_label_new ("This is a label.");
gtk_paned_pack1 (GTK_PANED (hpaned), entry, TRUE, TRUE);
gtk_paned_pack2 (GTK_PANED (hpaned), label, TRUE, TRUE);
gtk_container_add (GTK_CONTAINER (window), hpaned);
gtk_paned_set_position (GTK_PANED (hpaned), 40);
gtk_widget_show_all (window); /*��ʾ����*/
gtk_main();
return 0;
}
