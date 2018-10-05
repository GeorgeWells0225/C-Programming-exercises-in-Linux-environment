#include <gtk/gtk.h>
#include <stdlib.h>

int i;
GtkWidget *window; /*指向窗口的指针*/
GtkWidget *button; /*指向按钮的指针*/

void on_clicked(GtkWidget *widget, gpointer data)
{
char a[20],b[20];
i++;
gcvt((float)i,3,a);
strcat(a, " times");
strcpy(b,"you have clicked ");
strcat(b,a);
gtk_window_set_title (GTK_WINDOW (window), b);
}

int main (int argc,char *argv[])
{
char title[]="button";
gtk_init(&argc,&argv);
window=gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_title (GTK_WINDOW (window), title);
gtk_widget_set_usize (window, 220, 100);
//gtk_container_border_width(GTK_CONTAINER(window),80);
//gtk_widget_set_default_size (window, 350, 150);
button = gtk_button_new_with_label("Button"); /*新建一个带有标签的按钮*/
g_signal_connect (G_OBJECT(button), "clicked", G_CALLBACK(on_clicked), window);
gtk_container_add (GTK_CONTAINER (window), button);
gtk_widget_show_all (window); /*显示窗口*/
gtk_main();
return 0;
}
