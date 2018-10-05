#include <gtk/gtk.h>
#include <stdlib.h>
int main (int argc,char *argv[])
{
   GtkWidget *window;
   GtkWidget *button;
   char title[]="Add a button to the Window";
   char text[50];
   gtk_init(&argc,&argv);
   window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title (GTK_WINDOW (window), title);
   gtk_widget_set_usize (window, 250, 100);
   button = gtk_button_new_with_label("NEW BUTTON");
   gtk_container_add (GTK_CONTAINER (window), button);
   strcpy(text, gtk_button_get_label(GTK_BUTTON(button)));
       /*获取标签的文本，并将其复制到text2字符串数组中*/
   strcat(text, "\nThis is the append string.");
      /*将新的字符串连接到text2字符串数组的后面*/
   gtk_button_set_label (GTK_BUTTON(button), text);   /*设置标签的文本*/
   gtk_widget_show (window);
   gtk_widget_show (button);
   gtk_main();
   return 0;
}
