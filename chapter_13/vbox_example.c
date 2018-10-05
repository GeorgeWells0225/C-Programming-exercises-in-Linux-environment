#include <gtk/gtk.h>
int main (int argc,char *argv[])
{
GtkWidget *window; /*指向窗口的指针*/
GtkWidget *vbox; /*指向表格的指针*/
GtkWidget *entry; /*指向文本框的指针*/
GtkWidget *button; /*指向按钮的指针*/
GtkWidget *label; /*指向标签的指针*/
char title[]="Vbox example";
gtk_init(&argc,&argv);
window=gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_title (GTK_WINDOW (window), title);
gtk_widget_set_usize (window, 250, 150);
vbox = gtk_vbox_new (FALSE, 0);
entry =gtk_entry_new();
label=gtk_label_new ("This is a label.");
button=gtk_button_new_with_label("OK");
gtk_container_add (GTK_CONTAINER (window), vbox);
gtk_box_pack_start (GTK_BOX (vbox), label, TRUE, FALSE, 0);
gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, FALSE, 0);
gtk_box_pack_start (GTK_BOX (vbox), entry, TRUE, FALSE, 0);
gtk_widget_show_all (window); /*显示窗口*/
gtk_main();
return 0;
}
