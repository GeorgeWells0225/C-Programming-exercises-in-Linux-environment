#include <gtk/gtk.h>
int main (int argc,char *argv[])
{
GtkWidget *window; /*指向窗口的指针*/
GtkWidget *table; /*指向表格的指针*/
GtkWidget *table2; /*指向表格2的指针*/
GtkWidget *entry; /*指向文本框的指针*/
GtkWidget *button; /*指向按钮的指针*/
GtkWidget *button2; /*指向按钮的指针*/
GtkWidget *button3; /*指向按钮的指针*/
GtkWidget *button4; /*指向按钮的指针*/
GtkWidget *label; /*指向标签1的指针*/
char title[]="Consolidated and Nested table";
gtk_init(&argc,&argv);
window=gtk_window_new (GTK_WINDOW_TOPLEVEL);
gtk_window_set_title (GTK_WINDOW (window), title);
gtk_widget_set_usize (window, 350, 100);
table=gtk_table_new(3,2,FALSE);
/*定义一个3行2列的表格，单元格大小会根据单元格中的元件大小自动调整*/
table2=gtk_table_new(1,2,FALSE);


button=gtk_button_new_with_label("Button");
button2=gtk_button_new_with_label("Button2");
button3=gtk_button_new_with_label("Button3");
button4=gtk_button_new_with_label("Button4");
entry =gtk_entry_new ();
label=gtk_label_new ("This is a label");

gtk_container_add (GTK_CONTAINER (window), table);

gtk_table_attach (GTK_TABLE(table), button, 0, 1, 0, 1,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);

gtk_table_attach (GTK_TABLE(table), label, 1, 2, 0, 2,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);

gtk_table_attach (GTK_TABLE(table), entry, 0, 1, 1, 2,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
gtk_table_attach (GTK_TABLE(table), button2, 0, 1, 2, 3,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);

gtk_table_attach (GTK_TABLE(table), table2, 1, 2, 2, 3,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);

gtk_table_attach (GTK_TABLE(table2), button3, 0, 1, 0, 1,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);
gtk_table_attach (GTK_TABLE(table2), button4, 1, 2, 0, 1,
                 (GtkAttachOptions)(GTK_FILL), (GtkAttachOptions)(0), 0, 0);

gtk_widget_show_all (window); /*显示窗口*/
gtk_main();
return 0;
}
