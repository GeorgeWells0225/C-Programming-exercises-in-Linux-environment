#include <gtk/gtk.h>
#include <stdlib.h>
int main (int argc,char *argv[])
{
   GtkWidget *window;
   GtkWidget *label;
   char title[]="Add a label to the Window";
   char text[]="Hello, I like Linux C programs!";
   char text2[50];
   gtk_init(&argc,&argv);
   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title (GTK_WINDOW (window), title);
   gtk_widget_set_usize (window, 220, 100);
   label = gtk_label_new (text);
   gtk_container_add (GTK_CONTAINER (window), label);
   strcpy(text2, gtk_label_get_text(GTK_LABEL(label)));
   strcat(text2, "\nThis is the append string.");
   gtk_label_set_text (GTK_LABEL (label), text2);
   gtk_widget_show (window);
   gtk_widget_show (label);
   gtk_main();
   return 0;
}
